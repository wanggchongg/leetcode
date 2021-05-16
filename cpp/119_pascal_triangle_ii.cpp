// Pascal's Triangle II Total Accepted: 40417 Total Submissions: 137460 My Submissions Question Solution
// Given an index k, return the kth row of the Pascal's triangle.

// For example, given k = 3,
// Return [1,3,3,1].

// Note:
// Could you optimize your algorithm to use only O(k) extra space?


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    static vector<int> getRow(int rowIndex);
};

vector<int> Solution::getRow(int rowIndex)
{
	vector<int> preRow;
	vector<int> curRow;

	if(rowIndex < 0) return curRow;
	curRow.push_back(1);
	if(rowIndex == 0) return curRow;
	for(int i=1; i<=rowIndex; i++)
	{
		preRow = curRow;
		curRow.clear();
		curRow.push_back(1);
		for(int j=1; j<i; j++)
		{
			int temp = preRow[j-1] + preRow[j];
			curRow.push_back(temp);
		}
		curRow.push_back(1);
		preRow.clear();
	}
	return curRow;
}

int main()
{
	vector<int> result;
	result = Solution::getRow(0);
	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<" ";
	cout<<endl;
	return 0;
}
