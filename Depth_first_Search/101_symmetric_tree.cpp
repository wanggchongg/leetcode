// Symmetric Tree Total Accepted: 51931 Total Submissions: 164645 My Submissions Question Solution
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3
// Note:
// Bonus points if you could solve it both recursively and iteratively.

// confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

#include <iostream>
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
public:
    bool isSymmetric(TreeNode *root) {
    	if(root) return true;
    	stack<TreeNode*> leftV, rightV;
	    TreeNode *leftR = root->left, *rightR = root->right;
	    while(leftR||!leftV.empty()||rightR||!rightV.empty())
	    {
	        while(leftR && rightR)
	        {
	            if(leftR->val != rightR->val) //值不同
	            	return false;
	            leftV.push(leftR);
	            leftR = leftR->left;

	            rightV.push(rightR);
	            rightR = rightR->right;
	        }

	        if(leftR || rightR) //树形结构不同
	        	return false;

	        if(!leftV.empty() && !rightV.empty())
	        {
	            leftR = leftV.top();
	            leftV.pop();
	            leftR = leftR->right;

	            rightR = rightV.top();
	            rightV.pop();
	            rightR = rightR->left;
	        }
	    }
	    return true;

    }
};

int main()
{
	return 0;
}