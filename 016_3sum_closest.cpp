// 3Sum Closest Total Accepted: 35748 Total Submissions: 132728 My Submissions Question Solution
// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

//     For example, given array S = {-1 2 1 -4}, and target = 1.

//     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution { //时间复杂度O(n^2)
//先排序，再采用三指针，第一个指针轮询，第二三指针前后逼近
public:
    static int threeSumClosest(vector<int> &num, int target) {
    	if(num.size()<3) return INT_MAX;
    	sort(num.begin(), num.end());

    	int result = 0, sum = 0, distance = INT_MAX;
    	int i, j, k;
    	for(i=0; i<num.size()-2; i++)
    	{
    		j=i+1, k=num.size()-1;
    		while(j<k)
    		{
    			sum = num[i] + num[j] + num[k];
    			if(sum == target) return sum;
    			else if(sum < target)
    			{
    				if((target-sum) < distance)
    				{
    					result = sum;
    					distance = target - sum;
    				}
    				j++;
    			}
    			else
    			{
    				if((sum-target) < distance)
    				{
    					result = sum;
    					distance = sum - target;
    				}
    				k--;
    			}
    		}
    	}
    	return result;
    }
};

int main()
{
	int n;
	while(cin>>n)
	{
		vector<int> result;
		int num;
		for(int i=0; i<n; i++)
		{
			cin>>num;
			result.push_back(num);
		}
		cout<<Solution::threeSumClosest(result, 1)<<endl;
	}
	return 0;
}
