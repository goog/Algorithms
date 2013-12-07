/*
 * alllist.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>

void alllist(char *number,int n,int index)
{
	int i;
	if(index == n-1)
		{
		printf("%s\n",number);
		return;
		}
		
	for(i=0;i<10;i++)
	{
		number[index+1] = i +'0';
		alllist(number,n,index+1);
	}
}

void allsort(int n)
{
	int i;
	if(n <= 0)
		return;
	char * number = malloc(sizeof(n+1));
	number[n] = '\0';
	for(i=0;i<10;i++)
	{
		number[0] = i +'0';
		alllist(number,n,0);
	}
	
	free(number);
	number = NULL;
}




int main()
{
	allsort(2);
	return 0;
}

