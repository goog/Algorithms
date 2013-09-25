#!/usr/bin/python

def partition(a,low,high):
    ## set the pivot
    p = a[low]

    while(low < high):
        while(low < high and a[high] >= p):
            high-=1
        a[low] = a[high]
        while(low < high and a[low] <= p):
            low+=1
        a[high] = a[low]
        high-=1
    a[low] = p  ## set the p value
    return low

def qsort(a,low,high):
    if low < high:
        pp = partition(a,low,high)
        qsort(a,low,pp-1)
        qsort(a,pp+1,high)
    
    

if __name__ =="__main__":
    a = [12,3,4,5677,13,24,132,27,45,23412]
    print "the original array is:",a

    print "="*20
    qsort(a,0,len(a)-1)
    print a
    
