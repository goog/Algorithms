#include <stdio.h>


int main()
{
    int array[10];

    printf("the array is %p.\n", array);
    printf("the &array is %p.\n", &array);
    printf("the &(array[0]) is %p.\n", &(array[0]));

}
