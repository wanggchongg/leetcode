// Integer to Roman Total Accepted: 30033 Total Submissions: 86368 My Submissions Question Solution
// Given an integer, convert it to a roman numeral.

// Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <vector>
using namespace std;



class Solution1 {
public:
    static string intToRoman(int num) {
    	string result;
        vector<string> roman = {
            "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
            "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
            "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
            "", "M", "MM", "MMM"
        };

        int temp = 0;
        temp = num/1000;
        if(temp)
        	result += roman[30+temp];
        temp = (num%1000)/100;
        if(temp)
        	result += roman[20+temp];
        temp = (num%100)/10;
        if(temp)
        	result += roman[10+temp];
        temp = num % 10;
        if(temp)
        	result += roman[temp];
        return result;
    }
};

class Solution2 {
public:
    static string intToRoman(int num) {
        string result;
        int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int digit=0;
        while (num > 0) {
            int times = num / nums[digit];
            num -= nums[digit] * times;
            while(times--)
            {
                result += symbols[digit];
            }
            digit++;
        }
        return result;
    }
};

int main()
{
	int n;
	while(cin>>n)
	{
		cout<<Solution1::intToRoman(n)<<endl;
	}
	return 0;
}

