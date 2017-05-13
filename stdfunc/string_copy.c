#include <stdio.h>


char *strcpy(char *dest, const char *src)
{

    if(dest == NULL || src == NULL)
    {
        return NULL;
    }

    char *dest_copy = dest;

    while(*src)
    {
        *dest = *src;
        dest++;
        src++;

    }

    return dest_copy;
}



int main()
{
    char dst[100];
    char src[] = "abcd";

    strcpy(dst, NULL);
    printf("the second strcpy begins.\n");
    printf("%s\n", strcpy(dst, src));

}
