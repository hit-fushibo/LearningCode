import numpy as np
import matplotlib.pyplot as plt
import time
file_path='LearningCode/Learning/Advanced_Algorithms/lab/lab1/data/E1_AOL-out.txt'
sim_threshold=0.8
hash_func_num=10


def load_data(file_path:str)->dict:
    '''
    加载数据集的代码
    
    返回一个字典{int:set}
        key为每个集合的index
        键值为每个集合元素构成的set
    
    '''
    data_sets=dict()
    with open(file_path,'r') as f:
        lines=f.readlines()
        for line in lines:
            line=line.replace('\n','')
            line=line.split('\t')
            index=int(line[0])
            data=int(line[1])
            if index in data_sets.keys():
                data_sets[index].add(data)
            else:
                data_sets[index]={data}
    
    
    return data_sets

def naive(datasets:dict,similarity_threshold:float=sim_threshold)->list:
    set_keys=list(datasets.keys())
    result=[]
    for i in range(len(set_keys)):
        for j in range(i+1,len(set_keys)):
            set1=datasets[set_keys[i]]
            set2=datasets[set_keys[j]]
            
            sim=len(set1.intersection(set2))/len(set1.union(set2))
            if sim>=similarity_threshold:
                result.append([i,j])
    return result

def minHash(datasets:dict,hash_num:int=hash_func_num,similarity_threshold:float=sim_threshold)->tuple:
    t1=time.time()
    result=[]
    set_keys=list(datasets.keys())
    minHash_matrix=np.zeros((hash_num,len(set_keys)))
    data=set()
    for i in set_keys:
        data=data.union(datasets[i])
    data=list(data)
    for i in range(hash_num):
        hashed_data=np.random.permutation(data)
        for j in range(len(set_keys)):
            for k in range(len(hashed_data)):
                if hashed_data[k] in datasets[set_keys[j]]:
                    minHash_matrix[i,j]=k
                    break
            
    for i in range(len(set_keys)):
        for j in range(i+1,len(set_keys)):
            equ_num=0
            for k in range(hash_num):
                if minHash_matrix[k,i]==minHash_matrix[k,j]:
                    equ_num+=1
            sim=equ_num/hash_num
            if sim>=similarity_threshold:
                result.append([i,j])
    t2=time.time()
    return result,t2-t1

def result_Comparison(result1:list,result2:list)->float:
    set1=set(tuple(x) for x in result1)
    set2=set(tuple(x) for x in result2)
    sim=len(set1.intersection(set2))/len(set1.union(set2))
    return sim

def main():
    datasets=load_data(file_path)
    
    #采样，只留下大概500个集合
    sampled_dataset=dict()
    p=500/len(datasets.keys())
    for key in datasets.keys():
        if np.random.random()<p:
            sampled_dataset[key]=datasets[key]
            

    naive_result=naive(sampled_dataset,sim_threshold)
    
    result_sim=[]
    time_cost=[]
    hash_func_min=3
    hash_func_max=20
    for i in range(hash_func_min,hash_func_max+1): #hash函数个数3-10
        minHash_result,minHash_time=minHash(sampled_dataset,i,sim_threshold)
        sim=result_Comparison(naive_result,minHash_result)
        result_sim.append(sim)
        time_cost.append(minHash_time)
    hashfunc=np.arange(hash_func_min,hash_func_max+1,1)
    plt.plot(hashfunc,result_sim,'r-',label='result sim')
    plt.plot(hashfunc,time_cost,'b-',label='time')
    plt.legend()
    plt.show()
        
    
if __name__=='__main__':
    main()
    
    
            
    