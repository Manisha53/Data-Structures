# There is no "static" keyword in python but, class object variables are static by default.
# Types of variables - 
# 1- Class object Variable
# 2- Instance object Variable
# 3- Local variable
# 4- Global Variable
# __init__ method is like a constructor

class Test:
    x=5
    y=10                    # x & y - class object variable. There is only 1 class object for 1 class.
    def __init__(self, a):  # minimum 1 argument should be passed through init method and should be "self", atleast.
        self.a=a            # self.a - instance object variable, a- local variable. Instance object kitne bhi bann sakte hain. init method k call hone k pehle, instance variable ki value kuchh nahi hoti.
        print(self.a," ", a)

obj1 = Test(10)             # init will be called by default as soon as we create an object
obj2 = Test(11)
