#include <stdio.h>

void swap_two_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}



int partition(int *array, int start, int end)
{
    int x = array[start];

    int i = start;
    int j;

    for(j = start + 1; j <= end; j++)
    {

        if(array[j] < x)
        {
            i++;  // record the pivot position
            swap_two_int(&array[j], &array[i]);
        }
    }

    swap_two_int(&array[start], &array[i]);

    return i;
}


void quicksort(int *array, int start, int end)
{
    if(array == NULL)
        return;

    if(start < end)
    {
        int index = partition(array, start, end);

        quicksort(array, start, index - 1);
        quicksort(array, index + 1, end);
    }

}


int main()
{
    int test[] = {2, 1, 5, 9};

    quicksort(test, 0, 3);

    int i;

    for(i=0; i < 4; i++)
    {
        printf("%d\t", test[i]);
    }

    printf("\n");

    return 0;
}
