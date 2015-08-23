// Rotate List Total Accepted: 39200 Total Submissions: 180369 My Submissions Question Solution
// Given a list, rotate the list to the right by k places, where k is non-negative.

// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k)
	{
		if(!head || !head->next || k<1)
			return head;

		ListNode *first = head, *second = head;
		int len = 0;

		while(k)
		{
			if(!second)
				break;
			second = second->next;
			len++;
			k--;
		}

		if(!second)
		{
			if(!k)
				return head;
			else
			{
				k %= len;
				second = head;
				while(k--)
					second = second->next;
			}
		}

		while(second->next)
		{
			first = first->next;
			second = second->next;
		}

		second->next = head;
		head = first->next;
		first->next = NULL;

		return head;
	}

	ListNode *creatList(int n)
	{
		ListNode *head = NULL, *tail = NULL, *cur = NULL;
		int val = 0;

		for(int i=0; i<n; i++)
		{
			cin>>val;
			cur = new ListNode(val);
			if(i==0)
			{
				head = cur;
				tail = head;
			}
			else
			{
				tail->next = cur;
				tail = tail->next;
			}
		}
		tail->next = NULL;
		return head;
	}

	void freeList(ListNode *head)
	{
		ListNode *first = NULL, *second = head;
		while(second)
		{
			first = second;
			second = second->next;
			delete first;
		}
	}

	void printList(ListNode *head)
	{
		ListNode *cur = head;
		while(cur)
		{
			cout<<cur->val<<"->";
			cur = cur->next;
		}
		cout<<"NULL"<<endl;
	}
};

int main()
{
	Solution solution;
	int n, k;
	while(cin>>n>>k)
	{
		ListNode *head = solution.creatList(n);
		solution.printList(head);
		head = solution.rotateRight(head, k);
		solution.printList(head);
		solution.freeList(head);
	}
	return 0;
}