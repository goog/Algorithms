#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{

    int file_desc = open("./test.txt", O_CREAT | O_EXCL);
    if(file_desc < 0)
    {
        perror("open");
        return -1;
    }

}
