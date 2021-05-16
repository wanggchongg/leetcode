// 3Sum Total Accepted: 51825 Total Submissions: 306097 My Submissions Question Solution
// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
//     For example, given array S = {-1 0 1 2 -1 -4},

//     A solution set is:
//     (-1, 0, 1)
//     (-1, -1, 2)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static vector<vector<int> > threeSum(vector<int> &num) {
    	vector<vector<int> > result;
    	if(num.size() < 3) return result;
    	sort(num.begin(), num.end());
    	int sum;
    	int i, j, k;
    	vector<int> member;
    	for(i=0; i<num.size()-2; i++)
    	{
    		if(i>0 && num[i] == num[i-1])
    			continue;
    		j = i+1;
    		k = num.size()-1;

    		while(j<k)
    		{
    			sum = num[i]+num[j]+num[k];
    			if(sum == 0)
    			{
    				member.push_back(num[i]);
    				member.push_back(num[j]);
    				member.push_back(num[k]);
    				result.push_back(member);
    				member.clear();
    				j++;
    				while(num[j] == num[j-1])
    					j++;
				}
				else if(sum < 0)
				{
					j++;
					while(num[j] == num[j-1])
    					j++;
				}
				else
				{
					k--;
					while(num[k] == num[k+1])
    					k--;
				}
    		}
    	}
    	return result;
    }
};

int main()
{
	vector<int> num;
	vector<vector<int> >result;
	int n, number;
	while(cin>>n)
	{
		for(int i=0; i<n; i++)
		{
			cin>>number;
			num.push_back(number);
		}

		result = Solution::threeSum(num);
		num.clear();
		for(int i=0; i<result.size(); i++)
		{
			cout<<result[i][0]<<", "<<result[i][1]<<", "<<result[i][2]<<endl;
		}
		cout<<"-----------------"<<endl;
	}

	return 0;
}
