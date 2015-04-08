#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct dnode
{
	int data;
	struct dnode *next;
	struct dnode *pref;
}dnode;

dnode *creat()
{
	dnode *head, *tail, *cur;
	head = (dnode *)malloc(sizeof(dnode));
	head->pref = NULL;
	tail = head;
	int data = -1;
	while(data)
	{
		cout<<"please input data:"<<endl;
		cin>>data;
		if(data)
		{
			cur = (dnode *)malloc(sizeof(dnode));
			cur->data = data;
			tail->next = cur;
			cur->pref = tail;
			tail = tail->next;
		}
		else
			break;
	}
	tail->next = NULL;
	return head;
}

int main()
{
	dnode *head;
	head = creat();
	return 0;
}