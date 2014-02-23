#include "ch12.h"
#include "make_socket.c"

#define LISTENQ 5
#define MAXLINE 255
void doit(int client_sockfd);

int main(int argc, char ** argv)
{
	int server_sockfd, client_sockfd;
	socklen_t client_len;
	struct sockaddr_in cliaddr;
	server_sockfd = make_socket(SOCK_STREAM, 5013);
	listen(server_sockfd,LISTENQ);
	signal(SIGCHLD,SIG_IGN);
	
	while(1)
	{
		printf("server waitting \n");
		client_len = sizeof cliaddr;
		client_sockfd = accept(server_sockfd,(struct sockaddr *) &cliaddr, &client_len);
		if(fork() == 0) // create subprocess
		{
			close(server_sockfd);
			doit(client_sockfd);
			close(client_sockfd);
			exit(0); // terminal subprocess 
		}
		
		else
			close(client_sockfd);
	}	
}

void doit(int client_sockfd)
{
	char buf[MAXLINE];
	int n;
	n = read(client_sockfd,buf,sizeof(buf));
	buf[n] = 0;
	sleep(1); // simulate server time
	write(client_sockfd,buf,n); // send data to client
}
