// Balanced Binary Tree Total Accepted: 51648 Total Submissions: 161078 My Submissions Question Solution
// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool depthBalance(TreeNode *&root, int &depth)
    {
    	depth = 0;
    	if(root)
    	{
    		int ldepth = 0, rdepth = 0;
    		if(!depthBalance(root->left, ldepth))
    			return false;
    		if(!depthBalance(root->right, rdepth))
    			return false;
    		if(abs(ldepth-rdepth) >= 2)
    			return false;
    		depth = ((ldepth > rdepth)?ldepth:rdepth) + 1;
    		cout<<"depth = "<<depth<<endl;
    	}
    	return true;
    }

public:
    bool isBalanced(TreeNode *&root)
    {
    	int depth = 0;
    	if(depthBalance(root, depth))
    		return true;
    	else
    		return false;
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
	TreeNode *root = NULL;

	Solution solution;
	solution.createTree(root);
	cout<<boolalpha<<solution.isBalanced(root)<<endl;
	return 0;
}
