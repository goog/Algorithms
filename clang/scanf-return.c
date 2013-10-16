/*
 * 
 * 
 * 
 * 
 */
#include<stdio.h>
#include<stdlib.h>

void main(void)
{
	char c1,c2,c3;
	// check the number of successful conversion
	if (scanf("%c%c%c%",&c1,&c2,&c3) !=3)
	{
		printf("the length of input parameters must be three.\n");
		exit(1);
	}
	else
		printf("%c,%c,%c.",c1,c2,c3);
	
	
	
}


// input ABC 3 55 77.7
