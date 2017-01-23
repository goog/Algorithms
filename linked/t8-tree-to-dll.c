#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct node
{
    struct node *left;
    struct node *right;
    int val;
} Node;



void treeToDoublyList(Node *p, Node **prev, Node **head)
{
    
    if(!p) return;

    treeToDoublyList(p->left, prev, head);
  
    // current node's left points to previous node
    p->left = *prev;
    if(*prev)
        (*prev)->right = p;
    else
        *head = p;
    
    // as soon as the recursion ends, the head's left pointer 
    // points to the last node, and the last node's right pointer
    // points to the head pointer.
    Node *right = p->right;

    (*head)->left = p;
    p->right = *head;   // a circle
   
    
    // update previous node
    *prev = p;
    treeToDoublyList(right, prev, head);
}

// Given an ordered binary tree, returns a sorted circular
// doubly-linked list. The conversion is done in-place.
Node* tree2dll(Node *root) 
{
    printf("%s begins.\n", __FUNCTION__);
    Node *prev = NULL;
    Node *head = NULL;
  
    treeToDoublyList(root, &prev, &head);

    printf("%s ends.\n", __FUNCTION__);
    return head;
}


int main()
{
    Node a, b, c, d, e;
    memset(&a, 0, sizeof(Node));
    memset(&b, 0, sizeof(Node));
    memset(&c, 0, sizeof(Node));
    memset(&d, 0, sizeof(Node));
    memset(&e, 0, sizeof(Node));
    a.val = 5;
    b.val = 2;
    c.val = 6;
    d.val = 1;
    e.val = 3;

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;

    Node *head = tree2dll(&a);
    //printf("the head pointer is %p.\n", head);
    while(head)
    {
        printf("%d \t", head->val);
        fflush(stdout);
        sleep(1);
        
        head = head->right;
    }

}
