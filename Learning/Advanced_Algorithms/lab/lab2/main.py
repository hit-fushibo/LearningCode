'''
TODO:
1. lazy select 不同参数下循环轮次和运行时间比较
2. 不同算法在不同规模数据上的运行时间比较

'''


import os
from torch import le
from dataloder import datasets
from sort_select import sort_select
from linear import liner_select
from lazySelect import lazy_Select

import numpy as np
import time
import matplotlib.pyplot as plt

epoch = 10

save_path = 'LearningCode/Learning/Advanced_Algorithms/lab/lab2/result'


def alg_test(sigma: float, datasize: int) -> np.ndarray:
    data = datasets(datasize*2+1).load()

    sort_select_time = []
    liner_select_time = []
    lazy_select_time = []
    lazy_select_epoch = []
    for i in range(epoch):
        print('\t epoch ',i)
        k = datasize

        # sort select
        t1 = time.time()
        correct_result = sort_select(data, k)
        t2 = time.time()
        sort_select_time.append(t2-t1)
        print('\t\t sort done')

        # liner select
        t1 = time.time()
        liner_result = liner_select(data, k)
        t2 = time.time()
        liner_select_time.append(t2-t1)
        print('\t\t liner done')

        # lazy select
        t1 = time.time()
        lazy_result = lazy_Select(data, k, sigma)
        t2 = time.time()
        lazy_select_time.append(t2-t1)
        print('\t\t lazy done')
        l_e = 0
        for key in lazy_result.keys():
            l_e += lazy_result[key][1]
        l_e /= 3
        lazy_select_epoch.append(l_e)
    return np.array([sort_select_time, liner_select_time, lazy_select_time, lazy_select_epoch],dtype=np.float32)

def alg_fig():
    sigmas = [float(i)/100 for i in range(60, 95, 5)]
    # simgas=[0.75]
    datasizes = [i for i in range(5000, 55000, 5000)]
    for sigma in sigmas:
        print('sigma:',sigma)
        sort_time=[]
        liner_time=[]
        lazy_time=[]
        lazy_epoch=[]
        for data_size in datasizes:
            print('\t data size:',data_size*2)
            result = alg_test(sigma, data_size)
            print('\t done')
            sort_time.append(result[0].mean())
            liner_time.append(result[1].mean())
            lazy_time.append(result[2].mean())
            lazy_epoch.append(result[3].mean())
        fig,ax=plt.subplots()
        ax.plot(datasizes,sort_time,'r-',label='sort select time')
        ax.plot(datasizes,liner_time,'g-',label='liner select time')
        ax.plot(datasizes,lazy_time,'b-',label='lazy select time')
        ax.plot(datasizes,lazy_epoch,'o-',label='lazy select epoch')
        plt.legend()

        save_name='result_%.2f.png'%(sigma)
        plt.savefig(os.path.join(save_path,save_name))


def sigma_fig():
    sigmas = [float(i)/100 for i in range(60, 95, 5)]
    datasizes = [i for i in range(5000, 55000, 5000)]
    color=['r','g','b','pink','y','c','gray']
    fig,ax=plt.subplots()
    i=0
    for sigma in sigmas:
        result=[]
        for datasize in datasizes:
            data = datasets(datasize*2+1).load()
            k = datasize
            t1 = time.time()
            lazy_result = lazy_Select(data, k, sigma)
            t2 = time.time()
            result.append(t2-t1)
        ax.plot(datasizes,result,color[i],label='sigma %.2f'%sigma)
        i+=1
    plt.legend()
    save_name='result_sigma.png'
    plt.savefig(os.path.join(save_path,save_name))
            
if __name__ == '__main__':
    # alg_fig()
    sigma_fig()
        