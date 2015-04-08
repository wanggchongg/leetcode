// Factorial Trailing Zeroes

// Given an integer n, return the number of trailing zeroes in n!.

// Note: Your solution should be in logarithmic time complexity.

// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.


//思路：
//1.求解n!尾数0的个数，即求n!的质因子中2和5个数的最小值
//2.进一步：只需求n中偶数的质因子2的个数和5倍数的质因子5的个数，再求最小值
//3.进一步：因为质因子5的个数肯定小于2的个数，只需要求所有5倍数的质因子5的个数
//4.进一步：所有5倍数的质因子个数就等于[n/5](n除以5，除以到n至0的商和)

#include <iostream>
using namespace std;

class Solution {
public:
    static int trailingZeroes(int n);
};

// int Solution::trailingZeroes(int n)
// {
// 	int result = 1;
// 	int count_2 = 0;
// 	int count_5 = 0;

// 	if(n<5) return 0;
// 	for(int i=2; i<=n; i+=2)
// 	{
// 		int temp = 0;
// 		temp = i;
// 		while(temp%2==0)
// 		{
// 			count_2++;
// 			temp /= 2;
// 		}
// 	}

// 	for(int i=5; i<=n; i+=5)
// 	{
// 		int temp = 0;
// 		temp = i;
// 		while(temp%5==0)
// 		{
// 			count_5++;
// 			temp /= 5;
// 		}
// 	}

// 	result = (count_2<count_5)?count_2:count_5;
// 	return result;
// }

// int Solution::trailingZeroes(int n)
// {
// 	int count_5 = 0;

// 	for(int i=5; i<=n; i+=5)
// 	{
// 		int temp = 0;
// 		temp = i;
// 		while(temp%5==0)
// 		{
// 			count_5++;
// 			temp /= 5;
// 		}
// 	}
// 	return count_5;
// }

int Solution::trailingZeroes(int n)
{
	int count_5 = 0;

	while(n)
	{
		count_5 += n/5;
		n /= 5;
	}
	return count_5;
}

int main()
{
	int result;
	result = Solution::trailingZeroes(3);
	cout<<result<<endl;
	return 0;
}
