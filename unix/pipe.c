#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include <sys/types.h>

// 父进程通往子进程的管道；

int main()
{
	pid_t pid;
	int n,mypipe[2];
	char buffer[BUFSIZ+1],some_data[] = "Hello world!";
	
	// create pipe 
	if(pipe(mypipe))
		{
			printf("error happended.\n");
			exit(0);
		}
		
	if((pid = fork()) == (pid_t) 0)
	{
		close(mypipe[1]); // close subprocess out direction
		n = read(mypipe[0],buffer,BUFSIZ);
		printf("child %d read %d bytes:%s \n",getpid(),n, buffer);
		
	}
	
	else
	{
		close(mypipe[0]);
		n = write(mypipe[1],some_data,strlen(some_data));
		printf("parent process %d write %d bytes: %s \n",getpid(),n,some_data);	
	}
	exit(EXIT_SUCCESS);
}
