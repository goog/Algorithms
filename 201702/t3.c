#include <stdio.h>
#include <string.h>

typedef union
{

int a;
char b[10];
float c;
} Union;


int main()
{
    Union x,y = {100};

    x.a = 50;
    strcpy(x.b, "hello");
    x.c = 21.5;

    printf("Union x: %d %s %f\n", x.a, x.b, x.c);
    printf("Union y: %d %s %f\n", y.a, y.b, y.c);

}
