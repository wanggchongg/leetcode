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
	int res;
	if(l<r)
	{
		res = partition(s, l, r);
		quick_sort(s, l, res-1);
		quick_sort(s, res+1, r);
	}
}

int main()
{
	int number[7] = {49, 38, 65, 97, 76, 13, 27};
	quick_sort(number, 0, 6);
	int i;
	for(i=0; i<7; i++)
	{
		printf("%d, ", number[i]);
	}
	printf("\n");
	return 0;
}
