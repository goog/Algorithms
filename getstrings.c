#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>


void get_strings(const char *in)
{
    if(in == NULL)
    {
        printf("parameter is null for function %s.\n", __FUNCTION__);
        return;
    }

    char *cmd;
    asprintf(&cmd, "strings %s", in);
    printf("cmd: %s.\n", cmd);

    if(system(cmd))
        fprintf(stderr, "some thing went wrong when running %s.\n", cmd);

    free(cmd);
}


int main(int argc, char **argv)
{
    get_strings(argv[1]);
}
