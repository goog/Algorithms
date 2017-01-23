#include <stdio.h>
#include "node.h"


node *inverted_nth(node *head, int k)
{
    printf("the inverted order index is %d.\n", k);
    
    int cnt = 0;
    node *p1, *p2;

    p1 = p2 = head;

    while(p1)
    {
        cnt++;

        if(cnt == k)
            break;

        p1 = p1->next;
    }

    if(p1 == NULL)
        return NULL;

    p1 = p1->next;

    while(p1)
    {

        p1 = p1->next;
        p2 = p2->next;
    }

    return p2;
}

int main()
{
    int array[5] = {12, 34, 5, 56, 789};
    node *list = create_link_list_by_array(array, 5);

    print_link_list(list);

    node *found_node = inverted_nth(list, 3);
    if(found_node)
    {
        printf("the node data value is %d.\n", found_node->val);
    }
    else
    {
        printf("the index is too large.\n");
    }

}
