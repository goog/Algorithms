/*
 * queue.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * 
 * 
 */

using namespace std;
#include <iostream>
#include <cstring>
#include <cstdlib>

#define MAXSIZE 10

typedef struct
{
int *base;
int front;
int rear;	
} seQ;

int enqueue(seQ &q ,int key)
{
	// assert queue is full
	if((q.rear+1)%MAXSIZE == q.front) 
	{
		cout << "the queue is full." << endl;
		return -1;
	}
	q.base[q.rear] = key;
	q.rear = (q.rear+1)%MAXSIZE;
	return 0;
}

int dequeue(seQ &q)
{
	// queue is empty?
	if(q.rear == q.front) 
		{
			cout << "queue is empty." << endl;
			return -1;
		}
	q.front=(q.front+1)%MAXSIZE;
	return 0;
}

int qlen(seQ &q)
{
	cout << "The remainder space is " << MAXSIZE -1 - (q.rear+MAXSIZE-q.front)%MAXSIZE <<endl;
	return (q.rear+MAXSIZE-q.front)%MAXSIZE;
}


int main()
{	int *a = (int *)malloc(MAXSIZE*sizeof(int));
	seQ q;
	q.base = a;
	q.front = 0;
	q.rear = 0;
	enqueue(q ,1);
	enqueue(q ,2);
	enqueue(q ,3);
	enqueue(q ,4);
	enqueue(q ,5);
	enqueue(q ,6);
	enqueue(q ,7);
	enqueue(q ,8);
	enqueue(q ,9);
	enqueue(q ,10);
	qlen(q);
	
	delete a;
	a = NULL;
	return 0;
}

