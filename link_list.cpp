//带头结点的单链表的建立、测长和打印, 插入， 排序，倒置，查找中间节点
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}node;

node *create()
{
	node *head = NULL, *tail = NULL;
	head = (node *)malloc(sizeof(node));
	tail = head;
	node *cur = NULL;
	int data = -1;
	while(data)
	{
		cout<<"please input the data:"<<endl;
		cin>>data;
		if(data)
		{
			cur = (node *)malloc(sizeof(node));
			cur->data = data;
			tail->next = cur;
			tail = cur;
		}
		else
			break;
	}
	tail->next = NULL;
	return head;
}

int countLength(node *const head)
{
	node *ptr = head->next;
	int n = 0;
	while(ptr)
	{
		ptr = ptr->next;
		n++;
	}
	return n;
}

void print(node *const head)
{
	node *ptr = head->next;
	while(ptr)
	{
		cout<<ptr->data<<"->";
		ptr = ptr->next;
	}
	cout<<"NULL"<<endl;
}

node *deleteNode(node *head, int n)
{
	node *ptr = head, *cur = NULL;
	int i = n-1;
	while(i)
	{
		if(!ptr->next)
		{
			cout<<"can't find "<<n<<"th node"<<endl;
			return head;
		}
		ptr = ptr->next;
		i--;
	}
	cur = ptr->next;
	ptr->next = cur->next;
	free(cur);
	return head;
}

node *sort(node *head)//简单选择排序
{
	node *ptr1 = head->next, *ptr2, *pmin;
	int temp;
	while(ptr1)
	{
		pmin = ptr1;
		ptr2 = ptr1->next;
		while(ptr2)
		{
			if(ptr2->data < pmin->data)
				pmin = ptr2;
			ptr2 = ptr2->next;
		}
		if(pmin != ptr1)
		{
			temp = ptr1->data;
			ptr1->data = pmin->data;
			pmin->data = temp;
		}
		ptr1 = ptr1->next;
	}
	return head;
}

node *reverse(node *head)
{
	node *ptr1 = head->next, *cur;
	head->next = NULL;
	while(ptr1)
	{
		cur = ptr1;
		ptr1 = ptr1->next;
		cur->next = head->next;
		head->next = cur;
	}
	return head;
}

node *searchMid(node *head)
{
	node *mid  = head->next;
	node *tail = mid;
	while(tail->next && tail->next->next)
	{
		mid = mid->next;
		tail = tail->next->next;
	}
	return mid;
}

int main()
{
	node *head, *mid;
	int n;
	head = create();
	n = countLength(head);
	cout<<"length = "<<n<<endl;
	print(head);
	head = deleteNode(head, 8);
	print(head);
	head = sort(head);
	print(head);
	head = reverse(head);
	print(head);
	mid = searchMid(head);
	cout<<"mid="<<mid->data<<endl;

	return 0;
}
