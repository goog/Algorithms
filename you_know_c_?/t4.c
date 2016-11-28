#include <stdio.h>


main()
{

    int i = 16;

    int result = (((i >= i) << i) >> i) <= i ;
    printf("the result is %d.\n", result);

}
