// Spiral Matrix Total Accepted: 30911 Total Submissions: 148791 My Submissions Question Solution
// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

// For example,
// Given the following matrix:

// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix)
	{
		vector<int> result;

		if(matrix.empty())
			return result;

		int uRow = 0,    lCol = 0; //行标、列表的下界(最小)
		int dRow = matrix.size()-1, rCol = matrix[0].size()-1; //行标、列表的上界(最大)

		while(uRow<=dRow && lCol<=rCol)
		{
			for(int i=lCol; i<=rCol; i++)
			{
				result.push_back(matrix[uRow][i]);
			}
			uRow++;
			for(int i=uRow; i<=dRow; i++)
			{
				result.push_back(matrix[i][rCol]);
			}
			rCol--;

			if(uRow > dRow || lCol > rCol) // 任意下界大于上界，则终止
				break;

			for(int i=rCol; i>=lCol; i--)
			{
				result.push_back(matrix[dRow][i]);
			}
			dRow--;
			for(int i=dRow; i>=uRow; i--)
			{
				result.push_back(matrix[i][lCol]);
			}
			lCol++;
		}
		return result;
	}
};

int main()
{
	Solution solution;
	vector<vector<int> > matrix;
	vector<int> row;
	vector<int> result;
	int m, n, number;
	while(cin>>m>>n)
	{
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin>>number;
				row.push_back(number);
			}
			matrix.push_back(row);
			row.clear();
		}
		result = solution.spiralOrder(matrix);

		cout<<"input: "<<n*m<<", output: "<<result.size()<<endl;
		for(int i=0; i<result.size(); i++)
		{
			cout<<result[i]<<" ";
		}
		cout<<endl<<"----------------"<<endl;
		result.clear();
		matrix.clear();
	}
	return 0;
}
