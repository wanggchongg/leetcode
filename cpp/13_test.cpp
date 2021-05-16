#include <iostream>
using namespace std;

//单链表
typedef struct Node
{
	int data;
	struct Node *next;
}Node;

Node *create()
{
	Node *head = NULL, *tail = NULL, *cur = NULL;
	int value = 1;
	cin>>value;
	if(value)
	{
		head = (Node *)malloc(sizeof(Node));
		head->data = value;
		tail = head;
	}
	else
		return head;
	while(value)
	{
		cin>>value;
		if(value)
		{
			cur = (Node *)malloc(sizeof(Node));
			cur->data = value;
			tail->next = cur;
			tail = tail->next;
		}
	}
	tail->next = NULL;
	return head;
}

int countLen(Node *head)
{
	Node *p = head;
	int count = 0;
	while(p)
	{
		p = p->next;
		count++;
	}
	return count;
}

void print(Node *head)
{
	Node *p = head;
	while(p)
	{
		cout<<p->data<<"\t";
		p = p->next;
	}
	cout<<endl;
}

Node *delNode(Node *head, int num)
{
	Node *p = head, *cur = NULL;
	while(p)
	{
		if(num == p->data)
		{
			if(p == head)
			{
				cur = p;
				p = p->next;
				head = p;
				free(cur);
			}
			else
			{
				cur = p;
				p = p->next;
				free(cur);
			}
		}
		else
			p = p->next;
	}
	return head;
}

//简单选择排序
Node *sort(Node *head)
{
	if(!head || !head->next)
		return head;
	Node *p1 = head, *p2 = NULL, *pmin = NULL;
	int temp = 0;
	while(p1)
	{
		pmin = p1;
		p2 = p1->next;
		while(p2)
		{
			if(p2->data < pmin->data)
				pmin = p2;
			p2 = p2->next;
		}
		if(pmin != p1)
		{
			temp = p1->data;
			p1->data = pmin->data;
			pmin->data = temp;
		}
		p1 = p1->next;
	}
	return head;
}

//逆置
Node *reverse(Node *head)
{
	if(!head || !head->next)
		return head;
	Node *p1 = head, *cur = NULL;
	head = NULL;
	while(p1)
	{
		cur = p1;
		p1 = p1->next;
		cur->next = head;
		head = cur;
	}
	return head;
}

//双链表
typedef struct DNode
{
	int data
	struct DNode *next;
	struct DNode *pre;
}DNode;

DNode *create()
{
	DNode *head = NULL, *tail = NULL, *cur = NULL;
	int value;
	cin>>value;
	if(value)
	{
		head = (DNode *)malloc(sizeof(DNode));
		head->data = value;
		head->pre = NULL;
		tail = head;
	}
	else
		return head;
	while(value)
	{
		cin>>value;
		if(value)
		{
			cur = (DNode *)malloc(sizeof(DNode))
			cur->data = value;
			tail->next = cur;
			cur->pre = tail;
			tail = cur;
		}
	}
	tail->next = NULL;
	return head;
}

DNode *delNthNode(DNode *head, int n)
{
	if(n < 1)
		return head;
	DNode *p1 = head, *p2 = head, *cur = NULL;
	while(p2 && n)
	{
		p2 = p2->next;
		n--;
	}
	if(!p2 && n)
		return head;
	if(!p2 && !n)
	{
		cur = head;
		head = head->next;
		head->pre = NULL;
		free(cur);
		return head;
	}

	while(p2->next)
	{
		p1 = p1->next;
		p2 = p2->next;
	}

	if(p1->next == p2)
	{
		free(p2);
		p1->next = NULL;
	}
	else
	{
		cur = p1->next;
		p1->next = cur->next;
		cur->next->pre = p1;
		free(cur);
	}
	return head;
}

//链队
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;

typedef struct LinkQueue
{
	LNode *front;
	LNode *rear;
}LinkQueue;

void enQueue(LinkQueue &queue, int data)
{
	LNode *cur = (LNode *)malloc(sizeof(LNode));
	cur->data = data;
	cur->next = NULL;

	if(!queue.rear)
	{
		queue.front = cur;
		queue.rear = cur;
	}
	else
	{//尾插法
		queue.rear->next = cur;
		queue.rear = cur;
	}
}

void deQueue(LinkQueue &queue)
{
	LNode *cur;
	if(!queue.front)
	{
		cout<<"empty now"<<endl;
		return;
	}
	else
	{
		cur = queue.front;
		if(queue.rear == queue.front)
		{
			queue.rear = NULL;
			queue.front = NULL;
		}
		else
		{
			queue.front = cur->next;
		}
		cout<<cur->data<<" exit queue"<<endl;
		free(cur);
	}
}

//链栈
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;

typedef struct LinkStack
{
	LNode *top;
	LNode *base;
}LinkStack;

