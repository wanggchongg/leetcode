
#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    	int value = 0;
    	ListNode *head = NULL, *tail = NULL;
    	if(!l1)
    		return l2;
    	if(!l2)
    		return l1;
    	head = l1;
    	while(l1||l2)
    	{
    		if(l1&&l2)
    		{
    			value = value + l1->val + l2->val;
    			l1->val = value % 10;
    			value /= 10;
    			tail = l1;
    			l1 = l1->next;
    			l2 = l2->next;
    			continue;
    		}
    		if(!l1)
    		{
    			value = value + l2->val;
    			l2->val = value % 10;
    			value /= 10;
    			tail->next = l2;
    			tail = tail->next;
    			l2 = l2->next;
    			continue;
    		}
    		if(!l2)
    		{
    			value = value + l1->val;
    			l1->val = value % 10;
    			value /= 10;
    			tail->next = l1;
    			tail = tail->next;
    			l1 = l1->next;
    			continue;
    		}
    	}
    	if(value)
    	{
    		l1 = new ListNode(value);
    		tail->next = l1;
    	}
  		return head;
    }
};

int main()
{
	Solution *solution = new Solution;
	ListNode *l1 = NULL, *l2 = NULL, *tail, *point;
	int i;
	for(i=0; i<10; i++)
	{
		point = new ListNode(2*i+1);
		if(i==0)
		{
			l1 = tail = point;
		}
		else
		{
			tail->next = point;
			tail = tail->next;
		}
		cout<<tail->val<<"->";
	}
	cout<<"NULL"<<endl;
	for(i=0; i<9; i++)
	{
		point = new ListNode(i+1);
		if(i==0)
		{
			l2 = tail = point;
		}
		else
		{
			tail->next = point;
			tail = tail->next;
		}
		cout<<tail->val<<"->";
	}
	cout<<"NULL"<<endl;

	point = solution->addTwoNumbers(l1, l2);
	while(point)
	{
		cout<<point->val<<"->";
		point = point->next;
	}
	cout<<"NULL"<<endl;
	return 0;
}
