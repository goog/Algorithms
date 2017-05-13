#include <stdio.h>

void swap(int *p, int id1, int id2)
{
    int temp = *(p + id1);
    *(p + id1) = *(p + id2);
    *(p + id2) = temp;
}


void quicksort(int *p, int low, int high)
{
    int i;

    if(low < high)
    {
        int storeId = low;

        for(i = low + 1; i <= high; i++)
        {
            if(p[i] < p[low])
            {
                swap(p, i, ++storeId);
            }

        }
    
        
        swap(p, low, storeId);

        quicksort(p, low, storeId - 1);
        quicksort(p, storeId + 1, high);

    }
}





int main()
{
    int i;

    int test_array[] = {12, 3, 4, 8, 7, 6, 1001};

    quicksort(test_array, 0, 6);

    for(i= 0; i < 7; i++)
    {

        printf("%d\t", test_array[i]);
    }

    printf("\n");
}
