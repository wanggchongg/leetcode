// Pascal's Triangle Total Accepted: 44653 Total Submissions: 147964 My Submissions Question Solution
// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return

// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

//最大只能到34层
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    static vector<vector<int> > generate(int numRows);
};

vector<vector<int> > Solution::generate(int numRows)
{
	vector<vector<int> > result;
	if(numRows<1) return result;
	vector<int> rowValue;
	int temp = 0;
	rowValue.push_back(1);
	result.push_back(rowValue);
	rowValue.clear();
	if(numRows == 1) return result;
	for(int i=1; i<numRows; i++)
	{
		rowValue.push_back(1);
		for(int j=1; j<i; j++)
		{
			temp = result[i-1][j-1] + result[i-1][j];
			rowValue.push_back(temp);
		}
		rowValue.push_back(1);
		result.push_back(rowValue);
		rowValue.clear();
	}
	return result;
}

int main()
{
	vector<vector<int> > result;
	result = Solution::generate(34);

	for(int i = 0; i<result.size(); i++)
	{
		for(int j = 0; j<result[i].size(); j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

