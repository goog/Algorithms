#!/usr/bin/python3.2

## to wrap a function
def auto_dp(func, cache=1000):
    stat_list = list()  ## args list; pages will be loaded to memory
    stat_dict = dict()
    value_dict = dict() ## cache which stores the previous values to avoid repeated computation
    def new_func(*args):
        poped = None
        if len(stat_list) >= cache:  ## FIFO algorithm
            poped = stat_list.pop(0)
            
        if poped is not None:
            stat_dict[poped] -= 1
            if stat_dict[poped] == 0:  ## delete it / clock algorithm
                del stat_dict[poped]
                del value_dict[poped]
        if args in stat_dict: # hits
            stat_dict[args] += 1
            stat_list.append(args)  ## insert to memory
            return value_dict[args] ## return the cached value directly
        
        value_dict[args] = func(*args) ## compute it 
        stat_list.append(args)
        stat_dict[args] = 1
        return value_dict[args]
    return new_func


import sys

sys.setrecursionlimit(50000)

@auto_dp
def fibnacci(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fibnacci(n - 1) + fibnacci(n - 2)

print(fibnacci(5000))
