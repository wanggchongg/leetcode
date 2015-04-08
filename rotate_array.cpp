// Rotate an array of n elements to the right by k steps.

// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

// Note:
// Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

// [show hint]

// Related problem: Reverse Words in a String II

// Credits:
// Special thanks to @Freezen for adding this problem and creating all test cases.

#include <iostream>
#include <stdlib.h>
using namespace std;

// class Solution {
// public:
//     void rotate(int nums[], int n, int k) {
//     	if(n<1||k<1) return;
//     	int *numsT = (int *)malloc(sizeof(int)*n);
//     	memcpy(numsT, nums, sizeof(int)*n);
//     	for(int i=0; i<n; i++)
//     	{
//     		nums[(i+k)%n] = numsT[i];
//     	}
//     }
// };
//


class Solution {
public:
    static void rotate(int nums[], int n, int k) {
    	if(n<1||k<1) return;
    	k = k%n;
    	if(k==0) return;
		int *numsT = NULL;
		if(k>=n-k)
		{
			numsT = (int *)malloc(sizeof(int)*k);
			memcpy(numsT, &nums[n-k], k);
			memcpy(&nums[k], nums, n-k);
			memcpy(nums, numsT, k);
		}
		else
		{
			numsT = (int *)malloc(sizeof(int)*(n-k));
			memcpy(numsT, nums, n-k);
			memcpy(nums, &nums[n-k], k);
			memcpy(&nums[k], numsT, n-k);
		}
		free(numsT);
		numsT = NULL;
    }
};

int main()
{

	int nums[3] = {1, 2, 3};
	Solution::rotate(nums, 3, 1);
	for(int i=0; i<3; i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	return 0;
}
