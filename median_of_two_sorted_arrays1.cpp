#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

//求无重叠数字排序数组的中位数
double findMedianSortedArrays(int A[], int m, int B[], int n) {
	if(m<=0&&n<=0)
		return 0;

 	int *C = (int *)malloc(sizeof(int)*(m+n));
 	int i=0, j=0, k=0;
 	double result = 0;

 	if(m<=0)
 		C[k++] = B[j++];
 	if(n<=0)
 		C[k++] = A[i++];

	while(i<m && j<n)
	{
		if(A[i]<B[j])
		{
			C[k++] = A[i++];
		}
		else if(A[i]>B[j])
		{
			C[k++] = B[j++];
		}
		else
		{
			C[k++] = A[i++];
			j++;
		}

		if(A[i] == C[k-1])
			i++;
		if(B[j] == C[k-1])
			j++;
	}
	while(i<m)
	{
		if(A[i] > C[k-1])
			C[k++] = A[i++];
		else
			i++;
	}
	while(j<n)
	{
		if(B[j] > C[k-1])
			C[k++] = B[j++];
		else
			j++;
	}

	if(k%2==0)
		result = (double)(C[k/2] +C[k/2-1])/2;
	else
		result = (double)C[k/2];
	return result;
}

int main()
{
	int A[10], B[10];
	double res;
	for(int i=0; i<10; i++)
	{
		A[i] = i+1;
		B[i] = i;
	}
	res = findMedianSortedArrays(A, 10, B, 0);
	printf("res = %f\n", res);
	return 0;
}
