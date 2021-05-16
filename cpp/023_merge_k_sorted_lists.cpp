// Merge k Sorted Lists Total Accepted: 42850 Total Submissions: 202672 My Submissions Question Solution
// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
	struct cmp
	{//小顶堆
		bool operator()(ListNode *a, ListNode *b)
		{
			if(a->val >= b->val)
				return true;
			else
				return false;
		}
	};

    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if(lists.empty())
    		return NULL;

    	priority_queue<ListNode *, vector<ListNode *>, cmp> littleHeap;
    	for(int i=0; i<lists.size(); i++)
    	{
    		if(lists[i] != NULL)
    			littleHeap.push(lists[i]);
    	}

    	ListNode *head, *tail;
    	ListNode *cur = NULL;

    	if(!littleHeap.empty())
    	{
    		head = littleHeap.top();
    		littleHeap.pop();
    		if(head->next)
    			littleHeap.push(head->next);
    		tail = head;
    	}

    	while(!littleHeap.empty())
    	{
    		cur = littleHeap.top();
    		littleHeap.pop();
    		if(cur->next)
    			littleHeap.push(cur->next);
    		tail->next = cur;
    		tail = tail->next;
    	}
    	return head;
    }

 	ListNode *createList()
 	{
 		cout<<"createList:"<<endl;
 		ListNode *head = NULL, *tail = NULL, *cur = NULL;
 		int value;
 		head = new ListNode(0);
 		tail = head;
 		while(1)
 		{
 			cin>>value;
 			if(value)
 			{
 				cur = new ListNode(value);
 				tail->next = cur;
 				tail = tail->next;
 			}
 			else
 				return head;
 		}
 	}
};

int main()
{
	Solution solution;
	vector<ListNode *> lists;

	ListNode *head = NULL;

	for(int i=0; i<2; i++)
	{
		lists.push_back(solution.createList());
	}

	head = solution.mergeKLists(lists);

	ListNode *p = head;
	while(p)
	{
		cout<<p->val<<"->";
		p = p->next;
	}
	cout<<"NULL"<<endl;
	return 0;
}
