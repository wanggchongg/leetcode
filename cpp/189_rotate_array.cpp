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

//方法一：
class Solution1 {
public:
    static void rotate(int nums[], int n, int k) {
    	if(n<1||k<1) return;
    	int *numsT = (int *)malloc(sizeof(int)*n);
    	memcpy(numsT, nums, sizeof(int)*n);
    	for(int i=0; i<n; i++)
    	{
    		nums[(i+k)%n] = numsT[i];
    	}
    }
};


//方法二
class Solution2 {
public:
    static void rotate(int nums[], int n, int k) {
    	if(n<1||k<1) return;
    	k = k%n;
    	if(k==0) return;
		int *numsT = NULL;
		if(k>=n-k)
		{
			numsT = (int *)malloc(sizeof(int)*k);
			memcpy(numsT, &nums[n-k], sizeof(int)*k);
			memcpy(&nums[k], nums, sizeof(int)*(n-k));
			memcpy(nums, numsT, sizeof(int)*k);
		}
		else
		{
			numsT = (int *)malloc(sizeof(int)*(n-k));
			memcpy(numsT, nums, sizeof(int)*(n-k));
			memcpy(nums, &nums[n-k], sizeof(int)*k);
			memcpy(&nums[k], numsT, sizeof(int) *(n-k));
		}
		free(numsT);
		numsT = NULL;
    }
};

//方法三
class Solution3 {
public:
    static void rotate(int nums[], int n, int k) {
    	if(n<1||k<1) return;
    	k = k % n;
    	if(k==0) return;
		int i = 0, v = nums[0], index = -1, value = -1, start = 0, count = n;
		while(count)
		{
			while(index != start) //小循环
			{
				index = (i + k) % n;
				value = nums[index];
				nums[index] = v;
				i = index;
				v = value;
				count--;
			}
			start = (start + 1) % n;
			i = start;
			v = nums[i];
		}
    }
};

int main()
{

	int nums[7] = {1, 2, 3, 4, 5, 6, 7};
	Solution3::rotate(nums, 7, 3);
	for(int i=0; i<7; i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	return 0;
}
