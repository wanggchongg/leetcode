#include <iostream>
using namespace std;

int main()
{
	int m=199, n=2299;
	int result = 0;
	int m_b = 0, n_b = 0;
	while(m&&n)
	{
		if((m&0x1) ^ n&(0x1))
			result++;
		m = m>>1;
		n = n>>1;
	}
	while(m)
	{
		if(m&0x1)
			result++;
		m>>=1;
	}
	while(n)
	{
		if(n&0x1)
			result++;
		n>>=1;
	}
	cout<<"bit="<<result<<endl;
	return 0;
}