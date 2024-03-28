from dataloder import datasets
from sort_select import sort_select
from linear import liner_select
from lazySelect import lazy_Select

import numpy as np
import time
import matplotlib.pyplot as plt

mid_index = 50000
data_size = mid_index*2+1
epoch = 100


def main():
    data = datasets(data_size).load()

    sort_select_time = []
    liner_select_time = []
    lazy_select_time = []

    u_err = 0
    n_err = 0
    z_err = 0
    u_acc = []
    n_acc = []
    z_acc = []

    for i in range(epoch):
        k = mid_index

        # sort select
        t1 = time.time()
        correct_result = sort_select(data, k)
        t2 = time.time()
        sort_select_time.append(t2-t1)

        # liner select
        t1 = time.time()
        liner_result = liner_select(data, k)
        t2 = time.time()
        liner_select_time.append(t2-t1)

        # lazy select
        t1 = time.time()
        lazy_result = lazy_Select(data, k)
        t2 = time.time()
        lazy_select_time.append(t2-t1)

        # acc
        u_err += int(correct_result['uniform'] != lazy_result['uniform'])
        u_acc.append(1-(u_err/(i+1)))

        n_err += int(correct_result['normal'] != lazy_result['normal'])
        n_acc.append(1-(n_err/(i+1)))

        z_err += int(correct_result['zipf'] != lazy_result['zipf'])
        z_acc.append(1-(z_err/(i+1)))

    x = [i+1 for i in range(epoch)]

    fig, ax = plt.subplots(1, 4, figsize=(16, 6))
    ax[0].plot(x, sort_select_time, 'r-', label='sort select time')
    ax[0].plot(x, liner_select_time, 'g-', label='liner select time')
    ax[0].plot(x, lazy_select_time, 'b-', label='lazy select time')
    ax[0].set_title('alg run time')

    ax[1].plot(x, u_acc, 'r--', label='u acc')
    ax[1].set_title('uniform accuracy')

    ax[2].plot(x, n_acc, 'g--', label='n acc')
    ax[2].set_title('normal accuracy')

    ax[3].plot(x, z_acc, 'b--', label='z acc')
    ax[3].set_title('zipf accuracy')

    ax[0].legend()
    plt.savefig('LearningCode/Learning/Advanced_Algorithms/lab/lab2/result.png')
    plt.show()


if __name__ == '__main__':
    main()
