// spring 20160207
#include <stdio.h>
#include <limits.h>

int get_max_and_min(int *p, int length, int *max, int *min)
{
    // suppose
    int max_value = INT_MIN;
    int min_value = INT_MAX;

    int i;
    int flag = length % 2;

    for(i = 0; i < length/2; i++)
    {
        if(*(p + i) > *(p + i + 1))
        {
            if(*(p + i) > max_value)
            {
                max_value = *(p + i); // update the max value
            }

            if(*(p + i + 1) < min_value)
            {
                min_value = *(p + i + 1);
            }

        }
        else
        {
            if(*(p + i + 1) > max_value)
            {
                max_value = *(p + i + 1);
            }

            if(*(p + i) < min_value)
            {
                min_value = *(p + i);
            }

        }


    }

    if(flag)  // odd length array, the last element
    {
        if(*(p + length - 1) > max_value)
            max_value = *(p + length - 1);

        if(*(p + length - 1) < min_value)
            min_value = *(p + length - 1);
    }

    *max = max_value;
    *min = min_value;

    return 0;
}



int main()
{

    int array[6] = {23, 12, 45, 2016, 2, 15};

    int max, min;
    get_max_and_min(array, 6, &max, &min);

    printf("the max %d, min %d.\n", max, min);

    int array1[] = {23};

    //int max, min;
    get_max_and_min(array, 1, &max, &min);

    printf("the max %d, min %d.\n", max, min);

    return 0;
}
