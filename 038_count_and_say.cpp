#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string temp;
        string result = "1";
        char number;
        char tmpNumber;
        unsigned int count;
        if(n<=1)
            return result;

        for(int i=1; i<n; i++)
        {
            cout<<result<<endl;
            temp = result;
            result.clear();
            number = temp[0];
            count = 1;
            for(int j=1; j!=temp.size(); j++)
            {
                if(number == temp[j])
                {
                    count++;
                }
                else
                {
                    tmpNumber = '0'+count;
                    result = result + tmpNumber + number;
                    number = temp[j];
                    count = 1;
                }
            }
            tmpNumber = '0'+count;
            result = result + tmpNumber + number;
        }
        return result;
    }
};

int main()
{
    string res;
    Solution solution;
    res = solution.countAndSay(20);
    cout<<res<<endl;
    return 0;
}
