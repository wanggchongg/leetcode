#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;

typedef struct LinkQueue
{
	LNode *front;
	LNode *rear;
}LinkQueue;

void enQueue(LinkQueue &queue, int data)
{
	LNode *cur = (LNode *)malloc(sizeof(LNode));
	cur->data = data;
	cur->next = NULL;

	if(!queue.rear)
	{
		queue.front = cur;
		queue.rear = cur;
	}
	else
	{
		queue.rear->next = cur;
		queue.rear = cur;
	}
}

void deQueue(LinkQueue &queue)
{
	LNode *cur;
	if(!queue.front)
	{
		cout<<"empty now"<<endl;
		return;
	}
	else
	{
		cur = queue.front;
		queue.front = cur->next;
		cout<<cur->data<<" exit queue"<<endl;
		free(cur);
	}
}

int main()
{
	LinkQueue queue;
	queue.rear = queue.rear = NULL;
	for(int i=6; i<20; i++)
	{
		enQueue(queue, i);
	}

	for(int i=0; i<4; i++)
	{
		deQueue(queue);
	}

	cout<<"head data="<<queue.front->data<<endl;
	return 0;
}
