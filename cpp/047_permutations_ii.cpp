// Permutations Total Accepted: 50590 Total Submissions: 158436 My Submissions Question Solution
// Given a collection of numbers, return all possible permutations.

// For example,
// [1,2,3] have the following permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution { //回溯法
public:
    void DFS(vector<int> &visited, vector<int> &temp, vector<vector<int> > &result, vector<int> &nums)
    {
        if(temp.size() == nums.size())
        {
            result.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++)
        {
            //被遍历过的，和上一个元素值相同并且上一个元素没有遍历的
            if(visited[i] == 1 || (i !=0 && nums[i] == nums[i-1] && visited[i-1] == 1))
                continue;
            cout<<"i="<<i<<"nums[i]="<<nums[i]<<endl;
            visited[i] = 1;
            temp.push_back(nums[i]);
            DFS(visited, temp, result, nums);
            temp.pop_back();
            visited[i] = 0;
        }
    }

    vector<vector<int> > permuteUnique(vector<int>& nums) {
    	vector<vector<int> > result;
        vector<int> visited(nums.size(), 0);
        vector<int> temp;
        sort(nums.begin(), nums.end());
        DFS(visited, temp, result, nums);
    	return result;
    }
};

class Solution1 { //计算不可重复的permutation的个数，再采用标准库的next_permutation函数
public:
    long factor(long n)
    {
        if(n < 2)
            return 1;
        long result = 1;
        for(int i=1; i<=n; i++)
        {
            result *= i;
        }
        return result;
    }

    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<int> next;
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        next = nums;

        long demo = 1;
        long memb = 1;
        long count = 1;
        for(int i=0; i<next.size(); i++)
        {
            if(i !=0 && next[i] == next[i-1])
                count++;
            else
            {
                memb *= factor(count);
                count = 1;
            }
        }
        if(count > 1)
            memb *= factor(count);
        demo = factor(next.size());
        count = demo/memb; //不可重复的permutation的个数
        for(int i=0; i<count; i++)
        {
            next_permutation(next.begin(), next.end());
            result.push_back(next);
        }
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
        result = solution.permuteUnique(nums);
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
