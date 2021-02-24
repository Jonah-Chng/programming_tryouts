#/usr/bin/end python3

class A():
    def __init__(self):
        self.someint = 3
        self.otherfunc()
    def somefunc(self):
        self.someint +=1
        self.otherfunc()
    def otherfunc(self):
        print(self.someint)
a = A()
