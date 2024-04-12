import numpy as np
import time
import matplotlib.pyplot as plt
from pyparsing import nums

epsilon = 1e-10
INT_MAX = 100


class Graph:
    def __init__(self, n: int) -> None:
        self.n = n
        self.graph = np.zeros((n, n))
        for i in range(n):
            for j in range(i, n):
                if i == j:
                    self.graph[i, j] = np.inf
                else:
                    self.graph[i, j] = np.random.uniform(0+epsilon, 1)
                    self.graph[j, i] = self.graph[i, j]

    def prim(self) -> float:

        LOWCOST = np.zeros(self.n)
        CLOSEST = np.zeros(self.n, dtype=int)
        ans = np.zeros((self.n - 1, 3))

        k, weight = 0, 0
        for i in range(1, self.n):
            LOWCOST[i] = self.graph[0][i]
            CLOSEST[i] = 0

        for i in range(1, self.n):
            min = INT_MAX
            for j in range(1, self.n):
                if LOWCOST[j] < min:
                    min = LOWCOST[j]
                    k = j

            weight += min
            ans[i - 1][0] = CLOSEST[k]
            ans[i - 1][1] = k
            ans[i - 1][2] = self.graph[CLOSEST[k]][k]
            LOWCOST[k] = INT_MAX - 1
            for j in range(1, self.n):
                if self.graph[k][j] < LOWCOST[j] and abs(LOWCOST[j] - INT_MAX + 1) > 0.001:
                    LOWCOST[j] = self.graph[k][j]
                    CLOSEST[j] = k

        return weight


def generate_graph(n: int) -> Graph:
    return Graph(n)


def cal_MST_weight(n: int, epoch: int) -> float:
    weight_sum = 0
    for _ in range(epoch):
        G = generate_graph(n)
        weight_sum += G.prim()
    del G
    weight_sum /= epoch
    return weight_sum


def main():
    epoch = [1000,800,600,400,200,150,100]
    n_nums = [16, 32, 64, 128, 256, 512, 1024]
    mean_weight_list = []
    time_lsit = []
    i=0
    for n in n_nums:
        print(n)
        t1 = time.time()
        mean_MST_weight = cal_MST_weight(n, epoch[i])
        t2 = time.time()
        mean_weight_list.append(mean_MST_weight)
        time_lsit.append((t2-t1)/epoch[i])
        i+=1
    fig, ax = plt.subplots(1, 2, figsize=(16, 8))
    plt.subplots_adjust(wspace=0.5)
    ax[0].plot(n_nums, mean_weight_list, 'r-')
    ax[1].plot(n_nums, time_lsit, 'r-')

    ax[0].set_xlabel('Number of vertices')
    ax[0].set_ylabel('Mean MST weight')
    ax[0].set_xticks(n_nums)

    ax[1].set_xlabel('Number of vertices')
    ax[1].set_ylabel('alg run time')
    ax[1].set_xticks(n_nums)
    plt.savefig('LearningCode/Learning/Advanced_Algorithms/lab/lab3/result.png')
    plt.show()


if __name__ == '__main__':
    main()
