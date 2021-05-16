// Search for a Range Total Accepted: 43528 Total Submissions: 157760 My Submissions Question Solution
// Given a sorted array of integers, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	vector<int> result;

    	int begin = 0, end = nums.size()-1;
    	int mid = 0;
    	while(begin <= end)
    	{
    		mid = begin + (end - begin) / 2;
    		//cout<<"mid="<<mid<<endl;
    		if(nums[mid] == target)
    			break;
    		else if(nums[mid] < target)
    			begin = mid + 1;
    		else
    			end = mid - 1;
    	}

    	if(begin > end)
    	{
    		result.push_back(-1);
    		result.push_back(-1);
    	}
    	else
    	{
    		int bbegin = begin;
    		int eend = mid - 1;
    		mid = bbegin + (eend - bbegin)/2;
    		while(bbegin <= eend)
    		{
    			if(nums[mid] == target)
    				eend = mid - 1;
    			else
    				bbegin = mid + 1;
    			mid = bbegin + (eend - bbegin)/2;
    		}
    		result.push_back(mid);

    		bbegin = mid + 1;
    		eend = end;
    		mid = bbegin + (eend - bbegin)/2;
    		while(bbegin <= eend)
    		{
    			if(nums[mid] == target)
    				bbegin = mid + 1;
    			else
    				eend = mid - 1;
    			mid = bbegin + (eend - bbegin)/2;
    		}
    		result.push_back(mid-1);
    	}
    	return result;
    }
};

class Solution2 {
public:
	vector<int> searchRange(vector<int> &nums, int target)
	{
		vector<int> result;
		int start, end, mid;

		// search for left bound
		start = 0;
		end = nums.size() - 1;
		while(start + 1 < end)
		{
			mid = start + (end - start) / 2;
			if(nums[mid] == target)
				end = mid;
			else if(nums[mid] < target)
				start = mid;
			else
				end = mid;
		}

		if(nums[start] == target)
			result.push_back(start);
		else if(nums[end] == target)
			result.push_back(end);
		else
		{
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}

		// search for left bound
		start = 0;
		end = nums.size()-1;
		while(start + 1 < end)
		{
			mid = start + (end - start) / 2;
			if(nums[mid] == target)
				start = mid;
			else if(nums[mid] < target)
				start = mid;
			else
				end = mid;
		}

		if(nums[end] == target)
			result.push_back(end);
		else if(nums[start] == target)
			result.push_back(start);
		else
		{
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}

		return result;
	}
};

int main()
{
	vector<int> nums;
	int num;
	int n;
	int target;
	Solution2 solution;
	while(cin>>n>>target)
	{
		for(int i=0; i<n; i++)
		{
			cin>>num;
			nums.push_back(num);
		}
		vector<int> result = solution.searchRange(nums, target);
		cout<<"["<<result[0]<<", "<<result[1]<<"]"<<endl;
		nums.clear();
	}
	return 0;
}
