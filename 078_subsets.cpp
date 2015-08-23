// Subsets Total Accepted: 54404 Total Submissions: 193186 My Submissions Question Solution
// Given a set of distinct integers, nums, return all possible subsets.

// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If nums = [1,2,3], a solution is:

// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]


#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
	vector<vector<int> > subsets(vector<int> &nums) {
		vector<vector<int> > result;
		vector<int> temp;
		sort(nums.begin(), nums.end());
		for (int i = 0; i <= nums.size(); i++) {
			DFS(0, nums, i, temp, result);
		}

		return result;
	}

	void DFS(int index, vector<int> &nums, int &k, vector<int> &temp, vector<vector<int> > &result) {
		if (temp.size() == k) {
			result.push_back(temp);
			return;
		}

		for (int i = index; i < nums.size(); i++) {
			temp.push_back(nums[i]);
			DFS(i+1, nums, k, temp, result);
			temp.pop_back();
		}
	}
};

int main() {
	Solution solution;
	vector<int> nums;
	vector<vector<int> > result;
	int n;
	int value;
	while(cin>>n) {
		for(int i = 0; i < n; i++) {
			cin >> value;
			nums.push_back(value);
		}
		result = solution.subsets(nums);
		for (int i = 0; i < result.size(); i++) {
			for (int j = 0; j < result[i].size(); j++) {
				cout << result[i][j] << ", ";
			}
			cout << endl;
		}
		nums.clear();
	}
	return 0;
}
