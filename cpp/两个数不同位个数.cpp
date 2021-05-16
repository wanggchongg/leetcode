#include <iostream>
using namespace std;

int func(int x, int y)
{
	int z = x ^ y;
	int count = 0;
	while(z)
	{
		count++;
		z = z & (z-1);
	}
	return count;
}

int main()
{
	cout<<func(10, 11)<<endl;
	return 0;
}
