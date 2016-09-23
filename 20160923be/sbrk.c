#include <stdio.h>
#include <unistd.h>

int main()
{
    int *p0 = sbrk(0);
    // 打印堆地址
    printf("this site of p0 is : %d\n", p0);

    int *p1 = sbrk(1000);
    // 打印堆地址
    printf("this site of p1 is : %d\n", p1);


    int *p2 = sbrk(1);
    // 打印堆地址
    printf("this site of p2 is : %d\n", p2);

    int *p3 = sbrk(-1001);
    // 打印堆地址
    printf("this site of p3 is : %d\n", p3);

    p0 = sbrk(0);
    // 打印堆地址
    printf("this site of p0 is : %d\n", p0);

    return 0;

}
