/*
 * float-memory.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>

void df2b(float f, char *a)
{
	int i;
	for(i=0;i<31;i++)
	{
		f *= 2.0;
		a[i] =  ((int)f == 0 ? 0:1) +'0';
		// f equals f minus int part 
		f = f - (int)f;
		if(f == (float)0.0)
		{
			a[++i]='\0';
			break;
		}
		
	}
	a[31] = '\0';
	
}

int main()
{
	//float a =5.2;
	char s[32];
	df2b(0.2,s);
	int i;
	for(i=0;i<32;i++)
		printf("%c",s[i]);
	return 0;
}
