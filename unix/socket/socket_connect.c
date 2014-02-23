#include "init_socket.c"

int socket_connect(char *hostname, char * serv_port)
{
	int sockfd;
	struct sockaddr_in saddr;
	
	init_sockaddr(&saddr, hostname, serv_port);
	if((sockfd = socket(AF_INET,SOCK_STREAM, 0)) < 0)
		err_exit("socket error");
	if(connect(sockfd, (struct sockaddr *) &saddr, sizeof(saddr)) < 0) // connect to server 
		err_exit("connect error");
	return sockfd;

}
