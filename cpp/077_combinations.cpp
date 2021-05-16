// Combinations Total Accepted: 46018 Total Submissions: 148891 My Submissions Question Solution
// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// For example,
// If n = 4 and k = 2, a solution is:

// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > result;
		vector<int> temp;
		DFS(1, n, k, temp, result);
		return result;
	}

	void DFS(int index, int &n, int &k, vector<int> &temp, vector<vector<int> > &result) {
		if (temp.size() == k) {
			result.push_back(temp);
			return;
		}

		for (int i = index; i <= n; i++) {
			temp.push_back(i);
			DFS(i+1, n, k, temp, result);
			temp.pop_back();
		}
	}
};

int main() {
	Solution solution;
	int n, k;
	vector<vector<int> > result;
	while(cin>>n>>k) {
		result = solution.combine(n, k);
		for (int i = 0; i < result.size(); i++) {
			for (int j = 0; j < k; j++) {
				cout << result[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}