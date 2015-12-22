#include <stdio.h>
#include <string.h>


int get_next(char *string, int *next)
{

    next[0] = -1;
    int k;
    int j = 1;

    while(j < strlen(string))
    {
        //printf("the current j:%d\n", j);

        k = next[j-1];
        if(k == -1)
        {
            //printf("the current j @20 line:%d\n", j);
            next[j] = k + 1;
            j++;

            continue;
        }

        //printf("the current j @27:%d\n", j);
        //printf("the current k, j %d %d\n", k, j);
        if(string[k] == string[j-1])
        {
            next[j] = k + 1;

        }
        else
        {
            while ((k = next[k]) != -1)
            {
                if(string[k] == string[j-1])
                {
                    next[j] = k + 1;
                    break;
                }
            }

            if(k == -1)
            {
                next[j] = k + 1;

            }


        }

        j++;
    }

}


int main()
{

    //char *test = "ABCDABD";
    char *test = "DABCDABDE";
    int next[9];
    get_next(test, next);

    int i;
    for(i=0; i < 9; i++)
        printf("%d\t", next[i]);

    return 0;
}
