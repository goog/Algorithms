/*
 * fork-base.c
 * 
 * 
 * 
 */


#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(void)
{
	int fork(void),value;
	// there are four processes.
	value = fork();
	value = fork();
	sleep(20); // pstree | grep fork
	return 0;
}

