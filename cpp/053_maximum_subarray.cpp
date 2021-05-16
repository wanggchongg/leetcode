// Maximum Subarray Total Accepted: 57573 Total Submissions: 166255 My Submissions Question Solution
// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

// For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
// the contiguous subarray [4,−1,2,1] has the largest sum = 6.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//求子数组的最大和
//利用的是dp的思想，依次遍历数组中的每个元素，把他们相加，如果加起来小于0，则
//把当前元素之和清为0，否则则和最大和比较，更新最大和，最后得到必是子数组的最大和
//时间复杂度：o(n)
int maxSum(vector<int> &num)
{
	int max_sum = 0, sum = 0;

	for(int i=0; i<num.size(); i++)
	{
		sum += num[i];
		if(sum < 0) sum = 0;
		if(sum > max_sum)
			max_sum = sum;
	}
	if(max_sum == 0) //数组中只有负数
	{
		max_sum = num[0];
		for(int i=1; i<num.size(); i++)
		{
			if(num[i]>max_sum)
				max_sum = num[i];
		}
	}
	return max_sum;
}