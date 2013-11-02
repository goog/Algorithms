/*
 * 2d-array.c
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
	int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
	
	// output a[2][1]
	printf("the address of a[1] is %p and a[2] is %p \n",a[1],a[2]);
	printf("%d\n",*(a[2] + 0));  // a[2] is a pointer to an array with four elements;
	printf("%d\n",*(a[2] + 1));
	printf("%d\n",*(a[2] + 2));
	printf("%d\n",*(a[2] + 3));
	
	// array size 
	printf("%zu \n",sizeof(*(a+2)));
	printf("%d\n",(*(a+2))[1]);
	printf("%d\n",*((*(a+2)) +1));
	return 0;
}

