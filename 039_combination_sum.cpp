// Combination Sum Total Accepted: 45321 Total Submissions: 162155 My Submissions Question Solution
// Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2,3,6,7 and target 7,
// A solution set is:
// [7]
// [2, 2, 3]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void DFS(int sum, int index, vector<int> &comb, vector<vector<int> > &result, vector<int> &candidates, int target)
	{
		if(sum == target)
		{
			result.push_back(comb);
			return;
		}
		else if(sum > target)
		{
			return;
		}

		for(int i=index; i<candidates.size(); i++)
		{
			comb.push_back(candidates[i]);
			DFS(sum+candidates[i], i, comb, result, candidates, target);
			comb.pop_back();
		}
	}

    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        DFS(0, 0, comb, result, candidates, target);

        return result;
    }
};

class Solution1 {
public:
	void DFS(int index, vector<int> &comb, vector<vector<int> > &result, vector<int> &candidates, int target)
	{
		if(target == 0)
		{
			result.push_back(comb);
			return;
		}
		else if(target < 0)
		{
			return;
		}

		for(int i=index; i<candidates.size(); i++)
		{
			comb.push_back(candidates[i]);
			DFS(i, comb, result, candidates, target-candidates[i]);
			comb.pop_back();
		}
	}

    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        DFS(0, comb, result, candidates, target);

        return result;
    }
};

int main()
{
	Solution1 solution;
	vector<vector<int> >result;
	vector<int> candidates;
	int n, target;
	int num;

	while(cin>>n>>target)
	{
		for(int i=0; i<n; i++)
		{
			cin>>num;
			candidates.push_back(num);
		}
		result = solution.combinationSum(candidates, target);
		for(int i=0; i<result.size(); i++)
		{
			for(int j=0; j<result[i].size(); j++)
				cout<<result[i][j]<<" ";
			cout<<endl;
		}
		cout<<"---------------------"<<endl;
		result.clear();
		candidates.clear();
	}
	return 0;
}
