// Letter Combinations of a Phone Number Total Accepted: 37458 Total Submissions: 144335 My Submissions Question Solution
// Given a digit string, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below.



// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:
// Although the above answer is in lexicographical order, your answer could be in any order you want.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

//回溯法
class Solution {

private:
	map<char, string> digitsMap;
public:
	Solution()
	{
		digitsMap['0'] = "";
		digitsMap['1'] = "";
		digitsMap['2'] = "abc";
		digitsMap['3'] = "def";
		digitsMap['4'] = "ghi";
		digitsMap['5'] = "jkl";
		digitsMap['6'] = "mno";
		digitsMap['7'] = "pqrs";
		digitsMap['8'] = "tuv";
		digitsMap['9'] = "wxyz";
	}

//深度优先搜索
    void dfs(int dep, string &digits, vector<string> &result, string &str)
    {
        if(dep == digits.size())
        {
            result.push_back(str);
            return;
        }
        for(int i=0; i<digitsMap[digits[dep]].size(); i++)
        {
            str.push_back(digitsMap[digits[dep]][i]);
            dfs(dep+1, digits, result, str);
            str.erase(str.end()-1);
        }
    }

    vector<string> letterCombinations(string digits) {
    	vector<string> result;
    	if(digits.empty())
    		return result;

        string temp; //存储临时letter
    	dfs(0, digits, result, temp);
    	return result;
    }
};

int main()
{
    Solution solution;
    string digits;
    vector<string> result;
    while(cin>>digits)
    {
        result = solution.letterCombinations(digits);
        for(int i=0; i<result.size(); i++)
        {
            cout<<result[i]<<", ";
        }
        cout<<endl;
    }
	return 0;
}
