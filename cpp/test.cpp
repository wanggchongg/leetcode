#include <iostream>

using namespace std;

int main()
{
	const double &rtr = 3.14;
	const double pi = 3.14;
	const double *const ptr = &pi;

	const double *const p3 = &pi;

	double *p4;
	p4 = &pi;
	cout<<*ptr<<endl;
}