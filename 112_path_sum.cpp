// Path Sum Total Accepted: 48632 Total Submissions: 162916 My Submissions Question Solution
// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

#include <iostream>
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
    static bool hasPathSum(TreeNode *root, int sum);
    static void createTree(TreeNode * &root);
};

bool Solution::hasPathSum(TreeNode *root, int sum) {
	if(root)
	{
		int lack = sum - root->val;
		if(root->right == NULL && root->left == NULL) //递归结束条件
		{
	    	if(lack) return false;
	    	else return true;
		}

		if(hasPathSum(root->left, lack))
			return true;

		if(hasPathSum(root->right, lack))
			return true;
	}
	return false;
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
	//输入：5,4,11,7,0,0,2,0,0,0,8,13,0,0,4,0,1,0,0
	bool result;
	TreeNode *root;
	Solution::createTree(root);
	result = Solution::hasPathSum(root, 22);
	cout<<"result = "<<boolalpha<<result<<endl;
	return 0;
}
