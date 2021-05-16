// Minimum Depth of Binary Tree Total Accepted: 49511 Total Submissions: 169926 My Submissions Question Solution
// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.


#include <iostream>
#include <limits.h>
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
    static int minDepth(TreeNode *root);
    static void createTree(TreeNode* &root);
};

int Solution::minDepth(TreeNode *root) {
	int depth = 0;
	if(root)
	{
		int leftDep = INT_MAX, rightDep = INT_MAX; //防止当只有左或右子树为空时，返回0
		depth++;
		if(root->right == NULL && root->left == NULL) //递归结束条件
	    	return depth;

	    if(root->left)
	    	leftDep = minDepth(root->left);
	    if(root->right)
	    	rightDep = minDepth(root->right);
	    depth += ((leftDep<rightDep)?leftDep:rightDep);
	}
	return depth;
}

void Solution::createTree(TreeNode* &root)
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

int main()
{
	TreeNode *root = NULL;
	Solution::createTree(root);
	int depth = Solution::minDepth(root);
	cout<<"min depth = "<<depth<<endl;
	return 0;
}
