#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void remove_list_node(node *head, int remove_val)
{
    node **pp = &head;
    node *entry = head;

    while(entry)
    {
        if(entry->val == remove_val)
        {
            printf("value equals.\n");
            *pp = entry->next;

            free(entry);
        }

        pp = &(entry->next);  //point to the node's next filed address
        entry = entry->next;
   
    }
    
}


int main()
{

    int array[5] = {12, 34, 5, 56, 789};
    node *list = create_link_list_by_array(array, 5);

    print_link_list(list);

    remove_list_node(list, 56);
    print_link_list(list);

}
