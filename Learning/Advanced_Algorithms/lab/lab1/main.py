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

def result_Visualization(result:list,set_names:list):
    sim_matrix=np.zeros((len(set_names),len(set_names)))
    for pair in result:
        sim_matrix[pair[0],pair[1]]=1
        sim_matrix[pair[1],pair[0]]=1
    
    plt.figure()
    plt.imshow(sim_matrix, cmap='Blues', interpolation='none')
    plt.colorbar()
    plt.xticks(np.arange(len(set_names)), set_names, rotation=45)
    plt.yticks(np.arange(len(set_names)), set_names)
    plt.show()
    return

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
    print(len(sampled_dataset))
    

    naive_result=naive(sampled_dataset,sim_threshold)
    result_Visualization(naive_result,list(sampled_dataset.keys()))
    # print(naive_result)
    # return
    # print(1)
    
    # tmp=[]
    # for i in range(50,100): #hash函数个数3-10
    #     # print(i)
    #     minHash_result,minHash_time=minHash(sampled_dataset,i,sim_threshold)
    #     print(len(minHash_result))
    #     # break
    #     sim=result_Comparison(naive_result,minHash_result)
    #     # print('hash func num:%d. minHash time:%f. result sim:%f'%(i,minHash_time,sim))
    #     tmp.append(sim)
    # hashfunc=np.arange(3,100,1)
    # plt.plot(hashfunc,tmp,'r-')
    # plt.show()
        
    
if __name__=='__main__':
    main()
    
    
            
    