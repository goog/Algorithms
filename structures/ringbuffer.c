#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int DATA_T;


int rb_full();
int rb_empty();

static int capacity = 10;
volatile unsigned int read = 0;
volatile unsigned int write = 0;



DATA_T *rb_init(unsigned int num)
{
    capacity = num;

    return calloc(num, sizeof(DATA_T));
}


unsigned int rb_mask(unsigned int val)
{
    return val % capacity;
}


int rb_push(DATA_T *array, DATA_T *val)
{
    if(rb_full())
        return -1;

    memcpy(&array[rb_mask(write++)], val, sizeof(DATA_T));
    
    return 0;
}



int rb_shift(DATA_T *array, DATA_T *result)
{
    if(rb_empty())
        return -1;

    memcpy(result, &array[rb_mask(read++)], sizeof(DATA_T));

    return 0;
}


int rb_full()
{
    return (read - write) == capacity;
}

int rb_empty()
{
    return read == write;
}

int rb_size()
{
    return write - read;
}


int main()
{

    int test_array[12] = {12};

    DATA_T *ring = rb_init(10);
    if(ring == NULL)
        return -1;

    int i;
    for(i=0; i < 10; i++)
    {
        rb_push(ring, &test_array[i]);
    }

    printf("the ring buffer size is %d.\n", rb_size());

    test_array[0] = 12;
    test_array[1] = 24;

    int a, b;
    rb_shift(test_array, &a);
    rb_shift(test_array, &b);
    
    printf("the shift value is %d.\n", a);
    printf("the shift value is %d.\n", b);
    
    printf("size now is %d.\n", rb_size());
    printf("the write is %d.\n", write);
    printf("the read is %d.\n", read);

    rb_push(ring, (int []){2016});
    printf("the write is %d.\n", write);
    printf("the read is %d.\n", read);
    
    free(ring);
}
