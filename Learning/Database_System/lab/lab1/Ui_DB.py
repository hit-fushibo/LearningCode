# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'd:\code\Learning\Database_System\lab\lab1\DB.ui'
#
# Created by: PyQt5 UI code generator 5.15.10
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1119, 898)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.line = QtWidgets.QFrame(self.centralwidget)
        self.line.setGeometry(QtCore.QRect(0, 190, 1121, 21))
        self.line.setFrameShape(QtWidgets.QFrame.HLine)
        self.line.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line.setObjectName("line")
        self.line_2 = QtWidgets.QFrame(self.centralwidget)
        self.line_2.setGeometry(QtCore.QRect(0, 440, 1131, 20))
        self.line_2.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_2.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_2.setObjectName("line_2")
        self.line_3 = QtWidgets.QFrame(self.centralwidget)
        self.line_3.setGeometry(QtCore.QRect(550, 450, 20, 441))
        self.line_3.setFrameShape(QtWidgets.QFrame.VLine)
        self.line_3.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_3.setObjectName("line_3")
        self.school_display = QtWidgets.QTextBrowser(self.centralwidget)
        self.school_display.setGeometry(QtCore.QRect(10, 40, 261, 131))
        self.school_display.setObjectName("school_display")
        self.school_query = QtWidgets.QPushButton(self.centralwidget)
        self.school_query.setGeometry(QtCore.QRect(196, 17, 75, 23))
        self.school_query.setObjectName("school_query")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(10, 10, 54, 12))
        self.label.setObjectName("label")
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(0, 210, 61, 16))
        self.label_4.setObjectName("label_4")
        self.teacher_display = QtWidgets.QTextBrowser(self.centralwidget)
        self.teacher_display.setGeometry(QtCore.QRect(0, 316, 181, 131))
        self.teacher_display.setObjectName("teacher_display")
        self.teacher_query = QtWidgets.QPushButton(self.centralwidget)
        self.teacher_query.setGeometry(QtCore.QRect(0, 290, 75, 23))
        self.teacher_query.setObjectName("teacher_query")
        self.school_id = QtWidgets.QTextEdit(self.centralwidget)
        self.school_id.setGeometry(QtCore.QRect(90, 230, 131, 31))
        self.school_id.setObjectName("school_id")
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setGeometry(QtCore.QRect(0, 240, 91, 20))
        self.label_5.setObjectName("label_5")
        self.add_teacher_id = QtWidgets.QTextEdit(self.centralwidget)
        self.add_teacher_id.setGeometry(QtCore.QRect(183, 316, 91, 31))
        self.add_teacher_id.setObjectName("add_teacher_id")
        self.label_6 = QtWidgets.QLabel(self.centralwidget)
        self.label_6.setGeometry(QtCore.QRect(200, 300, 61, 16))
        self.label_6.setObjectName("label_6")
        self.add_teacher_name = QtWidgets.QTextEdit(self.centralwidget)
        self.add_teacher_name.setGeometry(QtCore.QRect(183, 364, 91, 31))
        self.add_teacher_name.setObjectName("add_teacher_name")
        self.label_7 = QtWidgets.QLabel(self.centralwidget)
        self.label_7.setGeometry(QtCore.QRect(200, 348, 61, 16))
        self.label_7.setObjectName("label_7")
        self.add_teacher = QtWidgets.QPushButton(self.centralwidget)
        self.add_teacher.setGeometry(QtCore.QRect(190, 410, 75, 23))
        self.add_teacher.setObjectName("add_teacher")
        self.student_display = QtWidgets.QTextBrowser(self.centralwidget)
        self.student_display.setGeometry(QtCore.QRect(290, 316, 181, 131))
        self.student_display.setObjectName("student_display")
        self.add_student_id = QtWidgets.QTextEdit(self.centralwidget)
        self.add_student_id.setGeometry(QtCore.QRect(473, 295, 91, 31))
        self.add_student_id.setObjectName("add_student_id")
        self.label_8 = QtWidgets.QLabel(self.centralwidget)
        self.label_8.setGeometry(QtCore.QRect(490, 279, 51, 16))
        self.label_8.setObjectName("label_8")
        self.add_student = QtWidgets.QPushButton(self.centralwidget)
        self.add_student.setGeometry(QtCore.QRect(480, 420, 75, 23))
        self.add_student.setObjectName("add_student")
        self.add_student_name = QtWidgets.QTextEdit(self.centralwidget)
        self.add_student_name.setGeometry(QtCore.QRect(473, 343, 91, 31))
        self.add_student_name.setObjectName("add_student_name")
        self.student_queery = QtWidgets.QPushButton(self.centralwidget)
        self.student_queery.setGeometry(QtCore.QRect(290, 292, 75, 23))
        self.student_queery.setObjectName("student_queery")
        self.label_9 = QtWidgets.QLabel(self.centralwidget)
        self.label_9.setGeometry(QtCore.QRect(490, 327, 61, 16))
        self.label_9.setObjectName("label_9")
        self.label_10 = QtWidgets.QLabel(self.centralwidget)
        self.label_10.setGeometry(QtCore.QRect(780, 327, 51, 16))
        self.label_10.setObjectName("label_10")
        self.add_class = QtWidgets.QPushButton(self.centralwidget)
        self.add_class.setGeometry(QtCore.QRect(760, 387, 75, 23))
        self.add_class.setObjectName("add_class")
        self.class_display = QtWidgets.QTextBrowser(self.centralwidget)
        self.class_display.setGeometry(QtCore.QRect(570, 316, 181, 131))
        self.class_display.setObjectName("class_display")
        self.add_class_id = QtWidgets.QTextEdit(self.centralwidget)
        self.add_class_id.setGeometry(QtCore.QRect(753, 341, 91, 31))
        self.add_class_id.setObjectName("add_class_id")
        self.class_query = QtWidgets.QPushButton(self.centralwidget)
        self.class_query.setGeometry(QtCore.QRect(570, 290, 75, 23))
        self.class_query.setObjectName("class_query")
        self.classroom_id = QtWidgets.QTextEdit(self.centralwidget)
        self.classroom_id.setGeometry(QtCore.QRect(1031, 316, 91, 31))
        self.classroom_id.setObjectName("classroom_id")
        self.classroom_addr = QtWidgets.QTextEdit(self.centralwidget)
        self.classroom_addr.setGeometry(QtCore.QRect(1031, 364, 91, 31))
        self.classroom_addr.setObjectName("classroom_addr")
        self.label_12 = QtWidgets.QLabel(self.centralwidget)
        self.label_12.setGeometry(QtCore.QRect(1048, 348, 61, 16))
        self.label_12.setObjectName("label_12")
        self.classroom_display = QtWidgets.QTextBrowser(self.centralwidget)
        self.classroom_display.setGeometry(QtCore.QRect(850, 316, 181, 131))
        self.classroom_display.setObjectName("classroom_display")
        self.classroom_query = QtWidgets.QPushButton(self.centralwidget)
        self.classroom_query.setGeometry(QtCore.QRect(850, 290, 75, 23))
        self.classroom_query.setObjectName("classroom_query")
        self.label_13 = QtWidgets.QLabel(self.centralwidget)
        self.label_13.setGeometry(QtCore.QRect(1048, 300, 61, 16))
        self.label_13.setObjectName("label_13")
        self.add_classroom = QtWidgets.QPushButton(self.centralwidget)
        self.add_classroom.setGeometry(QtCore.QRect(1038, 410, 75, 23))
        self.add_classroom.setObjectName("add_classroom")
        self.del_teacher = QtWidgets.QPushButton(self.centralwidget)
        self.del_teacher.setGeometry(QtCore.QRect(100, 290, 75, 23))
        self.del_teacher.setObjectName("del_teacher")
        self.del_student = QtWidgets.QPushButton(self.centralwidget)
        self.del_student.setGeometry(QtCore.QRect(397, 292, 75, 23))
        self.del_student.setObjectName("del_student")
        self.del_class = QtWidgets.QPushButton(self.centralwidget)
        self.del_class.setGeometry(QtCore.QRect(673, 290, 75, 23))
        self.del_class.setObjectName("del_class")
        self.del_classroom = QtWidgets.QPushButton(self.centralwidget)
        self.del_classroom.setGeometry(QtCore.QRect(956, 290, 75, 23))
        self.del_classroom.setObjectName("del_classroom")
        self.course_display = QtWidgets.QTextBrowser(self.centralwidget)
        self.course_display.setGeometry(QtCore.QRect(0, 558, 181, 131))
        self.course_display.setObjectName("course_display")
        self.label_11 = QtWidgets.QLabel(self.centralwidget)
        self.label_11.setGeometry(QtCore.QRect(0, 452, 91, 16))
        self.label_11.setObjectName("label_11")
        self.add_course_id = QtWidgets.QTextEdit(self.centralwidget)
        self.add_course_id.setGeometry(QtCore.QRect(183, 558, 91, 31))
        self.add_course_id.setObjectName("add_course_id")
        self.del_course = QtWidgets.QPushButton(self.centralwidget)
        self.del_course.setGeometry(QtCore.QRect(100, 532, 75, 23))
        self.del_course.setObjectName("del_course")
        self.label_14 = QtWidgets.QLabel(self.centralwidget)
        self.label_14.setGeometry(QtCore.QRect(207, 542, 51, 16))
        self.label_14.setObjectName("label_14")
        self.add_course = QtWidgets.QPushButton(self.centralwidget)
        self.add_course.setGeometry(QtCore.QRect(190, 700, 75, 23))
        self.add_course.setObjectName("add_course")
        self.label_15 = QtWidgets.QLabel(self.centralwidget)
        self.label_15.setGeometry(QtCore.QRect(0, 482, 91, 20))
        self.label_15.setObjectName("label_15")
        self.teacher_id = QtWidgets.QTextEdit(self.centralwidget)
        self.teacher_id.setGeometry(QtCore.QRect(92, 482, 131, 31))
        self.teacher_id.setObjectName("teacher_id")
        self.add_course_name = QtWidgets.QTextEdit(self.centralwidget)
        self.add_course_name.setGeometry(QtCore.QRect(183, 606, 91, 31))
        self.add_course_name.setObjectName("add_course_name")
        self.course_query = QtWidgets.QPushButton(self.centralwidget)
        self.course_query.setGeometry(QtCore.QRect(0, 532, 75, 23))
        self.course_query.setObjectName("course_query")
        self.label_16 = QtWidgets.QLabel(self.centralwidget)
        self.label_16.setGeometry(QtCore.QRect(208, 590, 51, 16))
        self.label_16.setObjectName("label_16")
        self.label_17 = QtWidgets.QLabel(self.centralwidget)
        self.label_17.setGeometry(QtCore.QRect(204, 640, 61, 16))
        self.label_17.setObjectName("label_17")
        self.add_course_classroom = QtWidgets.QTextEdit(self.centralwidget)
        self.add_course_classroom.setGeometry(QtCore.QRect(183, 656, 91, 31))
        self.add_course_classroom.setObjectName("add_course_classroom")
        self.free_cr_query = QtWidgets.QPushButton(self.centralwidget)
        self.free_cr_query.setGeometry(QtCore.QRect(320, 532, 111, 23))
        self.free_cr_query.setObjectName("free_cr_query")
        self.free_classroom_display_2 = QtWidgets.QTextBrowser(self.centralwidget)
        self.free_classroom_display_2.setGeometry(QtCore.QRect(320, 558, 181, 131))
        self.free_classroom_display_2.setObjectName("free_classroom_display_2")
        self.label_18 = QtWidgets.QLabel(self.centralwidget)
        self.label_18.setGeometry(QtCore.QRect(570, 450, 91, 16))
        self.label_18.setObjectName("label_18")
        self.student_id = QtWidgets.QTextEdit(self.centralwidget)
        self.student_id.setGeometry(QtCore.QRect(774, 460, 131, 31))
        self.student_id.setObjectName("student_id")
        self.label_19 = QtWidgets.QLabel(self.centralwidget)
        self.label_19.setGeometry(QtCore.QRect(684, 460, 91, 20))
        self.label_19.setObjectName("label_19")
        self.add_school_id = QtWidgets.QTextEdit(self.centralwidget)
        self.add_school_id.setGeometry(QtCore.QRect(273, 46, 91, 31))
        self.add_school_id.setObjectName("add_school_id")
        self.label_20 = QtWidgets.QLabel(self.centralwidget)
        self.label_20.setGeometry(QtCore.QRect(290, 30, 61, 16))
        self.label_20.setObjectName("label_20")
        self.add_school = QtWidgets.QPushButton(self.centralwidget)
        self.add_school.setGeometry(QtCore.QRect(280, 140, 75, 23))
        self.add_school.setObjectName("add_school")
        self.add_school_name = QtWidgets.QTextEdit(self.centralwidget)
        self.add_school_name.setGeometry(QtCore.QRect(273, 94, 91, 31))
        self.add_school_name.setObjectName("add_school_name")
        self.label_21 = QtWidgets.QLabel(self.centralwidget)
        self.label_21.setGeometry(QtCore.QRect(290, 78, 61, 16))
        self.label_21.setObjectName("label_21")
        self.free_course_query = QtWidgets.QPushButton(self.centralwidget)
        self.free_course_query.setGeometry(QtCore.QRect(910, 504, 101, 23))
        self.free_course_query.setObjectName("free_course_query")
        self.free_course_display = QtWidgets.QTextBrowser(self.centralwidget)
        self.free_course_display.setGeometry(QtCore.QRect(930, 530, 181, 131))
        self.free_course_display.setObjectName("free_course_display")
        self.selected_course_query = QtWidgets.QPushButton(self.centralwidget)
        self.selected_course_query.setGeometry(QtCore.QRect(570, 502, 81, 23))
        self.selected_course_query.setObjectName("selected_course_query")
        self.selected_course_display = QtWidgets.QTextBrowser(self.centralwidget)
        self.selected_course_display.setGeometry(QtCore.QRect(570, 528, 181, 131))
        self.selected_course_display.setObjectName("selected_course_display")
        self.drop_course = QtWidgets.QPushButton(self.centralwidget)
        self.drop_course.setGeometry(QtCore.QRect(663, 502, 81, 23))
        self.drop_course.setObjectName("drop_course")
        self.select_course = QtWidgets.QPushButton(self.centralwidget)
        self.select_course.setGeometry(QtCore.QRect(1027, 504, 81, 23))
        self.select_course.setObjectName("select_course")
        self.borrow_book = QtWidgets.QPushButton(self.centralwidget)
        self.borrow_book.setGeometry(QtCore.QRect(1027, 686, 81, 23))
        self.borrow_book.setObjectName("borrow_book")
        self.borrowed_book_query = QtWidgets.QPushButton(self.centralwidget)
        self.borrowed_book_query.setGeometry(QtCore.QRect(570, 684, 81, 23))
        self.borrowed_book_query.setObjectName("borrowed_book_query")
        self.free_book_query = QtWidgets.QPushButton(self.centralwidget)
        self.free_book_query.setGeometry(QtCore.QRect(910, 686, 101, 23))
        self.free_book_query.setObjectName("free_book_query")
        self.free_book_display = QtWidgets.QTextBrowser(self.centralwidget)
        self.free_book_display.setGeometry(QtCore.QRect(930, 712, 181, 131))
        self.free_book_display.setObjectName("free_book_display")
        self.return_book = QtWidgets.QPushButton(self.centralwidget)
        self.return_book.setGeometry(QtCore.QRect(663, 684, 81, 23))
        self.return_book.setObjectName("return_book")
        self.borrowed_book_display = QtWidgets.QTextBrowser(self.centralwidget)
        self.borrowed_book_display.setGeometry(QtCore.QRect(570, 710, 181, 131))
        self.borrowed_book_display.setObjectName("borrowed_book_display")
        self.lib_display = QtWidgets.QTextBrowser(self.centralwidget)
        self.lib_display.setGeometry(QtCore.QRect(379, 37, 261, 131))
        self.lib_display.setObjectName("lib_display")
        self.lib_query = QtWidgets.QPushButton(self.centralwidget)
        self.lib_query.setGeometry(QtCore.QRect(382, 13, 75, 23))
        self.lib_query.setObjectName("lib_query")
        self.books_desplay = QtWidgets.QTextBrowser(self.centralwidget)
        self.books_desplay.setGeometry(QtCore.QRect(677, 38, 261, 131))
        self.books_desplay.setObjectName("books_desplay")
        self.book_query = QtWidgets.QPushButton(self.centralwidget)
        self.book_query.setGeometry(QtCore.QRect(861, 13, 75, 23))
        self.book_query.setObjectName("book_query")
        self.book_query_lib_id = QtWidgets.QTextEdit(self.centralwidget)
        self.book_query_lib_id.setGeometry(QtCore.QRect(760, 5, 91, 31))
        self.book_query_lib_id.setObjectName("book_query_lib_id")
        self.label_22 = QtWidgets.QLabel(self.centralwidget)
        self.label_22.setGeometry(QtCore.QRect(690, 10, 61, 16))
        self.label_22.setObjectName("label_22")
        self.label_23 = QtWidgets.QLabel(self.centralwidget)
        self.label_23.setGeometry(QtCore.QRect(987, 84, 51, 16))
        self.label_23.setObjectName("label_23")
        self.add_book = QtWidgets.QPushButton(self.centralwidget)
        self.add_book.setGeometry(QtCore.QRect(977, 146, 75, 23))
        self.add_book.setObjectName("add_book")
        self.label_24 = QtWidgets.QLabel(self.centralwidget)
        self.label_24.setGeometry(QtCore.QRect(987, 36, 51, 16))
        self.label_24.setObjectName("label_24")
        self.add_book_id = QtWidgets.QTextEdit(self.centralwidget)
        self.add_book_id.setGeometry(QtCore.QRect(970, 52, 91, 31))
        self.add_book_id.setObjectName("add_book_id")
        self.add_book_name = QtWidgets.QTextEdit(self.centralwidget)
        self.add_book_name.setGeometry(QtCore.QRect(970, 100, 91, 31))
        self.add_book_name.setObjectName("add_book_name")
        self.del_book = QtWidgets.QPushButton(self.centralwidget)
        self.del_book.setGeometry(QtCore.QRect(860, 170, 75, 23))
        self.del_book.setObjectName("del_book")
        self.add_student_name_2 = QtWidgets.QTextEdit(self.centralwidget)
        self.add_student_name_2.setGeometry(QtCore.QRect(473, 390, 91, 31))
        self.add_student_name_2.setObjectName("add_student_name_2")
        self.label_25 = QtWidgets.QLabel(self.centralwidget)
        self.label_25.setGeometry(QtCore.QRect(490, 374, 61, 16))
        self.label_25.setObjectName("label_25")
        self.student_id_2 = QtWidgets.QTextEdit(self.centralwidget)
        self.student_id_2.setGeometry(QtCore.QRect(770, 600, 131, 31))
        self.student_id_2.setObjectName("student_id_2")
        self.student_id_3 = QtWidgets.QTextEdit(self.centralwidget)
        self.student_id_3.setGeometry(QtCore.QRect(770, 790, 131, 31))
        self.student_id_3.setObjectName("student_id_3")
        self.label_26 = QtWidgets.QLabel(self.centralwidget)
        self.label_26.setGeometry(QtCore.QRect(810, 570, 91, 20))
        self.label_26.setObjectName("label_26")
        self.label_27 = QtWidgets.QLabel(self.centralwidget)
        self.label_27.setGeometry(QtCore.QRect(800, 760, 91, 20))
        self.label_27.setObjectName("label_27")
        self.create_view = QtWidgets.QPushButton(self.centralwidget)
        self.create_view.setGeometry(QtCore.QRect(280, 170, 75, 23))
        self.create_view.setObjectName("create_view")
        self.having_test = QtWidgets.QPushButton(self.centralwidget)
        self.having_test.setGeometry(QtCore.QRect(10, 800, 121, 23))
        self.having_test.setObjectName("having_test")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1119, 26))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.school_query.setText(_translate("MainWindow", "院系查询"))
        self.label.setText(_translate("MainWindow", "学校管理"))
        self.label_4.setText(_translate("MainWindow", "院系管理"))
        self.teacher_query.setText(_translate("MainWindow", "老师查询"))
        self.label_5.setText(_translate("MainWindow", "操作院系编号"))
        self.label_6.setText(_translate("MainWindow", "教师编号"))
        self.label_7.setText(_translate("MainWindow", "教师姓名"))
        self.add_teacher.setText(_translate("MainWindow", "添加老师"))
        self.label_8.setText(_translate("MainWindow", "学号"))
        self.add_student.setText(_translate("MainWindow", "添加学生"))
        self.student_queery.setText(_translate("MainWindow", "学生查询"))
        self.label_9.setText(_translate("MainWindow", "学生姓名"))
        self.label_10.setText(_translate("MainWindow", "班号"))
        self.add_class.setText(_translate("MainWindow", "添加班级"))
        self.class_query.setText(_translate("MainWindow", "班级查询"))
        self.label_12.setText(_translate("MainWindow", "教室地址"))
        self.classroom_query.setText(_translate("MainWindow", "教室查询"))
        self.label_13.setText(_translate("MainWindow", "教室编号"))
        self.add_classroom.setText(_translate("MainWindow", "添加教室"))
        self.del_teacher.setText(_translate("MainWindow", "删除老师"))
        self.del_student.setText(_translate("MainWindow", "删除学生"))
        self.del_class.setText(_translate("MainWindow", "删除班级"))
        self.del_classroom.setText(_translate("MainWindow", "删除教室"))
        self.label_11.setText(_translate("MainWindow", "教师课程管理"))
        self.del_course.setText(_translate("MainWindow", "删除"))
        self.label_14.setText(_translate("MainWindow", "课程号"))
        self.add_course.setText(_translate("MainWindow", "添加课程"))
        self.label_15.setText(_translate("MainWindow", "操作教师编号"))
        self.course_query.setText(_translate("MainWindow", "查询"))
        self.label_16.setText(_translate("MainWindow", "课程名"))
        self.label_17.setText(_translate("MainWindow", "占用教室"))
        self.free_cr_query.setText(_translate("MainWindow", "可用教室查询"))
        self.label_18.setText(_translate("MainWindow", "学生事务管理"))
        self.label_19.setText(_translate("MainWindow", "操作学生学号"))
        self.label_20.setText(_translate("MainWindow", "院系编号"))
        self.add_school.setText(_translate("MainWindow", "添加院系"))
        self.label_21.setText(_translate("MainWindow", "院系名称"))
        self.free_course_query.setText(_translate("MainWindow", "可选课程查询"))
        self.selected_course_query.setText(_translate("MainWindow", "已选课程查询"))
        self.drop_course.setText(_translate("MainWindow", "退课"))
        self.select_course.setText(_translate("MainWindow", "选课"))
        self.borrow_book.setText(_translate("MainWindow", "借书"))
        self.borrowed_book_query.setText(_translate("MainWindow", "已借图书查询"))
        self.free_book_query.setText(_translate("MainWindow", "可借图书查询"))
        self.return_book.setText(_translate("MainWindow", "还书"))
        self.lib_query.setText(_translate("MainWindow", "图书馆查询"))
        self.book_query.setText(_translate("MainWindow", "藏书查询"))
        self.label_22.setText(_translate("MainWindow", "图书馆编号"))
        self.label_23.setText(_translate("MainWindow", "图书名称"))
        self.add_book.setText(_translate("MainWindow", "添加图书"))
        self.label_24.setText(_translate("MainWindow", "图书编号"))
        self.del_book.setText(_translate("MainWindow", "删除图书"))
        self.label_25.setText(_translate("MainWindow", "所在班级"))
        self.label_26.setText(_translate("MainWindow", "课程号"))
        self.label_27.setText(_translate("MainWindow", "图书编号"))
        self.create_view.setText(_translate("MainWindow", "生成视图"))
        self.having_test.setText(_translate("MainWindow", "having_test"))
