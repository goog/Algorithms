/*
 * read.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */



#include <unistd.h>
#define EOF (-1)

int getchar(void)
{
	char c;
	return (read(0,&c,1)) == 1 ? (unsigned char) c : EOF;
}

int main(void)
{
	
	char a;
	a = getchar(); // Ctrl + D cause an EOF
	printf("\nthe input character is:%c",a);
	
	return 0;
}

