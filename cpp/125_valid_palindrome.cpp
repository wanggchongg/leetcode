// Valid Palindrome Total Accepted: 48270 Total Submissions: 218622 My Submissions Question Solution
// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

// Note:
// Have you consider that the string might be empty? This is a good question to ask during an interview.

// For the purpose of this problem, we define empty string as valid palindrome.

#include <iostream>
#include <cmath>
using namespace std;

class Solution {

private:
	bool isAlphanumer(char c)
	{
		bool result = true;
		result = (c>='0'&&c<='9'||c>='A'&&c<='Z'||c>='a'&&c<='z');
		return result;
	}

	bool isEqual(char c1, char c2)
	{
		if(c1 == c2) //不忽略大小写，但是相等的情况
			return true;
		if(abs(c1-c2) == 32) //忽略大小写，但是相等的情况
			return true;
		else
			return false;
	}

public:
    bool isPalindrome(string s) {
    	if(s.size()<2)	return true;

    	int head = 0, tail = s.size()-1;
    	while(head <= tail)
    	{
    		if(!isAlphanumer(s[head]))
    		{
    			head++;
    			continue;
    		}
    		if(!isAlphanumer(s[tail]))
    		{
    			tail--;
    			continue;
    		}

    		if(isEqual(s[head], s[tail]))
    		{
    			head++;
    			tail--;
    		}
    		else
    			return false;
    	}
    	return true;
    }
};

int main()
{
	string s = "A man, a plan, a canal: Panama";

	Solution solution;
	cout<<boolalpha<<solution.isPalindrome(s)<<endl;
	return 0;
}