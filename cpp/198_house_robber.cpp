// House Robber Total Accepted: 7443 Total Submissions: 26156 My Submissions Question Solution
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

//01背包问题
#include <iostream>
#include <vector>
using namespace std;
#define max(x, y) ((x>=y)?x:y)

class Solution {
private:
	int robMoney(int count, vector<int> &money, vector<int> &num)
	{
		int retMaxMoney = 0;

		if(count >= 0)
		{
			if(money[count] != -1) //读备忘录
			{
				retMaxMoney = money[count];
			}
			else if(count == 0) //边界条件
			{
				retMaxMoney = num[count];
			}
			else //子问题/状态转移方程
			{
				retMaxMoney = max(robMoney(count-2, money, num)+num[count], robMoney(count-1, money, num));
			}
			money[count] = retMaxMoney; //写备忘录
		}
		return retMaxMoney;
	}

public:
    int rob(vector<int> &num) {
    	vector<int> money(num.size(), -1);
		return	robMoney(num.size()-1, money, num);
	}
};

int main()
{
	Solution solution;
	vector<int> num;
	int n;
	while(cin>>n)
	{
		int m = 0;
		for(int i=0; i<n; i++)
		{
			cin>>m;
			num.push_back(m);
		}
		cout<<"money="<<solution.rob(num)<<endl;
		num.clear();
	}
	return 0;
}
