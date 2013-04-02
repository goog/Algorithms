def biSEARCH(li,key):
    mid = len(li)/2
    if key == li[mid]:
        print "find it"
    elif key < li[mid]:
        biSEARCH(li[:mid],key)
    else:
        biSEARCH(li[mid+1:],key)

if __name__=="__main__":
    li = [1,3,4,5,7,8,90,100]
    biSEARCH(li,100)
    
