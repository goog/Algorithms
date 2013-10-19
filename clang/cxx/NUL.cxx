/*
 * NUL.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


using namespace std;
#include <iostream>
#include <malloc.h>

#define NUL ((void *) 0)


int main()
{
	int *i = NUL;
	char *p = NUL;
	i = (int *) malloc(sizeof(int));
	*i =10;
	
	p = (char *) malloc(sizeof(char));
	*p = 'A';
	
	cout <<  *(&(*i)) << " " << *(&(*i)) << endl;
	return 0;
}

