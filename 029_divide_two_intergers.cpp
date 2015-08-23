// Divide Two Integers Total Accepted: 36922 Total Submissions: 244420 My Submissions Question Solution
// Divide two integers without using multiplication, division and mod operator.

// If it is overflow, return MAX_INT.

#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
    	if(divisor == 0)
    		return (dividend >= 0) ? INT_MAX : INT_MIN;
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long dividend_t = abs((long)dividend);
        long divisor_t = abs((long)divisor);

        // cout<<"dividend_t = "<<dividend_t<<endl;
        // cout<<"divisor_t = "<<divisor_t<<endl;

        if(dividend_t < divisor_t)
            return 0;

        bool negative = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0); //负为true，正为false

        // cout<<"negative = "<<negative<<endl;

        int result = 0;
        int shift = 0;

    	while(dividend_t >= divisor_t)
    	{
            shift = 0;
            while((dividend_t>>shift) >= divisor_t)
            {
                shift++;
            }
            dividend_t -= divisor_t << (shift - 1);
            result += 1 << (shift - 1);
    	}
        return negative? -result:result;
    }
};

int main()
{
    Solution solution;

    int dividend, divisor;
    int result;
    while(cin>>dividend>>divisor)
    {
        result = solution.divide(dividend, divisor);
        cout<<result<<endl;
    }
	return 0;
}
