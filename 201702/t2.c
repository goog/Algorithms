#include <stdio.h>

#define PRINT(EXPR)  printf(#EXPR "=%d\n", EXPR)

int main()
{
    PRINT(5+6*7);
}
