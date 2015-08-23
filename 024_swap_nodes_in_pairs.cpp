// Swap Nodes in Pairs Total Accepted: 47791 Total Submissions: 146787 My Submissions Question Solution
// Given a linked list, swap every two adjacent nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed


#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	if(!head || !head->next)
    		return head;
    	ListNode *first = head, *second = head->next, *temp = NULL, *cur = NULL;
    	head = second;
    	while(second)
    	{
    		cur = second;
    		first->next = cur->next;
    		cur->next = first;

    		if(temp)
    			temp->next = cur;//连接上一指针对和下一指针对
    		temp = first;//保存上一次转换的指针对的第二个指针

    		first = first->next;
    		if(first)
    			second = first->next;
    		else
    			second = NULL;
    	}
    	return head;
    }

    ListNode *createList(int n)
    {
    	int val;
    	ListNode *head = NULL, *tail = NULL, *cur = NULL;
    	cout<<"create list:"<<endl;
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
    	return head;
    }
};

int main()
{
	Solution solution;
	ListNode *head = NULL;
	ListNode *tail = NULL;
	int n;
	while(cin>>n)
	{
		head = solution.createList(n);
		head = solution.swapPairs(head);
		tail = head;
		while(tail)
		{
			cout<<tail->val<<"->";
			tail = tail->next;
		}
		cout<<"NULL"<<endl;
	}
	return 0;
}
