#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    static string convertToTitle(int n);
};

string Solution::convertToTitle(int n)
{
	string result;
	if(n < 1)	return result;
	while(n)
	{
		n--;
		int nT = n % 26;
		char cT = 'A' + nT;
		result = cT + result;
		n /= 26;
	}
	return result;
}

int main()
{
	string s;
	s = Solution::convertToTitle(28);
	cout<<"s="<<s<<endl;
	return 0;
}
