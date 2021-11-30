
#!/usr/bin/env python
"""
@author Kevin Jie
@desc The module implements the Student object with names, sex, and phone number
      and has a self.__str__ function.
@date 2020/11/27
"""

class Student:
    def __init__(self, name, sex, tel):
        self.name = name
        self.sex = sex
        self.tel = tel

    def __str__(self):
        return "Name:{}, Sex:{}, Phone:{}".format(self.name, self.sex, self.tel)
