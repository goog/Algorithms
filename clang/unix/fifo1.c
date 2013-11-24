/*
 * fifo1.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <limits.h>
#include <unistd.h>

#define FIFO_FILE ("./myfifo")
int main()
{
	int fifo_fd,n,total_bytes = 0;
	char readbuf[PIPE_BUF];
	
	if(access(FIFO_FILE,F_OK) == -1)
		if(mkfifo(FIFO_FILE,0666) != 0)
		{
			printf("could't creat the fifo file \n");
			exit(EXIT_FAILURE);
		}
	
	if((fifo_fd = open(FIFO_FILE,O_RDONLY)) < 0)
	{
		printf("could not open fifo file \n");
		exit(EXIT_FAILURE);
	}
	
	printf("process %d open ", getpid());
	while((n = read(fifo_fd ,readbuf,PIPE_BUF)) > 0)
	{
		printf("received %d bytes at process %d\n",n,getpid());
		total_bytes +=n;
	}
	printf("totally received bytes is %d \n", total_bytes);
	close(fifo_fd);
	return 0;
}

