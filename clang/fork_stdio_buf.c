#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/*
test cmd: ./fork_stdio_buf > aa

*/

int main()
{

    printf("hello you\n");
    write(STDOUT_FILENO, "Cian\n", 5);

    if(fork() == -1)
    {
        printf("fork error\n");
        exit(-1);
    }

    //

    //exit(EXIT_SUCCESS);
}
