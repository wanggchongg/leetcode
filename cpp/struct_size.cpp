#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct A
{
	char a;
	int b;
	float c;
	double d;
	int *e;
	float *f;
	short g;
};

class B
{
public:
	B()
	{
		cout<<"!!!"<<endl;
	}
	virtual void func(void);
	virtual void func1(void);
};

struct C
{};

int main()
{
	cout<<"B_size:"<<sizeof(B)<<endl;
	cout<<"C_size:"<<sizeof(struct C)<<endl;
	struct A aaa;

	printf("A_size:%d\n", sizeof(aaa));
	printf("struct:%p\n", &aaa);
	printf("char:%p\n", &aaa.a);
	printf("int:%p\n", &aaa.b);
	printf("float:%p\n", &aaa.c);
	printf("double:%p\n", &aaa.d);
	printf("int*:%p\n", &aaa.e);
	printf("float*:%p\n", &aaa.f);
	printf("short:%p\n", &aaa.g);
	return 0;
}