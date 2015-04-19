// Remove Duplicates from Sorted List Total Accepted: 53921 Total Submissions: 157440 My Submissions Question Solution
// Given a sorted linked list, delete all duplicates such that each element appear only once.

// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3

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
    ListNode *deleteDuplicates(ListNode *head) {
    	if(!head) return head;
    	ListNode *first = head, *second = head->next;
    	ListNode *point = NULL;
    	while(second)
    	{
    		while(second && first->val==second->val)
    		{
    			point = second;
    			second = second->next;
    			free(point);
    		}
    		first->next = second;
    		if(first->next)
    		{
    			first = first->next;
    			second = second->next;
    		}
    	}
    	return head;
    }
};


int main()
{
	return 0;
}
