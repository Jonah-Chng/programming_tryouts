#!/usr/bin/python3.8
class Rectangle:
    def __init__(self, length, breadth):
        self.length = length
        self.breadth= breadth

    def getarea(self):
        return self.length *  self.breadth

    def getperimter(self):
        return self.length*2 + self.breadth*2

class Square(Rectangle):
    def __init__(self, length):
        super().__init__(length, length)

if __name__ == "__main__":
    square = Square(4)
    print(square.getarea())
