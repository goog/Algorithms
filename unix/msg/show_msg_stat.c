/*
 * show_msg_stat.c
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
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>

#include <errno.h>


void show_msg_stat(struct msqid_ds *buf)
{
	printf("the user id = %d \n", buf->msg_perm.uid);
	printf("the access permissions  = %#o \n", buf->msg_perm.mode & 0660);
	printf("msg_ctime= %s \n", ctime(&(buf->msg_ctime)));
	
}

int main()
{
	key_t key;
	int new,msqid,msgflg;
	struct msqid_ds buf;
	printf("enter the disire key:");
	scanf("%d",&key);
	msgflg = S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP ;
	if((msqid = msgget(key,msgflg|IPC_CREAT|IPC_EXCL))> 0)
		new =1;
	else if(errno  == EEXIST)
	{	
		new =1;
		msqid = msgget(key,msgflg);
	}
	else
		exit(EXIT_FAILURE);
	// get the msq state
	if(msgctl(msqid,IPC_STAT,&buf) == -1)
	{	
		printf("error \n");
		exit(EXIT_FAILURE);
	}
	show_msg_stat(&buf);
	if(new)
		msgctl(msqid,IPC_RMID,NULL);
	return 0;
}

