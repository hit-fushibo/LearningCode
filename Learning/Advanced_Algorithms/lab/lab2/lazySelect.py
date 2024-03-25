from sort import merge_sort
import numpy as np
import math

def randomSelect(data):
    return np.random.choice(data,int(pow(len(data),0.75)),replace=True).tolist()

def rank(list,element):
    cnt=0
    for i in list:
        if i <element:
            cnt+=1
    return cnt+1

def lazy_Select(datasets:dict,k:int):
    result={}
    for key in datasets.keys():
        data=datasets[key]
        n=len(data)
        
        
        while 1:
            
            
            sampled_data=randomSelect(data)
            
            sampled_data=merge_sort(sampled_data)
            
            x = int(k * pow(n, -0.25))
            l = max(0, int(x - math.sqrt(n)))
            r = min(int(pow(n, 0.75)), int(x + math.sqrt(n)))
            
            L = sampled_data[max(1, l - 1)]
            H = sampled_data[r - 1]
            LP = rank(data, L)
            HP = rank(data, H)
            
            p=[]
            for i in data:
                if L<=i<=H:
                    p.append(i)
            
            if LP<=k<=HP and len(p)<=4*pow(n,0.75)+1:
                p=merge_sort(p)
                result[key]=p[k-LP]
                break
    return result

            