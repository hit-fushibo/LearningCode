import random
import numpy as np
import string
import db


def generate_random_string():
    length = np.random.randint(1, 11)
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for _ in range(length))


def generate_student(num, DM: db.DatabaseManager):
    log_value = np.log10(num)
    id_len = int(np.ceil(log_value))
    for i in range(1, num+1):
        sid = str(i).zfill(int(id_len))
        sname = generate_random_string()
        attributes = ['sname', 'sid']
        values = ['\''+sname+'\'', '\''+sid+'\'']
        DM.add_tuple('student', attributes, values)


def generate_teacher(num, DM: db.DatabaseManager):

    log_value = np.log10(num)
    id_len = int(np.ceil(log_value))
    for i in range(1, num+1):
        tid = str(i).zfill(int(id_len))
        tname = generate_random_string()
        attributes = ['tname', 'tid']
        values = ['\''+tname+'\'', '\''+tid+'\'']
        DM.add_tuple('teacher', attributes, values)


def generate_course(c_num, t_num, DM: db.DatabaseManager):

    log_value = np.log10(c_num)
    c_id_len = int(np.ceil(log_value))
    log_value = np.log10(t_num)
    t_id_len = int(np.ceil(log_value))

    for i in range(1, c_num+1):
        c_id = str(i).zfill(c_id_len)
        t_id = str(int(np.random.randint(1, t_num+1))).zfill(t_id_len)
        attributes = ['course', 'tid']
        values = ['\''+c_id+'\'', '\''+t_id+'\'']
        DM.add_tuple('course', attributes, values)


def generate_select(snum, cnum, cl, cr, DM: db.DatabaseManager):

    log_value = np.log10(cnum)
    cid_len = int(np.ceil(log_value))
    log_value = np.log10(snum)
    sid_len = int(np.ceil(log_value))

    for i in range(1, snum+1):
        sid = str(i).zfill(sid_len)
        length = random.randint(cl, cr)
        sequence = random.sample(range(1, cnum+1), length)
        for cid in sequence:
            c_id = str(int(cid)).zfill(cid_len)
            attributes = ['sid', 'course']
            values = ['\''+sid+'\'', '\''+c_id+'\'']
            DM.add_tuple('s', attributes, values)


def delet_db(DM: db.DatabaseManager):
    DM.delete_tuple('s', '*')
    DM.delete_tuple('course', '*')
    DM.delete_tuple('teacher', '*')
    DM.delete_tuple('student', '*')
    DM.delete_tuple('sw', '*')


def delet_w(DM: db.DatabaseManager):
    DM.delete_tuple('coursew', '*')
    DM.delete_tuple('teacherw', '*')
    DM.delete_tuple('studentw', '*')
