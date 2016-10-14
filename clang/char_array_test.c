#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char myname[256] = "chengjay";


    printf("myname string length: %ld.\n", strlen(myname));

    char *p = myname;

    while(*p)
    {

        printf("%c\t", *p);
        p++;
    }

    printf("\n");
    
}
