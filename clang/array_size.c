#include <stdio.h>

int main()
{

    int array[5];

    printf("the size of int is %zu.\n", sizeof(int));
    printf("the array  value is %p\n", array);
    printf("the &array value is %p\n", &array);
    printf("the 'array+1' value is %p\n", array + 1);
    printf("the '&array+1' value is %p\n", &array + 1);

    // &array + 1 : int (*)[5]
    int n = *(&array + 1) - array;
    printf("the array size is %d.\n", n);

}
