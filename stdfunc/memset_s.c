#include <stdio.h>

void *secure_memset(void *v, int c, size_t n)
{
    volatile unsigned char *p = v;

    while(n--)
    {
        *(p++) = c;
    }

    return v;
}


int main()
{
    char test[12] = {'a'};

    char *p = secure_memset(test, 0, sizeof(test));

    printf("the string is %s.\n", p);
}
