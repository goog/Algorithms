#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"


void LRU_insert(node **head, int data)
{
    printf("%s begins.\n", __FUNCTION__);
    node *new_node = (node *)calloc(sizeof(node), 1);
    if(new_node == NULL)
    {
        printf("calloc error.\n");
        exit(EXIT_FAILURE);
    }

    new_node->val = data;
    new_node->next = *head;

    *head = new_node;  //update head pointer
    printf("%s ends.\n", __FUNCTION__);
}


int LRU_access_one_node(node **head, int data)
{

    node *prev = NULL;
    node *p = *head;

    while(p)
    {
        if(p->val == data)
            break;

        prev = p;
        p = p->next;
    }

    if(p != NULL)
    {
        prev->next = p->next;
        p->next = *head;

        *head = p;
        
        return 0;
    }

    return -1;
}
int main()
{

    int array[6] = {2, 4, 6. , 8, 10, 12};
    node *head = create_link_list_by_array(array, 6);
    print_link_list(head);
    
    LRU_insert(&head, 1024);
    print_link_list(head);
    
    int ret = LRU_access_one_node(&head, 12);
    printf("the ret flag %d.\n", ret);
    print_link_list(head);
    
}
