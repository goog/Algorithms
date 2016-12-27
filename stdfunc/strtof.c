#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


float stof(const char *s)
{
    
    int sign = 1;

    long double factor = 0.1f;
    int seen_dot = 0;
    int single_val = 0;
    long double result = 0;
    int int_res = 0;
    char ch;

    while(*s)
    {

        ch = *s;
        printf("char: %c\n", ch);

        if(ch == '-')
        {
            sign = -1;
        }
        else if(ch == '.')
        {
            seen_dot = 1;
            factor = 1.0f;

            int_res = result;  // save the integer result
            result = 0;
        }
        else if(isdigit(ch))
        {
            single_val = ch - '0';

            if(seen_dot == 1)  // float part
            {
                factor /= 10.0f;
                result = result + single_val * factor;
            }
            else
            {
                // for integer part
                factor *= 10;
                result = result * factor + single_val;
            }
            
            printf("the current factor is %Lf.\n", factor);

        }
        else
        {
            perror("Invalid input");
            exit(EXIT_FAILURE);
        }

        s++;
    }


    return sign * (int_res + result);
}



int main()
{
    char *str = "-32.141592653";
    printf("the result is %f.\n", stof(str)); // custom
    printf("the result is %f.\n", strtof(str, NULL));

}
