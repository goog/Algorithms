#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

float my_strtof(const char *str)
{

    int flag = 0;
    float result = 0;
    float factor = 1;
    char ch;

    while(ch = *str)
    {
        if(isdigit(ch))
        {
            if(flag == 1)
                factor *= 10;

            result = result*10 + ch - '0';
 
        }
        else if(ch = '.')
        {
            flag = 1;
        }
        else
        {
            printf("invalid input.\n");
            exit(EXIT_FAILURE);
        }
        
        str++;
    }


    return result/factor;


}


int main()
{

    float a = my_strtof("0.00314");
    printf("the a is %f.\n", a);

}
