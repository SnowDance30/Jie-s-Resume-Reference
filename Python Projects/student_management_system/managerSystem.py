#!/usr/bin/env python
"""
@author Kevin Jie
@desc The module implements the main system of the program, having an
      instruction interface and doing the corresponding orders received
      from the client.
@date 2020/11/27
"""

from student import *

class StudentManager:
    def __init__(self):
        # Use a list data structure to record all students
        self.student_list = []

    @staticmethod
    def show_menu():
        """
        @desc: show_menu() displays the menu with corresponding action numbers.
        @param: None
        @return None
        """
        print("Plese select a number：")
        print("1.Add student")
        print("2.Delete Student")
        print("3.Modify Student")
        print("4.Search Student")
        print("5.Display Students")
        print("6.Save Students Information")
        print("7.Exit")

    def add_student(self):
        """
        @desc: self.add_student() adds a new student information into self.student_list.
        @param: None
        @return: None
        """
        # 1.Enter basic information
        name = input("Please enter your name：")
        sex = input("Please enter your sex：")
        tel = input("Please enter your phone number：")
        # 2.Create a Student object
        student = Student(name, sex, tel)
        # 3.Add the Student into the student_list
        self.student_list.append(student)
        print("Success!\n")
        # print(self.student_list)
        # print(student)


    def del_student(self):
        """
        @desc: self.del_student() deletes a student information in self.student_list
        @param: None
        @return: None
        """
        # 1.Enter the name
        del_name = input("Please enter the name：")
        # 2.Loop through the student list
        for i in self.student_list:
            if del_name == i.name:
                self.student_list.remove(i)
                print("Success!\n")
                break
        else:
            print("No such student in the list.\n")
        # print(self.student_list)


    def modify_student(self):
        """
        @desc: self.modify_student() modifies a student's information
        @param: None
        @return: None
        """
        # 1.Enter the name
        modify_name = input("Please enter student's name：")
        # 2.Loop through the student list
        for i in self.student_list:
            if modify_name == i.name:
                i.name = input("New name：")
                i.sex = input("New sex：")
                i.tel = input("New phone number：")
                print("Success! new name: {}, new sex: {}, new phone number: {}\n".format(i.name, i.sex, i.tel))
                break
        else:
            print("No such student.\n")

    def search_student(self):
        # 1.Enter the student's name
        search_name = input("Please enter the student's name：")
        # 2.Loop through the student list
        for i in self.student_list:
            if search_name == i.name:
                print("Name is：{}, sex is：{}, phone number is：{}\n".format(i.name, i.sex, i.tel))
                break
        else:
            print("No student found.")


    def show_student(self):
        """
        @desc: self.show_student() displays all the students in the student list
        @param: None
        @return: None
        """
        # 1.Print header
        print("Name\tSex\tPhone Number")
        # 2.Print information
        for i in self.student_list:
            print("{}\t{}\t{}".format(i.name, i.sex, i.tel))
        print()


    def save_student(self):
        """
        @desc: self.save_student() saves student list into a data file.
        @param: None
        @return: None
        """
        f = open("student.data", "a")
        # Convert each student in the list into dictionary
        new_list = [i.__dict__ for i in self.student_list]
        print(new_list)
        # Write the list as string into the file
        f.write(str(new_list))
        f.close()


    def load_student(self):
        """
        self.load_student() loads student information from student data file
        @param: None
        @return: None
        """
        # Exception checking
        try:
            f = open("student.data", "r")
        except:
            f = open("student.data", "w")
        else:
            # Read from the file, and converts string back to list
            data = f.read()
            new_list = eval(data)
            self.student_list = [Student(i["name"], i["sex"], i["tel"]) for i in new_list]
        finally:
            f.close()

    def run(self):
        """
        @desc: self.run() enters the program.
        @param: None
        @return: None
        """
        # 1. Load students' information from the student data file.
        self.load_student()
        while True:  # Loop in menu
            # 2. Call the main menu
            self.show_menu()
            # 3. Recieve actions from user
            num_action = eval(input("Please enter your number："))

            if num_action == 1:
                self.add_student()

            elif num_action == 2:
                self.del_student()

            elif num_action == 3:
                self.modify_student()

            elif num_action == 4:
                self.search_student()

            elif num_action == 5:
                self.show_student()

            elif num_action == 6:
                self.save_student()

            elif num_action == 7:
                break