// Pow(x, n) Total Accepted: 50149 Total Submissions: 187708 My Submissions Question Solution
// Implement pow(x, n).

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
    	return pow(x, n);
    }
};

//改善的pow函数(借助折半)
class Solution1 {
public:
    double myPow(double x, int n) {
    	if(n == 0)
    		return 1;
    	if(n == 1)
    		return x;
    	bool isReci = false;
    	if(n < 0)
    	{
    		isReci = true;
    		n *= -1;
    	}

    	int k = n/2;
    	int l = n - k * 2;

    	double t1 = pow(x, k);
    	double t2 = pow(x, l);

    	if(isReci)
    		return 1 / (t1 * t1 * t2);
    	else
    		return t1 * t1 *t2;
    }
};

int main()
{
	Solution1 solution;
	int x, n;
	while(cin>>x>>n)
	{
		cout<<solution.myPow(x, n)<<endl;
		cout<<"---------------"<<endl;
	}
	return 0;
}
