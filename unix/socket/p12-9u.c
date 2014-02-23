//#include "ch12.h"
#include "socket_connect.c"  // socket_connect()
#define  MAXBUFFSIZE    256
int main(int argc, char **argv)
{
   int sockfd, n;
   char recvbuff[MAXBUFFSIZE], *host;
   
   if(argc < 2)
      host = NULL;
   else
      host = argv[1]; 
   sockfd = socket_connect(host,"5013");
   /* 读服务的回答并显示结果 */
   while((n = read(sockfd,recvbuff,MAXBUFFSIZE)) > 0)
   {
      recvbuff[n] = 0;
      fputs(recvbuff,stdout);  // output
   }
   if(n<0)
      err_exit("read error");
   exit(0);
}
