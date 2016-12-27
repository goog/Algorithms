#include <stdio.h>
#include <string.h>


char *strcat(char *dest, const char *src)
{
    while(*dest != '\0') dest++;

    strcpy(dest, src);
    
    return dest;
}


int main()
{

    char str1[12] = "h4h";
    char *str2 = "lab";

    strcat(str1, str2);
    printf("the string 1 is %s, length is %zu.\n", str1, strlen(str1));

    strcat(str1, "test the long string");
    printf("the string 1 is %s.\n", str1);

    printf("end.\n");
}
