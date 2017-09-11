#include <stdio.h>

int main()
{

    short int a = 0x1234;
    unsigned char x0, x1;

    
    unsigned char *ap = (unsigned char *) &a;
    x0 = ap[0], x1 = ap[1];    // x0 low address x1 high address

    if(x0 == 0x34 && x1 == 0x12)
        printf("its little endian.\n");
    else
        printf("its big endian.\n");

}
