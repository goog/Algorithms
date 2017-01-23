#include <stdio.h>
#include "node.h"



node *recursive_reverse_ll(node *head)
{

    if(head == NULL)
    {
        return NULL;
    }

    if(head->next == NULL)
    {
        return head;
    }

    node *new_head = recursive_reverse_ll(head->next);
    
    head->next->next = head;  // the second node points to the first one
    head->next = NULL;

    return new_head;
}


int main()
{
    int array[5] = {12, 34, 5, 56, 789};
    node *list = create_link_list_by_array(array, 5);

    print_link_list(list);

    list = recursive_reverse_ll(list);
    print_link_list(list);


}
