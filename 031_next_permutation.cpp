// Next Permutation Total Accepted: 34745 Total Submissions: 138968 My Submissions Question Solution
// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

// The replacement must be in-place, do not allocate extra memory.

// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 函数实现原理如下：
// 	在当前序列中，从尾端往前寻找两个相邻元素，前一个记为*i，后一个记为*ii，并且满足*i < *ii。然后再从尾端寻找另一个元素*j，如果满足*i < *j，即将第i个元素与第j个元素对调，并将第ii个元素之后（包括ii）的所有元素颠倒排序，即求出下一个序列了。
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	if(nums.size() == 0 || nums.size() == 1)
    		return;

    	int i = nums.size()-1;
    	while(i) //从右边找到第一个降序数字
    	{
    		if(nums[i] > nums[i-1])
    			break;
    		i--;
    	}
    	if(i)
    	{
    		i--; //从右边数第一个降序数字的右边一个数字
    		int j = nums.size()-1;
    		while(nums[i] >= nums[j]) //从右边找第一个比上述i指代数字大的数
    		{
    			j--;
    		}

    		//上述两个数字交换
    		nums[i] = nums[i] ^ nums[j];
    		nums[j] = nums[i] ^ nums[j];
    		nums[i] = nums[i] ^ nums[j];

    		//反转i指代数字右边的数字串
    		reverse(nums.begin()+i+1, nums.end());
    	}
    	else
    		reverse(nums.begin(), nums.end());
    }
};

class Solution {
public:
	void nextPermutation(vector<int>& nums)
	{
		next_permutation(nums.begin(), nums.end());
	}
};

int main()
{
	Solution solution;
	vector<int> nums;
	int input;
	int n;
	while(cin>>n)
	{
		for(int i=0; i<n; i++)
		{
			cin>>input;
			// cout<<input<<" ";
			nums.push_back(input);
		}
		cout<<endl;
		solution.nextPermutation(nums);
		for(int i=0; i<n; i++)
		{
			cout<<nums[i]<<", ";
		}
		cout<<endl;
		nums.clear();
	}
	return 0;
}