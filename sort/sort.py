
def bubbleSORT(li):
    for i in reversed(range(len(li)-1)):
        for j in range(i+1):
            if li[j]>li[j+1]:
                li[j],li[j+1]=li[j+1],li[j] ## swap two.
        print li


def straightINSERTIONsort(li):
    for i in range(1,len(li)):
        temp = li[i]
        for j in reversed(range(i)):
            print "i",i,"j",j
            if temp < li[j]:
                li[j+1]=li[j]
            else:
                li[j+1]=temp
                break
        print li
            
            
def insertionSORT(list2):
    for i in range(1, len(list2)):
        save = list2[i]
        j = i
        while j > 0 and list2[j - 1] > save:
            list2[j] = list2[j-1]
            j -= 1
        list2[j] = save
    print list2
        
def shellSORT(list2):
    d = len(list2)/2
    while d >0:
        for i in range(d,len(list2)):
            j=i
            save= list2[i]
            while j>=d and list2[j-d]> save:
                list2[j]=list2[j-d]
                j-=d
            list2[j]=save  ## j changed
        d/=2
    print list2




def heapSORT(li):
    n = len(li)
    for i in range((n-1)/2,-1,-1):  ## (n-1)/2 the last parent node
        heapADJUST(li,i,n-1)
    for i in range(n-1):   ##
        li[0],li[n-i-1] = li[n-i-1],li[0]
        heapADJUST(li,0,n-i-2)
    print li

def heapADJUST(li,s,m):
    rc = li[s]
    j = 2*s+1
    while j <= m:
        if ((j < m) and (li[j]< li[j+1])):
            j+=1
        if (rc >= li[j]):
            break
        li[s]= li[j]   ####  place the bigger one
        s= j
        j = 2*j +1
    li[s]=rc   ## place the 

        
if __name__ == '__main__':
    #bubbleSORT([100,15,13,1,23,12])
    #straightINSERTIONsort([3,5,1])
    #insertion_sort([1,2,5,3])
   # shellSORT([21,34,2,23,45,65])
    heapSORT([21,34,2,23,45])


    
        
