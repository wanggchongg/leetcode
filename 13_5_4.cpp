
//用两个栈表示堆(用模板表示)
#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct LNode
{
	T data;
	LNode<T> *next;
};

template <typename T>
class LinkStack
{
public:
	LinkStack();
	~LinkStack();
	void push(T &);
	void pop(T &);
	bool isEmpty();
private:
	LNode<T> *top;
	LNode<T> *base;
};

template <typename T>
LinkStack<T>::LinkStack()
{
	top = base = NULL;
}

template <typename T>
LinkStack<T>::~LinkStack()
{
}

template <typename T>
void LinkStack<T>::push(T &data)
{
	LNode<T> *cur = new LNode<T>;
	cur->data = data;
	cur->next = NULL;
	if(!top)
	{
		top = cur;
		base = cur;
	}
	else
	{
		cur->next = top;
		top = cur;
	}
}

template <typename T>
void LinkStack<T>::pop(T &data)
{
	LNode<T> *cur;
	if(!top)
	{
		return;
	}
	else
	{
		cur = top;
		top = cur->next;
		data = cur->data;
		free(cur);
	}
}

template <typename T>
bool LinkStack<T>::isEmpty()
{
	if(top)
		return true;
	else
		return false;
}

template <typename T>
class LinkQueue
{
public:
	LinkQueue();
	~LinkQueue();
	void enQueue(T &);
	void deQueue(T &);
private:
	LinkStack<T> s1;
	LinkStack<T> s2;
};

template <typename T>
LinkQueue<T>::LinkQueue()
{
}

template <typename T>
LinkQueue<T>::~LinkQueue()
{
}

template <typename T>
void LinkQueue<T>::enQueue(T &data)
{
	s1.push(data);
}

template <typename T>
void LinkQueue<T>::deQueue(T &data)
{
	T temp;
	if(!s2.isEmpty())
	{
		while(s1.isEmpty())
		{
			s1.pop(temp);
			s2.push(temp);
		}
	}
	if(s2.isEmpty())
	{
		s2.pop(temp);
		cout<<temp<<" exit queue"<<endl;
		data = temp;
	}
	else
	{
		cout<<"queue empty now"<<endl;
		return;
	}
}

int main()
{
	LinkQueue<string> queue;
	string data = "hello world";
	for(int i=10; i<20; i++)
		queue.enQueue(data);
	for(int i=0; i<3; i++)
		queue.deQueue(data);
	for(int i=0; i<10; i++)
		queue.deQueue(data);
	return 0;
}
