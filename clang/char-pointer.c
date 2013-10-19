/*
 * char-pointer.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>
#include <malloc.h>


int main()
{
	char *buf = malloc(1024);
	size_t howManyBytes = malloc_usable_size(buf);
	printf("Allocated %u bytes\n", (unsigned)howManyBytes);
	return 0;
}

