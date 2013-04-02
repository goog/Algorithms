def biSEARCH(li,key):
    mid = len(li)/2
    if key == li[mid]:
        print "find it"
    elif key < li[mid]:
        biSEARCH(li[:mid],key)
    else:
        biSEARCH(li[mid+1:],key)


def biSEARCH2(li,key):
    low = 0
    high= len(li)-1
    while(low<=high):
        mid = (low+high)/2
        if key == li[mid]:
            print "find it"
            break
        elif key < li[mid]:
            high = mid -1
        else:
            low = mid +1


if __name__=="__main__":
    li = [1,3,4,5,7,8,90,100]
    biSEARCH(li,100)
    print "the second method"
    biSEARCH2(li,100)
    
    
