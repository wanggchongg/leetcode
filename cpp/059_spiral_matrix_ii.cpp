// Spiral Matrix II Total Accepted: 29598 Total Submissions: 93275 My Submissions Question Solution
// Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

// For example,
// Given n = 3,

// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
	vector<vector<int> > generateMatirx(int n)
	{
		vector<vector<int> > matrix;
		vector<int> nums(n, 0);
		for(int i=0; i<n; i++)
		{
			matrix.push_back(nums);
		}

		int uRow = 0,    lCol = 0; //行标、列表的下界(最小)
		int dRow = n-1, rCol = n-1; //行标、列表的上界(最大)
		int count = 1;

		while(uRow<=dRow && lCol<=rCol)
		{
			for(int i=lCol; i<=rCol; i++)
			{
				matrix[uRow][i] = count;
				count++;
			}
			uRow++;
			for(int i=uRow; i<=dRow; i++)
			{
				matrix[i][rCol] = count;
				count++;
			}
			rCol--;

			if(uRow > dRow || lCol > rCol) // 任意下界大于上界，则终止
				break;

			for(int i=rCol; i>=lCol; i--)
			{
				matrix[dRow][i] = count;
				count++;
			}
			dRow--;
			for(int i=dRow; i>=uRow; i--)
			{
				matrix[i][lCol] = count;
				count++;
			}
			lCol++;
		}
		return matrix;
	}
};

int main()
{
	Solution solution;
	vector<vector<int> > matrix;
	int n = 0;
	while(cin>>n)
	{
		matrix = solution.generateMatirx(n);
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				cout<<matrix[i][j]<<" ";
			cout<<endl;
		}
		matrix.clear();
	}
	return 0;
}
