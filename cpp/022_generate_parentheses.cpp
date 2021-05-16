// Generate Parentheses Total Accepted: 44578 Total Submissions: 137341 My Submissions Question Solution
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// "((()))", "(()())", "(())()", "()(())", "()()()"

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	//回溯法
	void getParenthese(vector<string> &result, string pth, int left, int right)
	{
		if(left > right || left < 0 || right < 0) //如果没有left>right，则是全解空间
			//left>right 说明不允许出现的右括号比左括号多
			return;
		if(left == 0 && right == 0)
		{
			result.push_back(pth);
			return;
		}
		getParenthese(result, pth+"(", left-1, right);
		getParenthese(result, pth+")", left, right-1);
	}

    vector<string> generateParenthesis(int n) {
    	vector<string> result;
    	if(n <= 0)
    		return result;
    	getParenthese(result, "", n, n);
    	return result;
    }
};

int main()
{
	Solution solution;
	vector<string> result;
	int n;
	while(cin>>n)
	{
		result = solution.generateParenthesis(n);
		for(int i=0; i<result.size(); i++)
		{
			cout<<result[i]<<", ";
		}
		cout<<endl;
		result.clear();
	}
	return 0;
}
