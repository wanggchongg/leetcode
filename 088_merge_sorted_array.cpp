// Merge Sorted Array Total Accepted: 49291 Total Submissions: 163499 My Submissions Question Solution
// Given two sorted integer arrays A and B, merge B into A as one sorted array.

// Note:
// You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
    	if(n<1)
    		return;
    	if(m<1)
    	{
    		memcpy(A, B, sizeof(int) * n);
    		return;
    	}

    	int *C = (int *)malloc(sizeof(int) * (m+n));
    	int i = 0, j = 0, k = 0;
    	while(i!=m || j!=n)
    	{
    		if(i==m)
    		{
    			C[k++] = B[j++];
    			continue;
    		}
    		if(j==n)
    		{
    			C[k++] = A[i++];
    			continue;
    		}
    		if(A[i] <= B[j])
    		{
    			C[k++] = A[i++];
    		}
    		else
    		{
    			C[k++] = B[j++];
    		}
    	}
    	memcpy(A, C, sizeof(int) * (m+n));
    	free(C);
    }
};

int main()
{
	return 0;
}
