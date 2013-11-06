/*
 * pointer-t1.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>

void f(char **);

int main()
{
	char *argv[] = {"ab","cd","ef","gh","ij","kl"};
    f(argv);
	return 0;
}

void f(char **p)
{
    char *t;
    t = (p += sizeof(int))[-1]; // p -> p[4]; p[-1] = *(p-1)
    printf("%s",t);
    
}

