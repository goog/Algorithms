#-*- coding: UTF-8 -*-

def outer():
    x = 1
    def inner():
        print x
    inner()

if __name__ =="__main__":
    outer()