void push(LinkStack &stack, int &data)
{
	LNode *cur = (LNode *)malloc(sizeof(LNode));
	cur->data = data;
	cur->next = NULL;
	if(!stack.top)
	{
		stack.top = cur;
		stack.base = cur;
	}
	else
	{//头插法
		cur->next = stack.top;
		stack.top = cur;
	}
}

void pop(LinkStack &stack)
{
	LNode *cur;
	if(!stack.top)
	{
		cout<<"empty now"<<endl;
		return;
	}
	else
	{

		cur = stack.top;
		if(stack.top == stack.base)
		{
			stack.top = NULL;
			stack.base = NULL;
		}
		else
			stack.top = cur->next;
		cout<<cur->data<<" exit stack"<<endl;
		free(cur);
	}
}


//两个栈实现一个队列
template<typename T>
class MyQueue
{
private:
	stack<T> s1, s2;
public:
	void push(T &t)
	{
		s1.push(t);
	}

	void pop()
	{
		if(s2.empty())
		{
			while(!s1.empty())
			{
				s2.push(s1.top())
				s1.pop();
			}
		}
		if(!s2.empty())
		{
			s2.pop();
		}
	}

	T front()
	{
		if(s2.empty())
		{
			while(!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		return s2.top();
	}
};


//二叉树的遍历算法
struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

struct TreeNode1
{
	TreeNode *pNode;
	bool isFirst;
	TreeNode1(TreeNode *pn) : pNode(pn), isFirst(true) {}
};

class BiTree
{
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

	void preOrder1(TreeNode *root) //递归前序遍历
	{
		if(root)
		{
			cout<<root->value<<" ";
			preOrder1(root->left);
			preOrder1(root->right);
		}
	}

	void inOrder1(TreeNode *root) //递归中序遍历
	{
		if(root)
		{
			inOrder1(root->left);
			cout<<root->value<<" ";
			inOrder1(root->right);
		}
	}

	void postOrder1(TreeNode *root) //递归后序遍历
	{
		if(root)
		{
			postOrder1(root->left);
			postOrder1(root->right);
			cout<<root->value<<" ";
		}
	}

	void levelOrder(TreeNode *root) //层次遍历
	{
		if(!root)
			return;
		queue<TreeNode *> q;
		TreeNode *p = root;
		int NULL_count = 0;

		q.push(p);
		q.push(NULL);

		while(!q.empty())
		{
			p = q.front();
			q.pop();
			if(p != NULL)
			{
				NULL_count = 0;
				cout<<p->value<<" ";
				if(p->left)
					q.push(p->left);
				if(p->right)
					q.push(p->right);
			}
			else
			{
				NULL_count++;
				if(NULL_count == 2)
					break;
				q.push(NULL);
			}
		}
	}

	void preOrder2(TreeNode *root) //非递归前序遍历
	{
		stack<TreeNode *> s;
		TreeNode *p = root;
		while(p || !s.empty())
		{
			while(p)
			{
				cout<<p->value<<" ";
				s.push(p);
				p = p->left;
			}
			if(!s.empty())
			{
				p = s.top();
				s.pop();
				p = p->right;
			}
		}
	}

	void inOrder2(TreeNode *root) //非递归中序遍历
	{
		stack<TreeNode *> s;
		TreeNode *p = root;
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
				cout<<p->value<<" ";
				s.pop();
				p = p->right;
			}
		}
	}

	void postOrder2(TreeNode *root) //非递归后序遍历
	{
		stack<TreeNode1 *> s;
		TreeNode *p = root;
		TreeNode1 *temp;
		while(p || !s.empty())
		{
			while(p)
			{
				TreeNode1 *tN1 = new TreeNode1(p);
				s.push(tN1);
				p = p->left;
			}
			if(!s.empty())
			{
				temp = s.top();
				if(temp->isFirst)
				{
					temp->isFirst = false;
					s.push(temp);
					p = temp->pNode->right;
				}
				else
				{
					cout<<temp->pNode->value<<" ";
					p = NULL;
				}
			}
		}
	}

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
};


//快速排序
int partition(int s[], int i, int j)
{
	int value = s[i];
	int flag = 1;
	while(i<j)
	{
		switch(flag)
		{
		case 0:
			if(s[i] <= value)
				i++;
			else
			{
				s[j--] = s[i];
				flag = 1;
			}
			break;
		case 1:
			if(s[j] > value)
				j--;
			else
			{
				s[i++] = s[j];
				flag = 0;
			}
		}
	}
	return i;
}

void quick_sort(s[], int l, int r)
{
	if(l<r)
	{
		int res = partition(s, l, r);
		quick_sort(s, l, res-1);
		quick_sort(s, res+1, r);
	}
}



int main()
{
	return 0;
}