#include <stdio.h>

int main()
{
    int apricot[2][3][5];
    int (*r)[5] = apricot[0];
    int *t = apricot[0][0];

    printf("int size %zu.\n", sizeof(int));

    printf("r is %p.\n", r);
    printf("t is %p.\n", t);
    printf("r + 1 is %p.\n", ++r);
    printf("t + 1 is %p.\n", ++t);
}
