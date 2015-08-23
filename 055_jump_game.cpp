// Jump Game Total Accepted: 43478 Total Submissions: 160039 My Submissions Question Solution
// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

// For example:
// A = [2,3,1,1,4], return true.

// A = [3,2,1,0,4], return false.

#include <iostream>
#include <vector>
using namespace std;

//回溯算法
//会出现超时情况
class Solution {
public:

	bool DFS(int index, vector<int> &nums)
	{
		if(index == nums.size()-1)
			return true;
		if(nums[index] == 0 || index > nums.size()-1)
			return false;

		for(int i=nums[index]; i>0; i--)
		{
			if(DFS(index+i, nums))
				return true;
		}
		return false;
	}

    bool canJump(vector<int>& nums) {
    	if(nums.size() <= 1)
    		return true;

    	if(DFS(0, nums))
    		return true;
    	return false;
    }
};


//用贪心策略，刚开始step = A[0]，到下一步step--, 并且取step = max(step, A[1])，这样step一直是保持最大的能移动步数，局部最优也是全局最优。
class Solution1 {
public:
    bool canJump(vector<int>& nums) {
    	if(nums.size() <= 1)
    		return true;

    	int step = nums[0];
    	for(int i=1; i<nums.size(); i++)
    	{
    		if(step > 0)
    		{
    			step--;
    			step = max(step, nums[i]);
    		}
    		else
    			return false;
    	}

    	return true;
    }
};

int main()
{
	Solution solution;
	vector<int> nums;
	int n, number;
	while(cin>>n)
	{
		for(int i=0; i<n; i++)
		{
			cin>>number;
			nums.push_back(number);
		}
		cout<<solution.canJump(nums)<<endl;
		nums.clear();
	}
	return 0;
}
