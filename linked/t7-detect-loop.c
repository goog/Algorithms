#include <stdbool.h>
#include <stdio.h>
#include "node.h"


bool ll_exist_loop(node *head)
{

    if(head == NULL)
        return false;

    node *slow, *fast;

    slow = fast = head;

    while(1)
    {
        slow = slow->next;
        fast = fast->next;

        if(fast == NULL)
            return false;


        fast = fast->next; // fast goes two steps

        if(slow == NULL || fast == NULL)
        {
            return false;
        }
        
        if(slow == fast)
        {
            return true;
        }
    }

}


int main()
{

    int array[6] = {2, 4, 6. , 8, 10, 12};
    node *list_no_loop = create_link_list_by_array(array, 6);
    //print_link_list(list);

    node *list = create_loop_link_list_by_array(array, 6);
    //print_link_list(list);

    bool ret = ll_exist_loop(list);
    printf("the return bool is %d.\n", ret);

    ret = ll_exist_loop(list_no_loop);
    printf("list_no_loop return bool is %d.\n", ret);
}
