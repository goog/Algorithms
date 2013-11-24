/*
 * receive.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */

#include "p11-7.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>


int main()
{
	int running =1,msgid;
	struct my_msg msgbuf;
	long int msg_type = -57;
	
	if((msgid = msgget((key_t)1234,0666|IPC_CREAT)) == -1)
		exit(EXIT_FAILURE);
		
	while(running)
	{
		if(msgrcv(msgid,(void *) &msgbuf,BUFSIZ,msg_type,IPC_NOWAIT) != -1)
			printf("you have received %s ",msgbuf.text);
		else if(errno == ENOMSG && msgrcv(msgid,(void *) &msgbuf,BUFSIZ,0,0) != -1) 
			printf("you have received %s ",msgbuf.text);
		else
		{
			printf("received  failed . \n"); 
			exit(EXIT_FAILURE);
		}
		
		if(strncmp(msgbuf.text,"end",3) == 0)
			break;
		
	}
	
	if(msgctl(msgid,IPC_RMID,0) == -1)
	{
		printf("msgctl error \n .");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

