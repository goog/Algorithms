/*
 * coverload.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>

/*
int (*func)(void);


int func1(void)  
{  
    int i = 1;  
    return i;  
}
    
int func2(void)  
{  
    int i = 2;  
    return i;  
} 



int main()
{  
    int (*func)(void); 
    
    int i = 0;  
    if( i == 0 )   
		func = func1;   
    else   
		func = func2;
	 
    i = func();    // func1 is applied.
    printf("%d",i);
    
    return 0;
}
*/


int (*func)(void);   
    
int func1(void)  
{  
    int i = 1;  
    return i;  
}  
    
    
int func2(void)  
{  
    int i = 2;  
    return i;  
}  
    
int main()
{  
    int (*P[2])(void)={func1,func2};
    int i = 0; 
    i = (*P[0])();  
    printf("%d",i);
} 

