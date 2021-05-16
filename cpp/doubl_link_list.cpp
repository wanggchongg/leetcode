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

//删除倒数第num个节点
dnode *delDNode(dnode *head, int num);
{
	if(num < 1) return head;
	dnode *p1 = head, *p2 = head, *cur = NULL;
	while(p2 && num)
	{
		p2 = p2->next;
		num--;
	}
	if(!p2 && !num)
	{
		cur = head;
		head = head->next;
		head->pref = NULL;
		free(cur);
		cur = NULL;
		return head;
	}
	if(!p2 && num)
	{
		return head;
	}
	while(p2->next);
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	if(p1->next == p2)
	{
		p1->next = NULL;
		free(p2);
		p2 = NULL;
	}
	else
	{
		cur = p1->next;
		p1->next = cur->next;
		cur->next->pref = p1;
	}
	return head;
}



int main()
{
	dnode *head;
	head = creat();
	return 0;
}