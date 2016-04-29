#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    struct ifaddrs *ifaddr, *ifa;
    int family, s;
    char host[NI_MAXHOST];
    int flag = 0;

    if(argc > 2)
    {
        printf("too much parameter error.\n");
        return -1;
    }

    if(getifaddrs(&ifaddr) == -1)
    {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }


    for(ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next)
    {
        if(ifa->ifa_addr == NULL)
            continue;

        s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);

        if(argc == 1)
        {
            if((strcmp(ifa->ifa_name,"eth0")==0) && (ifa->ifa_addr->sa_family==AF_INET))
            {
                if(s != 0)
                {
                    printf("getnameinfo() failed: %s\n", gai_strerror(s));
                    exit(EXIT_FAILURE);
                }
                printf("%s\t%s\n",ifa->ifa_name, host);

                flag = 1;
                break;
            }

        }
        else
        {
            if((strcmp(ifa->ifa_name, argv[1]) == 0) && (ifa->ifa_addr->sa_family==AF_INET))
            {
                if(s != 0)
                {
                    printf("getnameinfo() failed: %s\n", gai_strerror(s));
                    exit(EXIT_FAILURE);
                }
                printf("%s\t%s\n",ifa->ifa_name, host);

                flag = 1;
                break;
            }
        }

    }

    if(flag == 0)
    {
        printf("interface not exist.\n");
    }

    freeifaddrs(ifaddr);
    exit(EXIT_SUCCESS);
}
