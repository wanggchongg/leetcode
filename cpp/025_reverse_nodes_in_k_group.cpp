// Reverse Nodes in k-Group Total Accepted: 32114 Total Submissions: 126045 My Submissions Question Solution
// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

// You may not alter the values in the nodes, only nodes itself may be changed.

// Only constant memory is allowed.

// For example,
// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

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
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if(!head || !head->next || k<1)
    		return head;
    	ListNode *first = new ListNode(0); //头结点
    	ListNode *second = head, *pNode = head, *temp;
    	first->next = head;
    	head = first;

    	while(second)
    	{
    		pNode = second;

    		for(int i=0; i<k; i++)
    		{
    			if(!pNode)
    			{
    				pNode = head->next;
    				delete head;
    				return pNode;
    			}
    			pNode = pNode->next;
    		}

    		for(int i=0; i<k; i++) //头插法逆置
    		{
    			pNode = second;
    			second = second->next;
    			pNode->next = first->next;
    			first->next = pNode;
    			if(i==0)
    				temp = pNode;
    		}
    		first = temp;
    		first->next = second;
    	}
    	pNode = head->next;
		delete head;
		return pNode;
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
	int n, k;
	while(cin>>n>>k)
	{
		head = solution.createList(n);
		head = solution.reverseKGroup(head, k);
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