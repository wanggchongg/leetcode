// Anagrams Total Accepted: 36232 Total Submissions: 148404 My Submissions Question Solution
// Given an array of strings, return all groups of strings that are anagrams.

// Note: All inputs will be in lower-case

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

//借助sort函数排序后的string做索引
class Solution {
	vector<string> anagrams(vector<string> &strs)
	{
		vector<string> result;
		map<string, int> contain;
		string temp;
		for(int i=0; i<strs.size(); i++)
		{
			temp = strs[i];
			sort(temp.begin(), temp.end());
			contain[temp]++;
		}

		for(int i=0; i<strs.size(); i++)
		{
			temp = strs[i];
			sort(temp.begin(), temp.end());
			if(contain[temp] > 1)
				result.push_back(strs[i]);
		}
		return result;
	}
};

//借助hash函数生成hash值做索引
class Solution1 {
public:
	long getHash(vector<int> &count)
	{
		long hash = 0;
		long a = 378551;
		long b = 63689;
		for(int i=0; i<count.size(); i++)
		{
			hash = hash * a + count[i];
			a = a *b;
		}
		return hash;
	}

	vector<string> anagrams(vector<string> &strs)
	{
		vector<string> result;
		multiset<long> contain;
		vector<long> hash;
		long temp;
		for(int i=0; i<strs.size(); i++)
		{
			vector<int> count(26, 0);
			for(int j=0; j<strs[i].size(); j++)
			{
				count[strs[i][j]-'a']++;
			}

			temp = getHash(count);
			hash.push_back(temp);
			contain.insert(temp);
		}

		for(int i=0; i<strs.size(); i++)
		{
			if(contain.count(hash[i]) > 1)
				result.push_back(strs[i]);
		}
		return result;
	}
};

int main()
{
	Solution1 solution;
	vector<string> strs;
	vector<string> result;
	string str;
	int n;
	while(cin>>n)
	{
		for(int i=0; i<n; i++)
		{
			cin>>str;
			strs.push_back(str);
		}
		result = solution.anagrams(strs);
		for(int i=0; i<result.size(); i++)
			cout<<result[i]<<endl;
		strs.clear();
	}

	return 0;
}