#include <iostream>
#include <stack>
using namespace std;


//二叉树的遍历算法
struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

void createTree1(TreeNode *&root)//递归前序建树
	{
		int value;
		cin>>value;
		if(!value)
			root = NULL;
		else
		{
			root = new TreeNode(value);
			createTree1(root->left);
			createTree1(root->right);
		}
	}

void postOrder2(TreeNode *root) //非递归后序遍历
{
	stack<TreeNode *> s;
	TreeNode *p = root;
	TreeNode *p_t = NULL;
	while(p || !s.empty())
	{
		while(p)
		{
			s.push(p);
			p = p->left;
		}
		if(!s.empty())
		{
			p = s.top();
			if(p->right && p_t != p)
			{
				p_t = p;
				p = p->right;
			}
			else
			{
				cout<<p->value<<" ";
				s.pop();
				p = NULL;
			}
		}
	}
}


int main()
{
	TreeNode *root = NULL;
	createTree1(root);
	postOrder2(root);
	return 0;
}
