#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    static int titleToNumber(string s) {
    	int result = 0;
    	for(int i=0; i<s.size(); i++)
    	{
    		char value = s[i];
    		result *= 26;
    		result = result + value - 'A' + 1;
    	}
    	return result;
    }
};

int main()
{
	cout<<Solution::titleToNumber("AA")<<endl;
	return 0;
}
