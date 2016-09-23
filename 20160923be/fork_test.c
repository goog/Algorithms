#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
   int i;
   for(i=0; i<2; i++){
      fork();
      printf("-");
      //printf("ppid=%d, pid=%d, i=%d \n", getppid(), getpid(), i);

   }

   //wait(NULL);
   //wait(NULL);
   sleep(1);

   return 0;
}
