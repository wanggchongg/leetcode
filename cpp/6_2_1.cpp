#include <iostream>
using namespace std;

int main()
{
	int a = 500;
	const int *b = &a;
	int const *c = &a;
	int *const d = &a;
	const int *const e = &a;
	int const *const f = &a;

	cout<<*b<<endl;
	cout<<*c<<endl;
	cout<<*d<<endl;
	cout<<*e<<endl;
	cout<<*f<<endl;

	return 0;
}
