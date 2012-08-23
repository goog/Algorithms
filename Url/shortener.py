# -*- coding:utf-8 -*-


dict = {0:'a',1:'b',2:'c',3:'d',4:'e',5:'f',6:'g',7:'h',8:'i',9:'j',
        10:'k',11:'l',12:'m',13:'n',14:'0',15:'p',16:'q',17:'r',18:'s',19:'t',
        20:'u',21:'v',22:'w',23:'x',24:'y',25:'z',
        26:'A',27:'B',28:'C',29:'D',30:'E',31:'F',32:'G',33:'H',34:'I',35:'J',
        36:'K',37:'L',38:'M',39:'N',40:'O',41:'P',42:'Q',43:'R',44:'S',45:'T',
        46:'U',47:'V',48:'W',49:'X',50:'Y',51:'Z',
        52:'0',53:'1',54:'2',55:'3',56:'4',57:'5',58:'6',59:'7',60:'8',61:'9'}
        
def base10to62(num):
        if num == 0:
            return 0
        arr = []
        while num:
            rem = num % 62
            num = num - rem
            num = num / 62
            arr.append(rem)
        arr.reverse()
        return arr
    
def encode(num):
    # num is base 10
    list = base10to62(num)
    list= [dict.get(x) for x in list]
    return ''.join(list)

def decode(string):
    s=0
    list = [k for x in string for k, v in dict.iteritems() if v ==x]
    for i,item in enumerate(list):
        s+=item*pow(62,len(list)-1-i)
    return s

print encode(1000454354389)
print decode('rMcGF4P')
    
    



    

