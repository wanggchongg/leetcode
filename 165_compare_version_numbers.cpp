// Compare Version Numbers Total Accepted: 18198 Total Submissions: 122137 My Submissions Question Solution
// Compare two version numbers version1 and version2.
// If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

// You may assume that the version strings are non-empty and contain only digits and the . character.
// The . character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

// Here is an example of version numbers ordering:

// 0.1 < 1.1 < 1.2 < 13.37

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	static vector<int> strToInt(string str)
	{
		vector<int> result;
		int i = 0;
		int value = 0;
		if(str[0] == '.')
			result.push_back(0);
		while(i<str.size())
		{
			if(str[i] != '.')
			{
				value *= 10;
				value += (str[i] - '0');
			}
			else
			{
				result.push_back(value);
				value = 0;
			}
			i++;
		}
		if(value)
			result.push_back(value);
		return result;
	}

    static int compareVersion(string version1, string version2)
    {
    	vector<int> v1, v2;
    	v1 = strToInt(version1);
    	v2 = strToInt(version2);

    	int i = 0, j = 0;
    	while(i<v1.size() && j<v2.size())
    	{
    		if(v1[i] > v2[j])
    			return 1;
    		if(v1[i] < v2[j])
    			return -1;
    		i++; j++;
    	}

    	if(i==v1.size() && j==v2.size())
    		return 0;
    	while(i<v1.size())
    	{
    		if(v1[i])
    			return 1;
    		i++;
    	}
    	while(j<v2.size())
    	{
    		if(v2[j])
    			return -1;
    		j++;
    	}
    	return 0;
    }
};



int main()
{
	string version1 = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
	string version2 = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
	int result = 0;
	result = Solution::compareVersion(version1, version2);
	cout<<"result="<<result<<endl;
	return 0;
}
