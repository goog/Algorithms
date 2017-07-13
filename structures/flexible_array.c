#include <stdio.h>
#include <stddef.h>

struct S{int F_len; double F[];};

int main()
{
    //int dd[];
    //printf("size of dd is %zu.\n", sizeof(dd));

    printf("size of struct S is %zu.\n", sizeof(struct S));

    printf("offset F_len= %zd, F=%zd \n", offsetof(struct S, F_len), offsetof(struct S, F));
}
