#include <stdio.h>

struct test
{
    int a;
    double b;

    union 
    {
        int c;
        char name[10];
    } x;

};


int main()
{
    struct test bb;
    //printf("the size of double is %zu.\n", sizeof(double));
    printf("the size of union is %zu.\n", sizeof(bb.x));

    printf("the size of struct test is %zu.\n", sizeof(struct test));

}
