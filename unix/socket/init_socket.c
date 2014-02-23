#include "ch12.h"

// create sockaddr by host name and server port
void init_sockaddr(struct sockaddr_in *name, const char *hostname, const char *serv)
{
   struct hostent *hp;
   char myname[255];
   const char *host;  // const content
   if (hostname == NULL){
      gethostname(myname, sizeof(myname));
      host = myname;
   }
   else
      host = hostname;
   
   if ((hp = gethostbyname(host)) == NULL){
      printf("Unknown host: %s\n", host);
      exit(-1);
   }
   printf("the host name is %s\n",host);
   bzero(name,sizeof(struct sockaddr));  // bytes containing '\0'
   if (hp->h_addrtype == AF_INET){   
      name->sin_family = AF_INET;
      bcopy(hp->h_addr_list[0], &name->sin_addr, hp->h_length);
      if (serv == NULL)
         name->sin_port = htons(0);  // auto chose a port 
      else
         name->sin_port = htons(atoi(serv));
   } else {
      printf("Unknown address type\n");
      exit(-1);
   }
}
