#include <stdio.h>
#include <stdlib.h>

int *plusOne(int *digits, int len, int *newLen) {
    int *result = NULL;
    int temp = 1;
    result = (int *)malloc(sizeof(int)*(len+1));
    for(int i=len-1; i>=0; i--)
    {
    	temp += digits[i];
    	result[i+1] = temp % 10;
    	temp /= 10;
    }
    if(temp != 0)
    {
    	result[0] = temp;
    	*newLen = len+1;
    }
    else
    {
    	result++;
    	*newLen = len;
    }
    return result;
}

int main()
{
	int a[10] = {1, 9,9,9, 9};
	int *b = NULL;
	int len = 0;
	b = plusOne(a, 5, &len);
	for(int i=0; i<len; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
	return 0;
}
