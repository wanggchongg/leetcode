#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
    	map<int, int> numMap;
    	int index = 0;

    	numMap[num[0]]++;
    	index = num[0];
    	for(int i=1; i<num.size(); i++)
    	{
    		numMap[num[i]]++;
    		if(numMap[index]<numMap[num[i]])
    			index = num[i];
    	}
    	return index;
    }
};

int main()
{
	return 0;
}