/*
 * checkVM.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
	struct rlimit rlt;
	getrlimit(RLIMIT_AS,&rlt);
	if(rlt.rlim_cur == RLIM_INFINITY)
	{
		printf("the virtual memory space is infinity. \n");
	}
	return 0;
}

