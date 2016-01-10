//edit by atom, 21:33 rain

#include <stdio.h>
#include <stdlib.h>


#define MAX_STATES  3

int g_state = 0;    // init state


// function for idle state and input is 0
int idle_0()
{

    printf("%s\n", "<idle state> do nothing");

    return 0;
}

int idle_1()
{

    printf("%s\n", "<idle state> goto work state");

    g_state = 2; // set state work

    return 0;
}


int (*idle_state[MAX_STATES])();

int (*idle_state[])() = {idle_0, idle_1};


int main()
{
    int ch;

    while((ch = getchar()) != '\n')
    {
        // asci 0:48   3:51
        if(ch < 48 || ch >= 51)
        {
            printf("%s\n", "parameter error.");
            continue;
        }

        switch (g_state)
        {
            case 0:
                if(g_state == 0)
                {
                    g_state = 1; // into idle state
                }

                break;

            case 1:    // idle state
                ch -= 48;

                // state process
                idle_state[ch]();
                break;

            case 2:    // work state
                break;
        }

    }

    printf("the final state is %d .\n", g_state);
    
    return 0;
}
