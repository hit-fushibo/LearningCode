import random_data_generate as rg
import db

snum=10000
cnum=1000
tnum=500
cl=20
cr=30

DB=db.DatabaseManager()


rg.delet_db(DB)
rg.generate_teacher(tnum,DB)
rg.generate_course(cnum,tnum,DB)
rg.generate_select(snum,cnum,cl,cr,DB)
rg.generate_student(snum,DB)


DB.close_connection()