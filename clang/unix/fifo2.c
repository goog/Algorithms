/*
 * fifo2.c
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
#include <unistd.h>
#include <limits.h>

#define FIFO_FILE ("./myfifo")
int main()
{
	int fifo_fd,n,total_bytes=0;
	// demo data :
	char writebuf[PIPE_BUF] = {'a'};
	if(access(FIFO_FILE,F_OK) == -1)
		if(mkfifo(FIFO_FILE,0666) != 0)
		{
			printf("could't creat the fifo file \n");
			exit(EXIT_FAILURE);
		}
	
	if((fifo_fd = open(FIFO_FILE,O_WRONLY)) < 0)
	{
		printf("could not open fifo file \n");
		exit(EXIT_FAILURE);
	}
	
	printf("process %d open for writing data", getpid());
	
	do
	{
		if((n = write(fifo_fd ,writebuf,PIPE_BUF)) == -1)
		{
			exit(EXIT_FAILURE);
		}
		printf("write %d bytes at process %d\n",n,getpid());
		total_bytes +=n;
	} while(total_bytes < 1000000);
	close(fifo_fd);
	printf("the process %d finished .\n", getpid());
	return 0;
}

