#!/usr/bin/env python3

import logging

class greeting():
    def __init__(self): 
        self.value = 3

class helloworld(greeting):
    def __init__(self):
        super().__init__()
    
    def greet(self):
        print('I am holding', self.value)

if __name__ == '__main__':
    g = helloworld()
    g.greet()