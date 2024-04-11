import numpy as np
import time
import matplotlib.pyplot as plt
from pyparsing import nums

epsilon=1e-10

class Graph:
    def __init__(self,n:int) -> None:
        self.n=n
        self.graph=np.zeros((n,n))
        for i in range(n):
            for j in range(i,n):
                if i==j:
                    self.graph[i,j]=np.inf
                else:
                    self.graph[i,j]=np.random.uniform(0+epsilon,1)
                    self.graph[j,i]=self.graph[i,j]
    
    def kruskal(self) -> float:
        
        weight=0
        result=[]
        for _ in range(self.n):
            min_weight=np.inf
            min_index=''
            for i in range(self.n):
                for j in range(i,self.n):
                    if self.graph[i,j]<min_weight:
                        temp_index='%d - %d'%(i,j)
                        if not temp_index in result:
                            min_index=temp_index
                            min_weight=self.graph[i,j]
            result.append(min_index)
            weight+=min_weight
        return weight

def generate_graph(n:int) -> Graph:
    return Graph(n)

def cal_MST_weight(n:int,epoch:int) -> float:
    weight_sum=0
    for _ in range(epoch):
        G=generate_graph(n)
        weight_sum+=G.kruskal()
    del G
    weight_sum/=epoch
    return weight_sum

def main():
    epoch=1000
    n_nums=[16,32,64,128,256,512,1024]
    mean_weight_list=[]
    time_lsit=[]
    for n in n_nums:
        print(n)
        t1=time.time()
        mean_MST_weight=cal_MST_weight(n,epoch)
        t2=time.time()
        mean_weight_list.append(mean_MST_weight)
        time_lsit.append((t2-t1)/epoch)
    fig,ax=plt.subplots(1,2,figsize=(16,8))
    plt.subplots_adjust(wspace=0.5)
    ax[0].plot(n_nums,mean_weight_list,'r-')
    ax[1].plot(n_nums,time_lsit,'r-')
    
    ax[0].set_xlabel('Number of vertices')
    ax[0].set_ylabel('Mean MST weight')
    ax[0].set_xticks(n_nums)
    
    ax[1].set_xlabel('Number of vertices')
    ax[1].set_ylabel('alg run time')
    ax[1].set_xticks(n_nums)
    plt.savefig('LearningCode/Learning/Advanced_Algorithms/lab/lab3/result.png')
    plt.show()


if __name__=='__main__':
    main()

        
                            