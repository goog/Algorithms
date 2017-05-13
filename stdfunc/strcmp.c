#include <stdio.h>


int strcmp(const char *str1, const char *str2)
{

    if(str1 == NULL && str2 == NULL)
    {
        return 0;
    }
    else if(str1 == NULL)
    {
        return -1;
    }
    else if(str2 == NULL)
    {
        return 1;
    }

    while(*str1 && *str2)
    {
        #if 0
        if(*str1 > *str2)
            return 1;
        else if(*str1 < *str2)
            return -1;
        #endif
        if(*str1 != *str2)
        {
            break;
        }

        str1++, str2++;
    }

    return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}


int main()
{
    if(strcmp("abc", "ab") == 1)
        printf("it is true.\n");

}
