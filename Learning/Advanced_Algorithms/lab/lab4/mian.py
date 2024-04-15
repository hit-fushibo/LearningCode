import random_data_generate as rg
import db
import numpy as np
from exact_weight import ExatWeight
from sample import Sampling
import time


DB = db.DatabaseManager()
'''
init database
'''
snum = 100
cnum = 10
tnum = 5
cl = 2
cr = 5

# rg.delet_db(DB)
# rg.generate_teacher(tnum,DB)
# rg.generate_course(cnum,tnum,DB)
# rg.generate_select(snum,cnum,cl,cr,DB)
# rg.generate_student(snum,DB)
# a=DB.query_data('teacherw',['*'])
# print(list(a))

'''
set query
'''
join_order1 = ['s', 'course']
join_order2 = ['s', 'course', 'teacher']
join_order3 = ['student', 's', 'course', 'teacher']




rg.delet_w(DB)
a = ExatWeight(DB, join_order1)
a.cul_weight()

s = Sampling(DB, 10, join_order1)


DB.close_connection()
