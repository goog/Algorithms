#include "ch12.h"

int main()
{
	int stayopen =1;
	struct servent *sp;
	setservent(stayopen);  // always open servent database
	while(1)
	{
		sp = getservent();
		if(sp)
			printf("server name = %12s port = %6d proto = %4s\n", sp->s_name, ntohs(sp->s_port), sp->s_proto);
		else
			break;
	}
	endservent();
	
	sp = getservbyname("telnet","tcp");
	if(sp != (struct servent *) 0)
		printf("server name = %12s port = %6d proto = %4s\n", sp->s_name, ntohs(sp->s_port), sp->s_proto);
	else
		printf("there is no telnet .\n");

	return 0;
}
