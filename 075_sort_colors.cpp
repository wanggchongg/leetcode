// Sort Colors Total Accepted: 56513 Total Submissions: 173650 My Submissions Question Solution
// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

// Note:
// You are not suppose to use the library's sort function for this problem.

// click to show follow up.

// Follow up:
// A rather straight forward solution is a two-pass algorithm using counting sort.
// First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

// Could you come up with an one-pass algorithm using only constant space?

#include <iostream>
#include <vector>
using namespace std;

//time: o(3*n)
class Solution {
public:
    void sortColors(vector<int>& nums) {
    	int first = 0, second = 0;

    	while(second < nums.size())
    	{
    		if(nums[second] == 0)
    		{
    			int temp = nums[second];
    			nums[second] = nums[first];
    			nums[first] = temp;
    			first ++;
    		}
    		second ++;
    	}

    	second = first;
    	while(second < nums.size())
    	{
    		if(nums[second] == 1)
    		{
    			int temp = nums[second];
    			nums[second] = nums[first];
    			nums[first] = temp;
    			first ++;
    		}
    		second ++;
    	}

    	second = first;
    	while(second < nums.size())
    	{
    		if(nums[second] == 2)
    		{
    			int temp = nums[second];
    			nums[second] = nums[first];
    			nums[first] = temp;
    			first++;
    		}
    		second ++;
    	}
    }
};

//time: o(n)
class Solution1 {
public:
    void sortColors(vector<int>& nums) {
    	int head = 0, tail = nums.size()-1;
    	int index = 0;

    	while(index <= tail)
    	{
    		if(nums[index] == 0)
    		{
    			int temp = nums[index];
    			nums[index] = nums[head];
    			nums[head] = temp;
    			index++;
    			head++;
    		}
    		else if(nums[index] == 1)
    		{
    			index++;
    		}
    		else
    		{
    			int temp = nums[index];
    			nums[index] = nums[tail];
    			nums[tail] = temp;
    			tail--;
    		}
    	}
    }
};

int main()
{
	Solution solution;

	vector<int> nums;
	int n;
	int value;
	while(cin>>n)
	{
		for(int i=0; i<n; i++)
		{
			cin>>value;
			nums.push_back(value);
		}
		solution.sortColors(nums);

		for(int i=0; i<n; i++)
		{
			cout<<nums[i]<<" ";
		}
		cout<<endl;
		nums.clear();
	}
	return 0;
}