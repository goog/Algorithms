#include <stdio.h>

enum {false, true};


int main()
{
    int i = 1;

    printf("false %d.\n", false);
    do
    {

        printf("%d\n", i);
        i++;
        if(i < 15)
        {
            //printf("i < 15 matched.\n");
            continue;
        }

    }while(false);


    return 0;
}
