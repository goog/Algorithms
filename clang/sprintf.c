/*
 * sprintf.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	char *sig_url = malloc(10+2);  //2
	sprintf(sig_url,"%s?%s","hello", "world");
	printf("%s ,%ld\n",sig_url,strlen(sig_url));
	return 0;
}

