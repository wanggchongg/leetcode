// Same Tree Total Accepted: 56437 Total Submissions: 134302 My Submissions Question Solution
// Given two binary trees, write a function to check if they are equal or not.

// Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

#include <iostream>
#include <stack>
using namespace std;

 // Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) { //先序遍历
    	if(!p&&!q) return true;
    	stack<TreeNode*> s_p, s_q;
	    TreeNode *p_t = p, *q_t = q;
	    while(p_t||!s_p.empty()||q_t||!s_q.empty())
	    {
	        while(p_t && q_t)
	        {
	            if(p_t->val != q_t->val) //值不同
	            	return false;
	            s_p.push(p_t);
	            p_t = p_t->left;

	            s_q.push(q_t);
	            q_t = q_t->left;
	        }

	        if(p_t || q_t) //树形结构不同
	        	return false;

	        if(!s_p.empty() && !s_q.empty())
	        {
	            p_t = s_p.top();
	            s_p.pop();
	            p_t = p_t->right;

	            q_t = s_q.top();
	            s_q.pop();
	            q_t = q_t->right;
	        }
	    }
	    return true;
    }

    void createTree(TreeNode* &root)
	{
		int value = 0;
		cout<<"input number: (0 = NULL)"<<endl;
		cin>>value;
		if(value == 0) root = NULL; //递归结束条件
		else
		{
			root = (TreeNode *)malloc(sizeof(TreeNode));
			root->val = value;
			createTree(root->left);
			createTree(root->right);
		}
	}
};

int main()
{
	TreeNode *p = NULL, *q = NULL;
	Solution s1, s2;
	cout<<"The first:"<<endl;
	s1.createTree(p);
	cout<<"The second:"<<endl;
	s2.createTree(q);
	cout<<boolalpha<<s1.isSameTree(p, q)<<endl;
	return 0;
}