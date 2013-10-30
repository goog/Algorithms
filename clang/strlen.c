/*
 * strlen.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("%zu \n",strlen("\t"));
	printf("%zu \n",strlen("\n\r"));
	return 0;
}
