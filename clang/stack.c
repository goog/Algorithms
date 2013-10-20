/*
 * stack.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>

typedef char stackElementT;

typedef struct {
  stackElementT *contents;
  int top;
  int maxSize;
} stackT;


// function definition
void StackInit(stackT *stackP, int maxSize)
{
	stackElementT *newContents;
	/* Allocate a new array to hold the contents. */
	
	newContents = (stackElementT *)malloc(sizeof(stackElementT)* maxSize);
	if(newContents == NULL) 
	{
		fprintf(stderr, "Insufficient memory to initialize stack.\n");
		exit(1);  /* Exit, returning error code. */
	}

	stackP->contents = newContents;
	stackP->maxSize = maxSize;
	stackP->top = -1;  /* I.e., empty */
	
}

void StackDestroy(stackT *stackP)
{
	free(stackP->contents);
	stackP->contents = NULL;
	stackP->maxSize = 0;
	stackP->top = -1;   // should
}


int StackIsEmpty(stackT *stackP)
{
  return stackP->top == -1;
}

int StackIsFull(stackT *stackP)
{
  return (stackP->top == stackP->maxSize -1);
}

void push(stackT *stackP, stackElementT key)
{
	if(!StackIsFull(stackP))
		stackP->contents[++stackP->top] = key;
	else
		{
			printf("stack is full");
			exit(1);
		}
	
}


stackElementT pop(stackT *stackP)
{
	if(StackIsEmpty(stackP))
	{
		fprintf(stderr,"The stack is empty, can't pop it.");
		exit(1);
	}
		
	else
		return stackP->contents[stackP->top--];
}



int main()
{
    stackT s1;
    StackInit(&s1, 10);
    push(&s1, 'Z');
    push(&s1,'A');
    push(&s1,'B');
    printf("the stack top is : %d\n",s1.top);
    pop(&s1);
    printf("the stack top is : %d\n",s1.top);
    pop(&s1);
    printf("the stack top is : %d\n",s1.top);
    pop(&s1);
    printf("the stack top is : %d\n",s1.top);
    pop(&s1); // error test
    
	return 0;
}

