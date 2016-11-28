#include <stdio.h>


extern int *arr;

int main()
{
    printf("the arr size is %zu.\n", sizeof(arr));

    arr[1] = 100;
    return 0;

}
