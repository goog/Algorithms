#include <setjmp.h>
#include <stdio.h>

jmp_buf buf;


banana()
{
    printf("in banana function.\n");
    longjmp(buf, 1);

    printf("you will never see this because i longjmp'd");
}



int main()
{
    int ret;

    if(setjmp(buf))
    {
        printf("back in main.\n");
    }
    else
    {
        printf("first time through\n");
        banana();
    }

}
