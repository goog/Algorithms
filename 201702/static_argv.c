#include <string.h>
#include <stdio.h>

// declare that arg is never null
int string_length(char arg[static 10])
{
    return strlen(arg);
}


int main()
{

    char test[10] = "abcd";
    char test2[3] = "ab";

    printf("the 1st length is %d.\n", string_length(test));
    printf("the 2st length is %d.\n", string_length(test2));
    printf("the null length is %d.\n", string_length(NULL));

}
