#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;

typedef struct LinkStack
{
	LNode *top;
	LNode *base;
}LinkStack;

void push(LinkStack &stack, int &data)
{
	LNode *cur = (LNode *)malloc(sizeof(LNode));
	cur->data = data;
	cur->next = NULL;
	if(!stack.top)
	{
		stack.top = cur;
		stack.base = cur;
	}
	else
	{
		cur->next = stack.top;
		stack.top = cur;
	}
}

void pop(LinkStack &stack)
{
	LNode *cur;
	if(!stack.top)
	{
		cout<<"empty now"<<endl;
		return;
	}
	else
	{
		cur = stack.top;
		stack.top = cur->next;
		cout<<cur->data<<" exit stack"<<endl;
	}
}

int main()
{
	LinkStack stack;
	stack.top = NULL;
	stack.base = NULL;

	for(int i=0; i<20; i++)
	{
		push(stack, i);
	}

	for(int i=0; i<25; i++)
	{
		pop(stack);
	}
	return 0;
}
