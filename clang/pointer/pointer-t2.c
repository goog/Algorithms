#include <stdio.h>

void f(char **);

int main()
{
    char *argv[] = {"ab","cd","ef","gh","ij","kl"};
    f(argv);

}

void f(char **p)
{
    char *t;
    t = (p += sizeof(int))[-1]; // p -> p[4]; p[-1] = *(p-1)
    printf("%s",t);
    
}

