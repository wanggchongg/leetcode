#include <stdio.h>
#include <stdlib.h>

// int *twoSum(int numbers[], int n, int target)
// {
// 	int cur = 0;
// 	int pos = n-1;
// 	static int index[2] = {0};
// 	for(cur=0; cur<n; cur++)
// 	{
// 		for(pos=cur+1; pos<n; pos++)
// 		{
// 			if(numbers[cur] + numbers[pos] == target)
// 			{
// 				index[0] = cur+1;
// 				index[1] = pos+1;
// 				return index;
// 			}
// 		}
// 	}
// 	return NULL;
// }
//快速排序
void quick_sort(int s[], int l, int r, int index[])
{
    if (l < r)
    {
		//Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l], p = index[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
				j--;
            if(i < j)
            {
            	index[i] = index[j];
				s[i++] = s[j];
            }

            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
				i++;
            if(i < j)
            {
            	index[j] = index[i];
				s[j--] = s[i];
            }
        }
        s[i] = x;
        index[i] = p;
        quick_sort(s, l, i - 1, index); // 递归调用
        quick_sort(s, i + 1, r, index);
    }
}

int *twoSum(int numbers[], int n, int target)
{
	int l = 0, r = n-1, i;
	static int pos[2] = {0};
	int *index;
	index = (int *)malloc(n*sizeof(int));
	for(i = 0; i < n; i++)
		index[i] = i;
	quick_sort(numbers, 0, n-1, index);
	while(l < r)
	{
		if(numbers[l]+numbers[r]>target)
		{
			r--;
		}
		else if(numbers[l]+numbers[r]<target)
		{
			l++;
		}
		else
		{
			if(index[l]<index[r])
			{
				pos[0] = index[l]+1;
				pos[1] = index[r]+1;
			}
			else
			{
				pos[0] = index[r]+1;
				pos[1] = index[l]+1;
			}
			return pos;
		}
	}
	return NULL;
}


int main()
{
	int n = 8;
	int nNumbers[] = {11, 7, 2, 15, 33, 1, 47, 6};
	int target = 16;
	int *result;

	result = twoSum(nNumbers, 8, 16);
	printf("result1=%d, result2=%d\n", result[0], result[1]);
	return 0;
}
