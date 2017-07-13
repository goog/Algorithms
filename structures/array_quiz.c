#include <stdio.h>

int main()
{
    char buf[32];
    printf("%d.\n", (unsigned int)(buf + 1) - (unsigned int)buf);
}
