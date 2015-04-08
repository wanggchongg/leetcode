#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
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