// Number of 1 Bits Total Accepted: 19428 Total Submissions: 52829 My Submissions Question Solution
// Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

// For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

#include <iostream>
#include <sys/types.h>
using namespace std;

class Solution1 {
public:
    static int hammingWeight(uint32_t n) {
    	int count_1 = 0;
    	while(n)
    	{
    		if(n & 0x1)
    			count_1++;
    		n >>= 1;
    	}
    	return count_1;
    }
};

class Solution2 {
public:
    static int hammingWeight(uint32_t n) {
    	int count_1 = 0;
    	while(n)
    	{
    		count_1++;
    		n = n & (n-1);
    	}
    	return count_1;
    }
};

int main()
{
	uint32_t n = 11;
	cout<<Solution2::hammingWeight(n)<<endl;
	return 0;
}
