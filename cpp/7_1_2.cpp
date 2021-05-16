#include <iostream>
using namespace std;

char *strA()
{
	char *str = "hello world";
	*str = 'a';
	return str;
}

int main()
{
	cout<<strA()<<endl;
	return 0;
}