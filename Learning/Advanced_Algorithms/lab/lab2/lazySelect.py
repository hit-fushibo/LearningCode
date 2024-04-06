from sort import merge_sort
import numpy as np
import math

# sigma=0.75

def randomSelect(data,sigma):
    return np.random.choice(data, int(pow(len(data), sigma)), replace=True).tolist()


def rank(l: list, element) -> int:
    cnt = 0
    for i in l:
        if i < element:
            cnt += 1
    return cnt+1


def lazy_Select(datasets: dict, k: int,sigma) -> dict:
    result = {}
    for key_ in datasets.keys():
        data = datasets[key_]
        n = len(data)
        epoch=0
        while 1:
            # print(11111)
            epoch+=1
            sampled_data = randomSelect(data,sigma)

            sampled_data = merge_sort(sampled_data)

            x = int(k * pow(n, -(1-sigma)))
            l = max(0, int(x - math.sqrt(n)))
            r = min(int(pow(n, sigma)), int(x + math.sqrt(n)))

            L = sampled_data[max(1, l - 1)]
            H = sampled_data[r - 1]
            L_rank = rank(data, L)
            H_rank = rank(data, H)

            p = []
            for i in data:
                if L <= i <= H:
                    p.append(i)

            if L_rank <= k <= H_rank and len(p) <= 4*pow(n, 1-sigma+0.5)+1:
                p = merge_sort(p)
                result[key_] = (p[k-L_rank],epoch)
                break
    return result
