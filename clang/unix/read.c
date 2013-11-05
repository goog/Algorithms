/*
 * read.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>
#include <unistd.h> 

int main()
{
	char buf[BUFSIZ];
	printf("The buffer size is %d\n",BUFSIZ);
	int n;
	while((n = read(0,buf,BUFSIZ)) > 0)
		write(1,buf,n);
		
	return 0;
}

