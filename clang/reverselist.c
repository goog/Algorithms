/*
 * reverselist.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>

struct nodeList
{
  int value;
  struct nodeList *next;
};

typedef struct nodeList ELEMENT;

ELEMENT * reverseList(ELEMENT *pHead)
{
	ELEMENT * i = NULL; 
	ELEMENT * p= pHead;
	ELEMENT * pnext;
	while(p !=NULL)
	{
		pnext = p->next;
		p->next = i;
		i = p; // the reverse link list head pointer ;
		p = pnext;
	}
	return i;
	
}

int main()
{
	ELEMENT * p = malloc(sizeof(ELEMENT));
	p->value = 12;
	ELEMENT * q = malloc(sizeof(ELEMENT));
	q->value = 20;
	q->next = NULL;
	p->next = q;
	ELEMENT *head = reverseList(p);
	printf("%p\n",head);
	while(head)
	{
		printf("%d\t",head->value);
		head = head->next;
	}
	return 0;
}

