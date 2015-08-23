// Combination Sum II Total Accepted: 35090 Total Submissions: 139535 My Submissions Question Solution
// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// Each number in C may only be used once in the combination.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 10,1,2,7,6,1,5 and target 8,
// A solution set is:
// [1, 7]
// [1, 2, 5]
// [2, 6]
// [1, 1, 6]

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
			if(i > index && candidates[i] == candidates[i-1])
			{
				continue;
			}
			comb.push_back(candidates[i]);
			DFS(sum+candidates[i], i+1, comb, result, candidates, target);
			comb.pop_back();
		}
	}

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
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
			if(i > index && candidates[i] == candidates[i-1])
			{
				continue;
			}
			comb.push_back(candidates[i]);
			DFS(i+1, comb, result, candidates, target-candidates[i]);
			comb.pop_back();
		}
	}

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        DFS(0, comb, result, candidates, target);

        return result;
    }
};

int main()
{
	Solution solution;
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
		result = solution.combinationSum2(candidates, target);
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
