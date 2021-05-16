#include <iostream>
using namespace std;

//举例：
// 2 |  8  6
//   ----------
//      4  3
// 所以：gcd=2，lcm=2*4*3=24

//求最大公约数：辗转相除法
// 1. a ÷ b，令r为所得余数（0≤r<b）
// 若 r = 0，算法结束；b 即为答案。
// 2. 互换：置 a←b，b←r，并返回第一步
int gcd1(int m, int n)
{
	int r;
	while(n)
	{
		r = m % n;
		m = n;
		n = r;
	};
	return m;
}

int gcd2(int m, int n)
{
	if(n)
		return gcd1(n, m % n);
	else
		return m;
}

//求最小公倍数：公式法
//由于两个数的乘积等于这两个数的最大公约数与最小公倍数的积。即（a，b）× [a，b] = a × b。
//所以，求两个数的最小公倍数，就可以先求出它们的最大公约数，然后用上述公式求出它们的最小公倍数。
int lcm(int m, int n)
{
	return (m*n)/gcd1(m, n);
}


int main()
{
	int m, n;
	cout<<"input two numbers:"<<endl;
	while(cin>>m)
	{
		cin>>n;
		if(m<=0 || n<=0)
		{
			cerr<<"error input!!!"<<endl;
			cout<<"input two numbers:"<<endl;
			continue;
		}
		cout<<"gcd("<<m<<", "<<n<<")="<<gcd1(m, n)<<endl;
		cout<<"lcm("<<m<<", "<<n<<")="<<lcm(m, n)<<endl;
		cout<<"input two numbers:"<<endl;
	}
	return 0;
}
