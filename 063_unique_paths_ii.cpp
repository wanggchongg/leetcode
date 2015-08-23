// Unique Paths II Total Accepted: 36871 Total Submissions: 131653 My Submissions Question Solution
// Follow up for "Unique Paths":

// Now consider if some obstacles are added to the grids. How many unique paths would there be?

// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.

// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// The total number of unique paths is 2.

// Note: m and n will be at most 100.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    	if(obstacleGrid.empty())
    		return 0;
    	int m = obstacleGrid.size();
    	int n = obstacleGrid[0].size();

    	bool isObstacle = false;
    	for(int i=0; i<m; i++)
    	{
    		if(isObstacle)
    		{
    			obstacleGrid[i][0] = 1;
    			continue;
    		}
    		if(obstacleGrid[i][0] == 1)
    			isObstacle = true;
    		else
    			obstacleGrid[i][0] = -1;
    	}

    	isObstacle = false;
    	for(int i=0; i<n; i++)
    	{
    		if(isObstacle)
    		{
    			obstacleGrid[0][i] = 1;
    			continue;
    		}
    		if(obstacleGrid[0][i] == 1)
    			isObstacle = true;
    		else
    			obstacleGrid[0][i] = -1;
    	}

    	for(int i=1; i<m; i++)
    	{
    		for(int j=1; j<n; j++)
    		{
    			if(obstacleGrid[i][j] == 1)
    				continue;
    			if(obstacleGrid[i-1][j] != 1 && obstacleGrid[i][j-1] != 1)
    				obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
    			else if(obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1] != 1)
    				obstacleGrid[i][j] = obstacleGrid[i][j-1];
    			else if(obstacleGrid[i-1][j] != 1 && obstacleGrid[i][j-1] == 1)
    				obstacleGrid[i][j] = obstacleGrid[i-1][j];
    			else
    				obstacleGrid[i][j] = 1;
    		}
    	}

    	if(obstacleGrid[m-1][n-1] != 1)
    		return -obstacleGrid[m-1][n-1];
    	return 0;
    }
};

int main()
{
	return 0;
}