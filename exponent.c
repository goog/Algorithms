/*
 * test.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * c programming test of winhong cup 
 * 
 * 
 */


#include <stdio.h>

long calc(long n,long p)
{
	long k=0;
	long temp;
	if(n == 0 && p!= 0) return 0;
	if(p == 0) 
	{
		if(n ) 
			return 0;
		else 
			return 1;
	}

	while(n!=1)
	{
		temp = n;
		n /= p;
		k++;
	}
	
	if(temp == p)
		return k;
	else
		return 0; 
}

int main()
{
	printf("%ld\n",calc(31,2));
	printf("%ld\n",calc(32,2));
	return 0;
}

