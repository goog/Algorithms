#include <stdio.h>
#include "node.h"



void reverse_ll(node **head)
{

    node *prev = NULL;
    node *p = *head;
    node *q;

    while(p)
    {
        q = p->next;
        
        p->next = prev;

        prev = p;
        p = q;
    }

    *head = prev;
}


int main()
{
    int array[5] = {12, 34, 5, 56, 789};
    node *list = create_link_list_by_array(array, 5);

    print_link_list(list);

    reverse_ll(&list);
    print_link_list(list);

}
