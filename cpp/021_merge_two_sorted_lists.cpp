#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
	struct ListNode *head = NULL, *tail = NULL;
	if(!l1&&!l2)
		return NULL;
	else if(!l1&&l2)
		return l2;
	else if(l1&&!l2)
		return l1;

	if(l1->val<=l2->val)
	{
		head = l1;
		l1 = l1->next;
		tail = head;
	}
	else
	{
		head = l2;
		l2 = l2->next;
		tail = head;
	}

	while(l1||l2)
	{
		if(!l1)
		{
			tail->next = l2;
			break;
		}
		if(!l2)
		{
			tail->next = l1;
			break;
		}
		if(l1->val<=l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
			tail = tail->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
			tail = tail->next;
		}
	}
	return head;
}

int main()
{
	struct ListNode *l1 = NULL, *l2 = NULL, *tail = NULL, *point = NULL;
	int i;
	for(i=0; i<10; i++)
	{
		point = (struct ListNode *)malloc(sizeof(struct ListNode));
		point->val = 2*(i+1)-1;
		printf("%d->", point->val);
		if(i==0)
		{
			l1 = tail = point;
			tail->next = NULL;
		}
		else
		{
			tail->next = point;
			tail = tail->next;
		}
	}
	printf("NULL\n");
	tail->next = NULL;
	for(i=0; i<10; i++)
	{
		point = (struct ListNode *)malloc(sizeof(struct ListNode));
		point->val = 2*(i+1);
		printf("%d->", point->val);
		if(i==0)
		{
			l2 = tail = point;
			tail->next = NULL;
		}
		else
		{
			tail->next = point;
			tail = tail->next;
		}
	}
	printf("NULL\n");
	tail->next = NULL;

	tail = mergeTwoLists(l1, l2);
	while(tail)
	{
		printf("%d->", tail->val);
		tail = tail->next;
	}
	printf("NULL\n");
	return 0;
}
