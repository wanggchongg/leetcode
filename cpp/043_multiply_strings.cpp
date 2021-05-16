// Multiply Strings Total Accepted: 30810 Total Submissions: 147069 My Submissions Question Solution
// Given two numbers represented as strings, return multiplication of the numbers as a string.

// Note: The numbers can be arbitrarily large and are non-negative.

#include <iostream>
using namespace std;

class Solution {
public:
	string multiplyA(string &num1, char num2) //倒序积
	{
		string result;
		if(num2 == '0')
		{
			result = '0';
			return result;
		}
		int carry = 0;
		int digit = 0;
		int product = 0;
		for(int i=num1.size()-1; i>=0; i--)
		{
			product = (num2-'0') * (num1[i]-'0');
			digit = (product+carry)%10;
			carry = (product+carry)/10;
			result += ('0'+digit);
		}
		if(carry)
			result += ('0'+carry);
		return result;
	}

	string add(string &num1, string &num2) //倒序和
	{
		string result;
		while(num1.size() < num2.size())
		{
			num1.push_back('0');
		}
		while(num2.size() < num1.size())
		{
			num2.push_back('0');
		}

		int carry = 0;
		int digit = 0;
		int sum = 0;
		for(int i=0; i<num1.size(); i++)
		{
			sum = (num1[i]-'0')+(num2[i]-'0');
			digit = (sum+carry)%10;
			carry = (sum+carry)/10;
			result += ('0'+digit);
		}
		if(carry)
			result += ('0'+carry);
		return result;
	}

    string multiply(string num1, string num2) {
    	string result;
    	string &multiplicand = (num1.size() >= num2.size())?num1:num2;
    	string &multiplicator = (num1.size() < num2.size())?num1:num2;

    	for(int i=multiplicator.size()-1, j=0; i>=0; i--, j++)
    	{
    		string temp;
    		for(int k=0; k<j; k++)
    			temp.push_back('0');
    		temp += multiplyA(multiplicand, multiplicator[i]);
    		//cout<<"temp="<<temp<<endl;
    		result = add(result, temp);
    		//cout<<"result="<<result<<endl;
    	}
    	reverse(result.begin(), result.end());
    	return result;
    }
};

int main()
{
	string num1;
	string num2;
	Solution solution;
	string result;
	while(cin>>num1>>num2)
	{
		result = solution.multiply(num1, num2);
		cout<<result<<endl;
	}
	return 0;
}
