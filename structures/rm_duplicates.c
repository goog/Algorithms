#include <stdio.h>

void printf_array(int *nums, int length)
{
    int i;

    for(i = 0; i < length; i++)
    {
        printf("%d\t", nums[i]);
    }

    printf("\n");
}


int remove_duplicates(int *nums, int length)
{
    if(nums == NULL || length == 0)
        return 0;

    int index = 0;
    for(int i = 1; i < length; i++)
    {
        printf("i:%d\t index:%d.\n", i, index);
        if(nums[index] != nums[i])
            nums[++index] = nums[i];

        printf_array(nums, length);
    }

    return index + 1;
}


int main()
{
    int test_array[3] = {1, 1, 2};

    int ret = remove_duplicates(test_array, 3);

    printf("the array size now %d.\n", ret);
}
