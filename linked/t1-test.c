#include "node.h"



int main()
{

    int array[5] = {12, 34, 5, 56, 789};
    node *list = create_link_list_by_array(array, 5);

    print_link_list(list);
}
