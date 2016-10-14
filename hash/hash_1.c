#include <stdio.h>
#include <stdlib.h>


/*
static unsigned long
sdbm(str)
unsigned char *str;
*/
static unsigned long
sdbm(unsigned char *str)
{
    unsigned long hash = 0;
    int c;

    while (c = *str++)
        hash = c + (hash << 6) + (hash << 16) - hash;

    return hash;
}


int 
plus(a, b)
int a, b;
{
    printf("inputs are: %d, %d.\n", a ,b);
    return a + b;
}

// djb2
unsigned long
hash_djb2(unsigned char *str)
{
    unsigned int hash = 5183;
    int c;

    while(c = *str++)
    {
        hash = ((hash << 5) + hash) + c;
        // hash = 33*hash + c;
    }

    return hash;
}

int
main()
{

    unsigned long hash1 = hash_djb2("abcdef");
    printf("the hash value is %ld.\n", hash1);

    unsigned long hash2 = sdbm("abcdef");
    printf("the hash value is %ld.\n", hash2);

    int c = plus(12, 34);
    printf("the plus function result:%d.\n", c);
}
