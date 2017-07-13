#include <stdio.h>
#include <string.h>

// declare that arg is never null
int string_length(char arg[static 10])
{
    //printf("%s begins.\n", __FUNCTION__);
    return 2;  //fake value
}


int main()
{

    char test[10] = "abcd";
    char test2[3] = "ab";

    printf("the test length is %d.\n", string_length(test));
    printf("the test2 length is %d.\n", string_length(test2));
    printf("the null length is %d.\n", string_length(NULL));

}
