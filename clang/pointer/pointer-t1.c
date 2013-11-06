/*
 * pointer-t1.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>

int main()
{
	int a[5] = {1,2,3,4,5};
    // a++;  error
    printf("%p,%p,%p\n",&a[0],&a[1],&a[4]);
    printf("The address of &a +1 is %p\n",&a+1); // &a is a pointer to an array .
    int *ptr = (int*)(&a+1);
    printf("%d %d",*(a+1),*(ptr-1));
	return 0;
}

