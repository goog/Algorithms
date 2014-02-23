#include "ch12.h"
#include "socket_connect.c"  // socket_connect()

#define  MAXBUFFSIZE    256
int main(int argc, char **argv)
{
   int sockfd, n;
   char recvbuff[MAXBUFFSIZE];
   sockfd = socket_connect(NULL,"5013");
   write(sockfd,argv[1], sizeof argv[1]);
   n = read(sockfd,recvbuff,sizeof recvbuff);
   recvbuff[n] = 0;
   printf("string from server is %s \n", recvbuff);
   close(sockfd);
   exit(0);
}
