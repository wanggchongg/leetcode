#include <iostream>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x <= 0)
			return 0;
		long low = 0;
		long high = x;

		while(high >= low) {
			long middle = low + (high - low) / 2;
			if (x < middle * middle)
				high = middle - 1;
			else
				low = middle + 1;
		}
		return (int)high;
	}
};

int main()
{
	int x = 0;
	Solution solution;
	while(cin>>x) {
		cout<<solution.mySqrt(x)<<endl;
	}
	return 0;
}