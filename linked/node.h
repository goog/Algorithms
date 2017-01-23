


typedef struct node
{
    int val;
    struct node *next;
} node;


node *create_link_list_by_array(int *array, int size);
void print_link_list(node *head);
node *create_loop_link_list_by_array(int *array, int size);
