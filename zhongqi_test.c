#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[], char *envp[])
{
    int a[0];
    
    int i = 0;
    while(envp[i++])
        printf("%s \n", envp[i - 1]);
    

    printf("the size of a[0] is %ld.\n", sizeof(a));
}
