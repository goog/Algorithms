#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node item;

item * reverse_link_list(item * head)
{

    item *p = NULL, *p_next = NULL, *q = NULL;

    /*if(head == NULL)
    {
        return NULL;
    }*/

    p = head;

    while(p)
    {
        p_next = p->next;

        if(p == head)
        {
            q = p;
            q->next = NULL;   // the first reversed node
        }
        else
        {
            p->next = q;   // q : temp head, insert at head
            q = p;
        }

        p = p_next; // search to next node

    }

    return q;
}





int main()
{

    item *i1 = (item *)calloc(1, sizeof(item));
    if(i1 == NULL)
    {
        printf("calloc failed \n");
        return -1;
    }
    item *i2 = (item *)calloc(1, sizeof(item));
    if(i2 == NULL)
    {
        printf("calloc failed \n");
        return -1;
    }

    item *i3 = (item *)calloc(1, sizeof(item));
    if(i3 == NULL)
    {
        printf("calloc failed \n");
        return -1;
    }

    i1->data = 20;
    i1->next = i2;

    i2->data = 10;
    i2->next = i3;

    i3->data = 30;
    i3->next = NULL;

    item * new = reverse_link_list(i1);

    while(new)
    {
        printf("%d\n", new->data);
        new = new->next;
    }


    free(i1);
    free(i2);
    free(i3);

    return 0;
}
