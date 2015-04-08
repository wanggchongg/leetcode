#include <stdio.h>
#include <stdlib.h>

int partition(int s[], int i, int j)
{
	int value = 0;
	int flag = 1; //判断该从头循环还是尾循环
	value = s[i];
	while(i<j)
	{
		switch(flag)
		{
		case 0:
			if(s[i] < value)
				i++;
			else
			{
				s[j--] = s[i];
				flag = 1;
			}
			break;
		case 1:
			if(s[j] >= value)
				j--;
			else
			{
				s[i++] = s[j];
				flag = 0;
			}
			break;
		}
	}
	s[i] = value;
	return i;
}

void quick_sort(int s[], int l, int r)
{
	int *stack = (int *)malloc(sizeof(int)*(r-l+1));
	int top = 0;
	int index1, index2;
	int res;
	stack[top++] = r;
	stack[top++] = l;
	while(top!=0)
	{
		index1 = stack[--top];
		index2 = stack[--top];
		res = partition(s, index1, index2);

		if(res != index2) //后部分partiton未结束
		{
			stack[top++] = index2;
			stack[top++] = res+1;
		}
		if(res != index1) //前部分partion未结束
		{
			stack[top++] = res-1;
			stack[top++] = index1;
		}
	}
	free(stack);
	stack = NULL;
}

int main()
{
	int number[10] = {8, 1, 8, 4, 9, 5, 8, 10, 3, 6};
	quick_sort(number, 0, 9);
	int i;
	for(i=0; i<10; i++)
	{
		printf("%d, ", number[i]);
	}
	printf("\n");
	return 0;
}
