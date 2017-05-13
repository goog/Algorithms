#include <string.h>
#include <stdio.h>

int strcmp_(const char *s1, const char *s2)
{
    while(*s1 && (*s1 == *s2))
    {
        s1++, s2++;
    }

    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}




int main()
{
    int ret = strcmp(NULL, "abc");
    printf("return value is %d.\n", ret);
}
