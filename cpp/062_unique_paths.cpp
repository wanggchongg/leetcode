// Unique Paths Total Accepted: 47992 Total Submissions: 146180 My Submissions Question Solution
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?


// Above is a 3 x 7 grid. How many possible unique paths are there?

// Note: m and n will be at most 100.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n)
	{
		if(m<1 || n<1)
			return 0;
		vector<vector<int> > dp;
		for(int i=0; i<m; i++)
		{
			vector<int> row(n, 1);
			dp.push_back(row);
		}

		for(int i=1; i<m; i++)
		{
			for(int j=1; j<n; j++)
			{
				dp[i][j] = dp[i][j-1] + dp[i-1][j];
			}
		}
		return dp[m-1][n-1];
	}
};

int main()
{
	Solution solution;
	int m, n;
	while(cin>>m>>n)
	{
		cout<<solution.uniquePaths(m, n)<<endl;
	}
	return 0;
}
