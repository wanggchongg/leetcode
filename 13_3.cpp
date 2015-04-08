#include <iostream>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;

void JOSEPHUS(int n, int k, int m)
{
	LNode *head, *ptr, *cur;
	head = (LNode *)malloc(sizeof(LNode));
	head->data = 0;
	ptr = head;
	for(int i=1; i<=n; i++)
	{
		cur = (LNode *)malloc(sizeof(LNode));
		cur->data = i;
		ptr->next = cur;
		ptr = ptr->next;
	}
	ptr->next = head->next;

	while(k--) ptr = ptr->next;
	while(n--)
	{
		int j = m-1;
		while(j--)
			ptr = ptr->next;
		cur = ptr->next;
		ptr->next = cur->next;
		cout<<cur->data<<"->";
		free(cur);
		ptr = ptr->next;
	}
	cout<<"NULL"<<endl;
}

int main()
{
	JOSEPHUS(15, 13, 4);
	return 0;
}
