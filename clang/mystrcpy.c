/*
 * mystrcpy.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>
#include <assert.h>

char *mystrcpy(char *des, const char *src)
{
	assert(des != NULL && src != NULL);
	char *re = des;
	while((*des++ = *src++));
	*des = '\0';
	return re;
	
}

int main()
{
	char a[10] = "Hi,google";
	char b[10];
	mystrcpy(b,a);
	printf("the copy string is %s \n",b);
	printf("%s \n",mystrcpy(b,a));
	printf("%zu",sizeof(a));
	return 0;
}

