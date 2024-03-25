import numpy as np
import matplotlib.pyplot as plt
import time
import os
# 定义文件路径和相似度阈值等参数
file_paths = [os.path.join('./data',f) for f in os.listdir('./data')]
sim_threshold = 0.8
hash_func_default_num = 10
hash_func_min = 10
hash_func_max = 100

def load_data(file_path: str) -> dict:
    '''
    加载数据集的函数
    输入：文件路径
    输出：一个字典{int:set}，key为每个集合的index，键值为每个集合元素构成的set
    '''
    data_sets = dict()
    with open(file_path, 'r') as f:
        lines = f.readlines()
        for line in lines:
            line = line.replace('\n', '')
            line = line.split('\t')
            index = int(line[0])
            data = int(line[1])
            if index in data_sets.keys():
                data_sets[index].add(data)
            else:
                data_sets[index] = {data}
    return data_sets

def naive(datasets: dict, similarity_threshold: float = sim_threshold) -> list:
    '''
    Naive算法的函数
    输入：数据集字典，相似度阈值
    输出：满足相似度阈值的集合对列表
    '''
    set_keys = list(datasets.keys())
    result = []
    for i in range(len(set_keys)):
        for j in range(i+1, len(set_keys)):
            set1 = datasets[set_keys[i]]
            set2 = datasets[set_keys[j]]
            sim = len(set1.intersection(set2)) / len(set1.union(set2))
            if sim >= similarity_threshold:
                result.append([i, j])
    return result

def minHash(datasets: dict, hash_num: int = hash_func_default_num, similarity_threshold: float = sim_threshold) -> tuple:
    '''
    MinHash算法的函数
    输入：数据集字典，哈希函数个数，相似度阈值
    输出：满足相似度阈值的集合对列表和计算时间
    '''
    t1 = time.time()
    result = []
    set_keys = list(datasets.keys())
    minHash_matrix = np.zeros((hash_num, len(set_keys)))
    data = set()
    for i in set_keys:
        data = data.union(datasets[i])
    data = list(data)
    for i in range(hash_num):
        hashed_data = np.random.permutation(data)
        for j in range(len(set_keys)):
            for k in range(len(hashed_data)):
                if hashed_data[k] in datasets[set_keys[j]]:
                    minHash_matrix[i, j] = k
                    break
    for i in range(len(set_keys)):
        for j in range(i+1, len(set_keys)):
            equ_num = 0
            for k in range(hash_num):
                if minHash_matrix[k, i] == minHash_matrix[k, j]:
                    equ_num += 1
            sim = equ_num / hash_num
            if sim >= similarity_threshold:
                result.append([i, j])
    t2 = time.time()
    return result, t2 - t1

def result_Comparison(result1: list, result2: list) -> float:
    '''
    比较两个结果的相似度的函数
    输入：两个结果列表
    输出：相似度
    '''
    set1 = set(tuple(x) for x in result1)
    set2 = set(tuple(x) for x in result2)
    if len(set1.union(set2))!=0:
        sim = len(set1.intersection(set2)) / len(set1.union(set2))
    else:
        sim=int(len(set1.intersection(set2))==0)
    return sim

def main():
    ii=0
    save_name=['AOL','Booking','korsarak']
    for file_path in file_paths:
        print(ii)
        datasets = load_data(file_path)
        
        # for test
        # sampled_dataset = dict()
        # p = 50 / len(datasets.keys())
        # for key in datasets.keys():
        #     if np.random.random() < p:
        #         sampled_dataset[key] = datasets[key]
                
        sampled_dataset=datasets
        
        naive_result = naive(sampled_dataset, sim_threshold)
        
        result_sim = []
        time_cost = []
        
        for i in range(hash_func_min, hash_func_max + 1):  
            minHash_result, minHash_time = minHash(sampled_dataset, i, sim_threshold)
            sim = result_Comparison(naive_result, minHash_result)
            result_sim.append(sim)
            time_cost.append(minHash_time)
        hashfunc = np.arange(hash_func_min, hash_func_max + 1, 1)
        fig,ax=plt.subplots(1,2)
        fig.subplots_adjust(wspace=0.5)
        ax[0].plot(hashfunc, result_sim, 'r-', label='result sim')
        ax[0].set_title('result sim')
        ax[0].set_xlabel('Hash Function')
        ax[0].set_ylabel('Result Similarity')
        
        ax[1].plot(hashfunc, time_cost, 'b-', label='time')
        ax[1].set_title('run time')
        ax[1].set_xlabel('Hash Function')
        ax[1].set_ylabel('Time Cost')
        # plt.legend()
        plt.savefig(os.path.join('./result',save_name[ii]+'.svg'))
        ii+=1

if __name__ == '__main__':
    main()
