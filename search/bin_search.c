#include <assert.h>
#include <stdio.h>

int bin_search(int *a, int length, int value)
{
    int mid, low, high;

    assert(length > 0);

    low = 0;
    high = length -1;

    while(low <= high)
    {

        //mid = (low + high) / 2;
        mid = low + ((high - low) >> 1);

        if(a[mid] == value)
        {
            return mid;
        }
        else if(a[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }

    }


    return -1;
}


int main()
{
    int array[] = {1, 16, 24, 35, 47, 59, 62, 73, 88, 99};
    int index = bin_search(array, 10, 62);

    printf("the index is %d\n", index);
}
