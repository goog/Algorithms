#include <stdlib.h>
#include <stdio.h>


main()
{

    char a = 0;
    short int b = 0;

    size_t size_short_int = sizeof(b);
    size_t size_int = sizeof(a + b);

    printf("the short int size: %zu.\n", size_short_int);
    printf("the int size: %zu.\n", size_int);
    //if(sa == sb)
    //    printf("two sizes are equal.\n");

}
