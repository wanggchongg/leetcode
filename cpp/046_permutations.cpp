// Permutations Total Accepted: 50590 Total Submissions: 158436 My Submissions Question Solution
// Given a collection of numbers, return all possible permutations.

// For example,
// [1,2,3] have the following permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

#include <iostream>
#include <vector>
using namespace std;

class Solution { //计算可重复的permutation的个数，再采用标准库的next_permutation函数
public:
    vector<vector<int> > permute(vector<int>& nums) {
    	vector<int> next;
    	vector<vector<int> > result;
    	next = nums;

    	int limit = 1;
    	for(int i=1; i<=nums.size(); i++)
    	{
    		limit *= i;
    	}
    	for(int i=0; i<limit; i++)
    	{
	    	next_permutation(next.begin(), next.end());
	    	result.push_back(next);
    	}
    	return result;
    }
};

class Solution1 { //计算可重复的permutation的个数，再算出nextPermutation
public:
	void nextPermutation(vector<int> &nums)
	{
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

	vector<vector<int> > permute(vector<int>& nums) {
    	vector<int> next;
    	vector<vector<int> > result;
    	next = nums;

    	int limit = 1;
    	for(int i=1; i<=nums.size(); i++)
    	{
    		limit *= i;
    	}
    	for(int i=0; i<limit; i++)
    	{
	    	nextPermutation(next);
	    	result.push_back(next);
    	}
    	return result;
    }
};

class Solution2 { //回溯法
public:
    void DFS(vector<int> &no, vector<int> &temp, vector<vector<int> > &result, vector<int> &nums, int deep)
    {
        if(deep == nums.size())
        {
            result.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++)
        {
            bool flag = false;
            for(int j=0; j<no.size(); j++) //判断是否和上层节点是重复的
            {
                if(i == no[j])
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                continue;

            temp.push_back(nums[i]);
            no.push_back(i);
            DFS(no, temp, result, nums, deep+1);
            temp.pop_back();
            no.pop_back();
        }
    }

    vector<vector<int> > permute(vector<int>& nums) {
        vector<int> next;
        vector<vector<int> > result;
        vector<int> no;
        DFS(no, next, result, nums, 0);
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int> >result;
    vector<int> nums;
    int n;
    int num;

    while(cin>>n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>num;
            nums.push_back(num);
        }
        result = solution.permute(nums);
        for(int i=0; i<result.size(); i++)
        {
            for(int j=0; j<result[i].size(); j++)
                cout<<result[i][j]<<" ";
            cout<<endl;
        }
        cout<<"---------------------"<<endl;
        result.clear();
        nums.clear();
    }
	return 0;
}
