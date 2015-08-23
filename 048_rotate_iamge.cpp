// Rotate Image Total Accepted: 36216 Total Submissions: 113389 My Submissions Question Solution
// You are given an n x n 2D matrix representing an image.

// Rotate the image by 90 degrees (clockwise).

// Follow up:
// Could you do this in-place?

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
    	vector<vector<int> > matrix_1 = matrix;
    	int size = matrix.size();
    	for(int i=0; i<size; i++)
    	{
    		for(int j=0; j<size; j++)
    		{
    			matrix[j][size-i-1] = matrix_1[i][j];
    		}
    	}
    }
};

class Solution1 {
public:
	void rotate(vector<vector<int> >& matrix)
	{
		int size = matrix.size();

		for(int i=0; i<size/2; i++)
		{
			for(int j=0; j<(size+1)/2; j++)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[size-1-j][i];
				matrix[size-1-j][i] = matrix[size-1-i][size-1-j];
				matrix[size-1-i][size-1-j] = matrix[j][size-1-i];
				matrix[j][size-1-i] = temp;
			}
		}
	}
};

int main()
{
	Solution1 solution;
	vector<vector<int> > matrix;
	vector<int> row;
	int n, number;
	while(cin>>n)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin>>number;
				row.push_back(number);
			}
			matrix.push_back(row);
			row.clear();
		}
		solution.rotate(matrix);

		for(int i=0; i<n; i++)
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
