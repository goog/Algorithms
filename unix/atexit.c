/*
 * atexit.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>


static void func_1(void)
{
	printf("invoked the first function.\n");
	
}


static void func_2(void)
{
	printf("invoked the second function.\n");
	
}

int main()
{
	if(atexit(func_1) != 0)
	{
		printf("error : atexit() register the function one .\n");
		exit(EXIT_FAILURE);		
	}
	
	if(atexit(func_2) != 0)
	{
		printf("error : atexit() register the function two .\n");
		exit(EXIT_FAILURE);		
	}
	printf("main : exit normally \n");
	return 0;
}

