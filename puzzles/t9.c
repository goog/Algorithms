#include <stdio.h>


int main()
{

    float f = 0.0f;
    int i;

    for(i = 0; i < 10; i++)
        f = f + 0.1f;

    printf("the f is %f.\n", f);
    printf("the 1.0f is %f.\n", 1.0f);

    if(f == 1.0f)
        printf("f is 1.0 \n");
    else
        printf("f is not 1.0 \n");

    //if(abs(f - 1.0f) < 0.2)
    //    printf("f is 1.0 \n");
    if(fabsf( f - 1.0f ) <= 0.0001)
        printf("the f is 1.0f.\n");

}
