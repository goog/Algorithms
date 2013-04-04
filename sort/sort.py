
def bubbleSORT(li):
    for i in reversed(range(len(li)-1)):
        for j in range(i+1):
            if li[j]>li[j+1]:
                li[j],li[j+1]=li[j+1],li[j] ## swap two.
        print li


            
def insertionSORT(list2):
    for i in range(1,len(list2)):
        save = list2[i]
        j = i  ### j, the position to insert
        while j > 0 and list2[j-1] > save:
            list2[j] = list2[j-1]
            j-= 1
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



def merge(li,li2):
    listM= []
    i , j = 0,0
    while(i < len(li) and j < len(li2)):
        if li[i] <= li2[j]:
            listM.append(li[i])
            i+=1
        else:
            listM.append(li2[j])
            j+=1
    if i != len(li):
        listM.extend(li[i:])
    elif j!= len(li2):
        listM.extend(li2[j:])
    print listM



def partition(li,low,high):
    pivot = li[low]   ##  a unit spare
    while low < high:
        while low < high and li[high]>=pivot:
            high-=1
        li[low]= li[high]
        while low < high and li[low]<=pivot:
            low+=1
        li[high]= li[low]
    li[low] = pivot
    return low

def quickr(li,low,high):
    if low < high:
        p = partition(li,low,high)
        quickr(li,low,p-1)
        quickr(li,p+1,high)

def quickSORT(li):
    quickr(li,0,len(li)-1)
if  __name__ == '__main__':
    #bubbleSORT([100,15,13,1,23,12])
    #insertionSORT([1,2,5,3])
    #shellSORT([21,34,2,23,45,65])
    #heapSORT([21,12,2,100,45])
    #merge([2,34,556],[34,34,67,1234,3567,4234])
    li = [4,56,23,12,1345,321]
    quickSORT(li)
    print li
        
