#include <stdio.h>


struct S
{
    int i;
    char c;
} s;


main()
{
    printf("the struct size is %zu.\n", sizeof(*(&s)) );

}
