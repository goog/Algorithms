#include "ch12.h"
#include <sys/un.h>

int make_un_socket(int type, const char *filename)
{
	struct sockaddr_un name;
	int sock;
	socklen_t size;
	sock = socket(AF_UNIX, type, 0);  // create socket
	if(sock < 0)
		err_exit("socket");
	name.sun_family = AF_UNIX;
	strcpy(name.sun_path,filename);
	size = sizeof(struct sockaddr_un) +1;
	if( bind(sock, (struct sockaddr *)&name,size) < 0)  // bind to a file
		err_exit("bind");
	return sock;
}
