// Binary Tree Level Order Traversal Total Accepted: 46831 Total Submissions: 157954 My Submissions Question Solution
// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]
// confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

//广度优先查找
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//Definition for binary tree
struct TreeNode {
   	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
    	vector<vector<int> > result;
    	if(!root) return result;
    	vector<int> layer;
    	queue<TreeNode *> rootQ;
    	TreeNode *current = root;
    	int NULL_count=0;

    	rootQ.push(current);
    	rootQ.push(NULL);

    	while(!rootQ.empty())
    	{
    		current = rootQ.front();
    		rootQ.pop();
    		if(current != NULL)
    		{
    			NULL_count = 0;
    			layer.push_back(current->val);
    			if(current->left)
    				rootQ.push(current->left);
    			if(current->right)
    				rootQ.push(current->right);
    		}
    		else
    		{
    			NULL_count++;
    			if(NULL_count==2)
    				break;
    			rootQ.push(NULL);
	    		result.push_back(layer);
	    		layer.clear();
    		}
    	}
    	return result;
    }

    void createTree(TreeNode* &root)
	{
		int value = 0;
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
	vector<vector<int> > result;
	int n = 0;
	while(cin>>n)
	{
		solution.createTree(root);
		result = solution.levelOrder(root);
		for(int i=0; i<result.size(); i++)
		{
			for(int j=0; j<result[i].size(); j++)
			{
				cout<<result[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<"------------------------"<<endl;
		result.clear();
		root = NULL;
	}
	return 0;
}
