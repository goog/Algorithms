#include <stdio.h>


int main()
{

    float a = 12.5;
    int b = a;
    printf("%d\n", a);
    printf("%d\n", *((int *)&a));
    printf("the b: %d\n", b);


}
