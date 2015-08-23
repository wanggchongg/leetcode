// Container With Most Water Total Accepted: 36076 Total Submissions: 113010 My Submissions Question Solution
// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container.

#include <iostream>
using namespace std;

//求两块木板组成的容器的最大盛水量
class Solution {
public:
    int maxArea(vector<int>& height) {
    	if(height.size()<2) return 0;
    	int result = 0;
    	int water = 0;
    	int i=0, j=height.size()-1;
    	while(i<j)
    	{
    		water = min(height[i], height[j])*(j-i);
    		if(result < water)
    			result = water;
    		if(height[i] <= height[j])
    			i++;
    		else
    			j--;
    	}
    	return result;
    }
};

int main()
{
	return 0;
}