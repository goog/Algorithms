#include "ch12.h"
#include "make_socket.c"

#define LISTENQ 5
#define MAXLINE 512

int main(int argc, char ** argv )
{
	int listenfd, connfd;
	socklen_t len;
	struct sockaddr_in cliaddr;
	char buf[MAXLINE];
	time_t ticks;
	
	listenfd = make_socket(SOCK_STREAM, 5013);
	listen(listenfd,LISTENQ);
	
	for(;;)
	{
		len = sizeof cliaddr;
		connfd = accept(listenfd,(struct sockaddr *) &cliaddr, &len);
		printf("client ip is %s ", inet_ntoa((struct in_addr) cliaddr.sin_addr));
		ticks = time(NULL);
		sprintf(buf, "%.24s \n",ctime(&ticks));
		write(connfd,buf,strlen(buf)); // send data to client
		close(connfd);
		
	}	
}
