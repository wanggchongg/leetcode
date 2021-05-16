#include <iostream>
using namespace std;

//Definition for binary tree
struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

int maxDepth(struct TreeNode *root) {
	int depth = 0;
	if(root)
	{
		depth++;
		int ldepth, rdepth;
		ldepth = maxDepth(root->left);
		rdepth = maxDepth(root->right);
		depth += (ldepth>rdepth)?ldepth:rdepth;
	}
	return depth;
}

int main()
{
	return 0;
}