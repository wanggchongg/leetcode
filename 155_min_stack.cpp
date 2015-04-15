// Min Stack Total Accepted: 25665 Total Submissions: 149296 My Submissions Question Solution
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.


#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
	stack<int> s;
	stack<int> min_s;
public:
    void push(int x) {
    	s.push(x);
    	if(min_s.empty() || min_s.top() >= x)
    	{
    		min_s.push(x);
    	}
    }

    void pop() {
    	if(s.empty())
    		return;
    	if(s.top() <= min_s.top())
    	{
    		min_s.pop();
    	}
    	s.pop();
    }

    int top() {
    	if(s.empty())
    		return -1;
    	return s.top();
    }

    int getMin() {
    	if(min_s.empty())
    		return -1;
    	return min_s.top();
    }
};

int main()
{
	MinStack s;
	int input = 0;
	for(int i=0; i<10; i++)
	{
		cout<<"please input number:"<<endl;
		cin>>input;
		s.push(input);
	}
	for(int i=0; i<5; i++)
	{
		cout<<"min = "<<s.getMin()<<", top = "<<s.top()<<endl;
		s.pop();
	}
	cout<<"min = "<<s.getMin()<<", top = "<<s.top()<<endl;
	return 0;
}
