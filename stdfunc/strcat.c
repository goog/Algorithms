#include <stdio.h>


char *strcat(char *dest, const char *src)
{
    char *save = dest;
    while(*dest != '\0') dest++;

    //strcpy(dest, src);
    while(*dest++ = *src++);
    *dest = '\0';
    
    return save;
}


int main()
{

    char str1[12] = "h4h";
    char *str2 = "lab";

    strcat(str1, str2);
    printf("the string 1 is %s\n", str1);

    strcat(str1, "test the long string");
    printf("the string 1 is %s.\n", str1);

    printf("end.\n");
}
