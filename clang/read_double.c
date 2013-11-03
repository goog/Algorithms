/*
 * read_double.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	double d;
	printf("Input a double number:\n");
	scanf("%lf", &d);
	printf ("%f", d);
	return 0;
}

