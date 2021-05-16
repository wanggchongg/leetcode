//此方法只能求到第13层

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    static vector<vector<int> > generate(int numRows);
};

int C_n_m(int n, int m)
{
	if(n<1)
		return 1;
	long member = 1, denom = 1;
	for(int i = n-m+1; i<=n; i++)
		member *= i;
	for(int i=1; i<=m; i++)
		denom *= i;
	return member/denom;
}

vector<vector<int> > Solution::generate(int numRows)
{
	vector<vector<int> > result;
	if(numRows<1) return result;
	vector<int> rowValue;
	int temp = 0;
	for(int i=0; i<numRows; i++)
	{
		for(int j=0; j<=i; j++)
		{
			temp = C_n_m(i, j);
			rowValue.push_back(temp);
		}
		result.push_back(rowValue);
		rowValue.clear();
	}
	return result;
}

int main()
{
	vector<vector<int> > result;
	result = Solution::generate(14);

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

