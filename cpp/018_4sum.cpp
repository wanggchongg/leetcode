// 4Sum Total Accepted: 32633 Total Submissions: 152084 My Submissions Question Solution
// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
// The solution set must not contain duplicate quadruplets.
//     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

//     A solution set is:
//     (-1,  0, 0, 1)
//     (-2, -1, 1, 2)
//     (-2,  0, 0, 2)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static vector<vector<int> > fourSum(vector<int> &num, int target) {
    	vector<vector<int> > result;
    	if(num.size() < 4) return result;
    	sort(num.begin(), num.end());
    	int sum;
    	int i, j, k, l;
    	vector<int> member;
    	for(i=0; i<num.size()-3; i++)
    	{
    		if(i>0 && num[i] == num[i-1])
    			continue;
            for(j=i+1; j<num.size()-2; j++)
            {
                if(j>i+1 && num[j] == num[j-1])
                    continue;
                k = j+1;
        		l = num.size()-1;

        		while(k<l)
        		{
        			sum = num[i]+num[j]+num[k]+num[l];
        			if(sum == target)
        			{
        				member.push_back(num[i]);
        				member.push_back(num[j]);
        				member.push_back(num[k]);
                        member.push_back(num[l]);
        				result.push_back(member);
        				member.clear();
        				k++;
        				while(num[k] == num[k-1])
        					k++;
    				}
    				else if(sum < target)
    				{
    					k++;
    					while(num[k] == num[k-1])
        					k++;
    				}
    				else
    				{
    					l--;
    					while(num[l] == num[l+1])
        					l--;
    				}
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
    int target;
	while(cin>>n)
	{
        cin>>target;
		for(int i=0; i<n; i++)
		{
			cin>>number;
			num.push_back(number);
		}

		result = Solution::fourSum(num, target);
		num.clear();
		for(int i=0; i<result.size(); i++)
		{
			cout<<result[i][0]<<", "<<result[i][1]<<", "<<result[i][2]<<", "<<result[i][3]<<endl;
		}
		cout<<"-----------------"<<endl;
	}

	return 0;
}