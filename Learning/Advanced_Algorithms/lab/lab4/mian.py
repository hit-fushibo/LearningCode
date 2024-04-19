import matplotlib.pyplot as plt
import numpy as np
import time
import os

import random_data_generate as rg
import db
from exact_weight import ExatWeight
from extended_olken import ExtendedOlken
from full_join import FullJoin
from sample import Sampling

save_path = 'LearningCode/Learning/Advanced_Algorithms/lab/lab4'
'''
def test func
'''


def ew(join_order, sample_num,DB):
    a = ExatWeight(DB, join_order,sample_num)
    a.Sample()
    
    del a


def eo(join_order, sample_num,DB):
    a = ExtendedOlken(DB, join_order,sample_num)
    a.Sample()
    
    del a
    


# def oe(join_order, sample_num):
#     pass


def full_join(join_order, sample_num):
    a = FullJoin(DB, join_order)
    a.run()
    del a


'''
init database
'''
DB = db.DatabaseManager()
snum = 10000
cnum = 1000
tnum = 500
cl = [20, 30, 40, 50]
cr = [i+10 for i in cl]

# rg.delet_db(DB)
# rg.generate_teacher(tnum,DB)
# rg.generate_course(cnum,tnum,DB)
# rg.generate_select(snum,cnum,cl[1],cr[1],DB)
# rg.generate_student(snum,DB)
print('database init!')

'''
set query
'''
join_order1 = ['student', 's']
join_order2 = ['s', 'course', 'teacher']
# join_order3 = ['student', 's', 'course']
join_orders = [join_order1, join_order2]

'''
test func
'''
# different sample num and different join order

sample_nums = [1e2, 1e3, 1e4, 1e5]
fj_res = []
eo_res = []
ew_res = []
# oe_res = []
x = [2, 3, 4, 5]
for i in range(len(join_orders)):
    print('join order ',i+1)
    join_order = join_orders[i]
    fj_res_t = []
    eo_res_t = []
    ew_res_t = []
    # oe_res_t = []
    for j in range(len(sample_nums)):
        sample_num = int(sample_nums[j])
        print('\t sample_num ',j+1)
        print('\t\t fj begin')
        t1 = time.time()
        full_join(join_order, sample_num)
        t2 = time.time()
        fj_res_t.append(t2-t1)
        print('\t\t fj end')

        print('\t\t eo begin')
        t1 = time.time()
        eo(join_order, sample_num,DB)
        t2 = time.time()
        eo_res_t.append(t2-t1)
        print('\t\t eo end')
        print('\t\t ew begin')
        t1 = time.time()
        ew(join_order, sample_num,DB)
        t2 = time.time()
        ew_res_t.append(t2-t1)
        print('\t\t ew end')

        # t1 = time.time()
        # oe(join_order, sample_num)
        # t2 = time.time()
        # oe_res_t.append(t2-t1)
    plt.figure()
    save_name = 'Q%d.png' % (i+1)
    fj_res_t = np.log10(np.array(fj_res_t))
    eo_res_t = np.log10(np.array(eo_res_t))
    ew_res_t = np.log10(np.array(ew_res_t))
    # oe_res_t = oe_res[i]
    plt.plot(x, fj_res_t, 'r-', label='full join')
    plt.plot(x, eo_res_t, 'g-', label='extended olken')
    plt.plot(x, ew_res_t, 'b-', label='exact eight')
    # plt.plot(x, oe_res_t, 'y-', lable='online exploration')
    plt.scatter(x, fj_res_t, color='r', marker='*')
    plt.scatter(x, eo_res_t, color='g', marker='*')
    plt.scatter(x, ew_res_t, color='b', marker='*')
    # plt.scatter(x, oe_res_t, color='y', marker='*')
    plt.xlabel('sample num')
    plt.ylabel('alg run time(second)')
    plt.xticks([1, 2, 3, 4, 5, 6], ['10^%d' % i for i in range(1, 7)])
    plt.yticks([1, 2, 3, 4, 5, 6], ['10^%d' % i for i in range(1, 7)])
    plt.xlim(0, 7)
    plt.ylim(0, 7)
    plt.legend()
    plt.savefig(os.path.join(save_path, save_name))
    
    fj_res.append(fj_res_t)
    eo_res.append(eo_res_t)
    ew_res.append(ew_res_t)
    # oe_res.append(oe_res_t)
    save_array=np.array([np.log10(np.array(fj_res)),np.log10(np.array(eo_res)),np.log10(np.array(ew_res))])
    np.save(os.path.join(save_path, 'lab4_1_%d.npy'%i),save_array)


# # # different table size
# fj_res = []
# eo_res = []
# ew_res = []
# # oe_res = []

# for i in range(len(join_orders)):
#     print('join_order ',i+1)
#     join_order = join_orders[i]
#     fj_res_t = []
#     eo_res_t = []
#     ew_res_t = []
#     # oe_res_t = []
#     for j in range(len(cl)):
#         print('\tcl ',j+1)
#         sample_num = int(1e4)
#         DB.execute('delete from s;')
#         print('\t\t delete!')
#         rg.generate_select(snum,cnum,cl[j],cr[j],DB)
#         print('\t\t generate!')
#         t1 = time.time()
#         full_join(join_order, sample_num)
#         t2 = time.time()
#         fj_res_t.append(t2-t1)
#         print('\t\tfj')

#         t1 = time.time()
#         eo(join_order, sample_num,DB)
#         t2 = time.time()
#         eo_res_t.append(t2-t1)
#         print('\t\teo')

#         t1 = time.time()
#         ew(join_order, sample_num,DB)
#         t2 = time.time()
#         ew_res_t.append(t2-t1)
#         print('\t\tew')

#         # t1 = time.time()
#         # oe(join_order, sample_num)
#         # t2 = time.time()
#         # oe_res_t.append(t2-t1)
#     plt.figure()
#     save_name = 'Q%d_2.png' % (i+1)
#     fj_res_t = fj_res[i]
#     eo_res_t = eo_res[i]
#     ew_res_t = ew_res[i]
#     # oe_res_t = oe_res[i]
#     plt.plot(x, fj_res_t, 'r-', label='full join')
#     plt.plot(x, eo_res_t, 'g-', label='extended olken')
#     plt.plot(x, ew_res_t, 'b-', label='exact eight')
#     # plt.plot(x, oe_res_t, 'y-', lable='online exploration')
#     plt.scatter(x, fj_res_t, color='r', marker='*')
#     plt.scatter(x, eo_res_t, color='g', marker='*')
#     plt.scatter(x, ew_res_t, color='b', marker='*')
#     # plt.scatter(x, oe_res_t, color='y', marker='*')
#     plt.xlabel('table size(hundred thousand)')
#     plt.ylabel('alg run time(second)')
#     plt.xticks([1, 2, 3, 4, 5, 6], ['10^%d' % i for i in range(1, 7)])
#     plt.yticks([1, 2, 3, 4, 5, 6], ['10^%d' % i for i in range(1, 7)])
#     plt.xlim(0, 7)
#     plt.ylim(0, 7)
#     plt.legend()
#     plt.savefig(os.path.join(save_path, save_name))

#     fj_res.append(fj_res_t)
#     eo_res.append(eo_res_t)
#     ew_res.append(ew_res_t)
#     # oe_res.append(oe_res_t)
#     save_array=np.array([np.log10(np.array(fj_res)),np.log10(np.array(eo_res)),np.log10(np.array(ew_res))])
#     np.save(os.path.join(save_path, 'lab4_2_%d.npy'%i),save_array)
    
DB.close_connection()
