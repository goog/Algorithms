/*
 * sharememory.c
 * 
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#define SHMSIZ 32

int main()
{
	char c, *shm, *s;
	int shmid;
	if( (shmid = shmget(785,SHMSIZ,IPC_CREAT|0666)) < 0)
	{
		printf("shmget failed .\n");
		exit(EXIT_FAILURE);
	}
	
	//连接共享存储段至进程的数据空间， 0 读写方式连接
	if((shm = shmat(shmid,NULL,0)) == (char *) -1)
	{exit(-1);}
	
	s= shm;
	for(c='a';c<='z';c++) 
		*s++ = c;
	*s = '\0';
	return 0;
}

