/*
 * bigendian.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */



#include <stdio.h>
#include <inttypes.h>


char is_big_endian(void)
{
    //union {
        //uint32_t i;
        //char c[4];
    //} bint = {0x01020304};
    
    unsigned int i = 0x01020304;
    char *p = (char *) &i;
    printf("%p\n",&i);
    printf("%p\n",p);
    printf("%d\n", *(p + 3));
    return *p;

    //return bint.c[0] == 1;
}

int main()
{
	printf("%d",is_big_endian());
	return 0;
}

