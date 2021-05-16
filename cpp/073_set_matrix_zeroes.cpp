// Set Matrix Zeroes Total Accepted: 39458 Total Submissions: 125458 My Submissions Question Solution
// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

// click to show follow up.

// Follow up:
// Did you use extra space?
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?
//
//原来以为矩阵只要有一个0，就会把这一行和这一列置为0，进而整个矩阵为0.所以只要找矩阵中是否存在0就可以了。但是不知这样的，只是根据原矩阵的0而不是置0之后重新扫描矩阵，只和原矩阵中0有关。

#include <iostream>
#include <vector>
using namespace std;

//space: o(m+n)
class Solution {
public:
	void setZeroes(vector<vector<int> >&matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		vector<bool> rows(m, false);
		vector<bool> cols(n, false);
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(matrix[i][j] == 0)
				{
					rows[i] = true;
					cols[j] = true;
				}
			}
		}

		for(int i=0; i<m; i++)
		{
			if(rows[i])
			{
				for(int j=0; j<n; j++)
				{
					matrix[i][j] = 0;
				}
			}
		}

		for(int j=0; j<n; j++)
		{
			if(cols[j])
			{
				for(int i=0; i<m; i++)
				{
					matrix[i][j] = 0;
				}
			}
		}
	}
};


//space: o(1)
class Solution1 {
public:
	void setZeroes(vector<vector<int> >&matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		bool firstRow0 = false;
		bool firstCol0 = false;

		for(int i=0; i<n; i++)
		{
			if(matrix[0][i] == 0)
			{
				firstRow0 = true;
				break;
			}
		}

		for(int i=0; i<m; i++)
		{
			if(matrix[i][0] == 0)
			{
				firstCol0 = true;
				break;
			}
		}

		for(int i=1; i<m; i++)
		{
			for(int j=1; j<n; j++)
			{
				if(matrix[i][j] == 0)
				{
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		for(int i=1; i<m; i++)
		{
			for(int j=1; j<n; j++)
			{
				if(matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			}
		}

		if(firstRow0)
		{
			for(int i=0; i<n; i++)
				matrix[0][i] = 0;
		}

		if(firstCol0)
		{
			for(int i=0; i<m; i++)
				matrix[i][0] = 0;
		}
	}
};

int main()
{
	int m, n;
	Solution1 solution;
	int data;
	vector<vector<int> > matrix;
	vector<int> row;
	while(cin>>m>>n)
	{
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin>>data;
				row.push_back(data);
			}
			matrix.push_back(row);
			row.clear();
		}
		solution.setZeroes(matrix);
		cout<<"-------------------------"<<endl;
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<"-------------------------"<<endl;
		matrix.clear();
	}
	return 0;
}