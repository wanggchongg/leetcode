#include <stdio.h>
#include <stdlib.h>
 //Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
	struct ListNode *first = head, *second = head, *point = NULL;
	int i;
	if(!head||n<0) //异常情况
		return point;

	for(i=0; i<n; i++)
	{
		if(!second)
			break;
		second = second->next;
	}

	if(!second&&i<n) //异常情况, n>结点总数
	{
		return point;
	}
	if(!second&&i==n) //删除head结点的情况
	{
		point = first->next;
		return point;
	}

	while(second->next) //普通情况
	{
		first = first->next;
		second = second->next;
	}
	point = first->next;
	first->next = point->next;
	point = head;
	return point;
}

int main()
{
	struct ListNode *head = NULL, *tail = NULL, *point = NULL;
	int i;
	int max = 10;
	int value;

	for(i=0; i<max; i++)
	{
		point = (struct ListNode *)malloc(sizeof(struct ListNode));
		point->val = i+1;
		printf("%d->", point->val);
		if(i==0)
		{
			head = tail = point;
			tail->next = NULL;
			continue;
		}
		tail->next = point;
		tail = tail->next;
		tail->next = NULL;
	}
	printf("NULL\n");


	head = removeNthFromEnd(head, 3);
	tail = head;
	while(tail)
	{
		value = tail->val;
		tail = tail->next;
		printf("%d->", value);
	}
	printf("NULL\n");

	return 0;
}
