#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "node.h"



node *create_link_list_by_array(int *array, int size)
{

    node *head = NULL;
    node *p_node, *prev;
    int i;

    for(i=0; i < size; i++)
    {
        if(i == 0)
        {
            p_node = (node *)calloc(sizeof(node), 1);
            if(p_node == NULL)
            {
                return NULL;
            }

            p_node->val = array[i];
            p_node->next = NULL;
            
            head = p_node;
            prev = p_node;
        }
        else
        {
            p_node = (node *)calloc(sizeof(node), 1);
            if(p_node == NULL)
            {
                printf("calloc failed.\n");
                return head;
            }

            p_node->val = array[i];
            p_node->next = NULL;

            prev->next = p_node;
            prev = p_node;
        }



    }


    return head;
}


void print_link_list(node *head)
{
    node *p;

    for(p = head; p != NULL; p = p->next)
    {
        printf("%d\t", p->val);
        fflush(stdout);
        #if 0
        sleep(1);
        #endif
    }

    printf("\n");
}



node *create_loop_link_list_by_array(int *array, int size)
{

    node *head = NULL;
    node *p_node, *prev;
    node *p2;
    int i;

    if(size < 4)
    {
        printf("we are building a loop link list, size must bigger than 4.\n");
        exit(EXIT_FAILURE);
    }

    for(i=0; i < size; i++)
    {
        if(i == 0)
        {
            p_node = (node *)calloc(sizeof(node), 1);
            if(p_node == NULL)
            {
                return NULL;
            }

            p_node->val = array[i];
            p_node->next = NULL;
            
            head = p_node;
            prev = p_node;
        }
        else
        {
            p_node = (node *)calloc(sizeof(node), 1);
            if(p_node == NULL)
            {
                printf("calloc failed.\n");
                return head;
            }

            
            if(i ==2)
            {
                p2 = p_node;
                //printf("p2 value is %d.\n", p2->val);
            }
            
            p_node->val = array[i];
            if(i != size - 1)
                p_node->next = NULL;
            else
            {
                p_node->next = p2;
                printf("last node value is %d.\n", p_node->val);
            }

            prev->next = p_node;
            prev = p_node;
        }



    }


    return head;
}
