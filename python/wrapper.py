#-*- coding: UTF-8 -*-
import time
import os,sys
 
def foo():
    for i in range(1000000):
        n = 1.23456789*9.2345678
    print('in foo()')
 
# 定义一个计时器，传入一个，并返回另一个附加了计时功能的方法
def timeit(func):  
    # 定义一个内嵌的包装函数，给传入的函数加上计时功能的包装
    def wrapper():
        start = time.clock()
        func()
        end =time.clock()
        print('used:', end - start)
     
    # 将包装后的函数返回
    return wrapper
if __name__== "__main__":
    foo = timeit(foo)
    foo()
