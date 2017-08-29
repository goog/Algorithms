#include <stdio.h>
#include <byteswap.h>
#include <string.h>
#include <inttypes.h>

int main()
{
    float f;

    printf("please enter float:");
    printf("\nthe sizeof float and int is %d.\n", sizeof(float) == sizeof(int));
    
    scanf("%f", &f);
    printf("%%a format float: %a.\n", f);
    printf("hex is %x.\n", *(unsigned int *)(&f));

    uint32_t x;
    memcpy(&x, &f, sizeof(uint32_t));
    printf("reverted hex: %08x\n", bswap_32(x));
}
