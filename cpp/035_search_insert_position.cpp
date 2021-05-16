// Search Insert Position Total Accepted: 56062 Total Submissions: 157898 My Submissions Question Solution
// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You may assume no duplicates in the array.

// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int> &nums, int target)
	{
		int start, end, mid;

		start = 0;
		end = nums.size()-1;
		mid = start + (end - start) / 2;
		while(start <= end)
		{
			if(nums[mid] == target)
				return mid;
			else if(nums[mid] < target)
				start = mid + 1;
			else
				end = mid - 1;
			mid = start + (end - start) / 2;
		}
		return mid;
	}
};

int main()
{
	vector<int> nums;
	Solution solution;

	int n, target, num;
	int result;
	while(cin>>n>>target)
	{
		for(int i=0; i<n; i++)
		{
			cin>>num;
			nums.push_back(num);
		}
		result = solution.searchInsert(nums, target);
		cout<<result<<endl;
		nums.clear();
	}
	return 0;
}