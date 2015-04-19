// Climbing Stairs Total Accepted: 49251 Total Submissions: 144283 My Submissions Question Solution
// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

//斐波那契数列
#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    	if(n <= 2) return n;

    	int way = 0, first = 1, second = 2;
    	for(int i=2; i<n; i++)
    	{
    		way = first + second;
    		first = second;
    		second = way;
    	}
    	return way;
    }
};

int main()
{
	return 0;
}