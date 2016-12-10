#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    long tid;

    tid = syscall(SYS_gettid);
    printf("%ld\n", tid);

    //printf("The tid is %d.\n", gettid());
    return EXIT_SUCCESS;
}
