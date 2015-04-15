// Intersection of Two Linked Lists Total Accepted: 24437 Total Submissions: 87843 My Submissions Question Solution
// Write a program to find the node at which the intersection of two singly linked lists begins.


// For example, the following two linked lists:

// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗
// B:     b1 → b2 → b3
// begin to intersect at node c1.


// Notes:

// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	ListNode *ha = headA, *hb = headB;
    	if(!ha || !hb) return NULL;
    	int countA = 1, countB = 1;

    	while(ha->next)
    	{
    		countA++;
    		ha = ha->next;
    	}

    	while(hb->next)
    	{
    		countB++;
    		hb = hb->next;
    	}

    	if(ha != hb) return NULL;

    	ha = headA;
    	hb = headB;

    	while(countA > countB)
    	{
    		ha = ha->next;
    		countA--;
    	}
    	while(countB > countA)
    	{
    		hb = hb->next;
    		countB--;
    	}

    	while(ha && hb)
    	{
    		if(ha == hb)
    			return ha;
    		else
    		{
    			ha = ha->next;
    			hb = hb->next;
    		}
    	}
    	return NULL;
    }
};

int main()
{
	return 0;
}