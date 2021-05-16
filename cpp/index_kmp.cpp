#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//next[i] = k 意思是模式串P的第i个字符与主串相应字符失配时，此字符重新与模式串比较的字符位置为k
void get_next(const char P[], int next[])
{
	int len = strlen(P);
	if(len==0) return;
	next[0] = -1; //第0个字符失配时，主串应该右移一位，这里用-1表示。
	if(len==1) return;
	next[1] = 0;
	if(len==2) return;
	int i = 1, j = 0;

	while(i<len)
	{
		//当第i+1个模式串字符失配时
		if(j == -1 || P[i] == P[j]) //第i个字符和第next[i]个字符相等情况
		{
			i++;
			j++;
			next[i] = j;
		}
		else //第i个字符和第next[i]个字符不等情况,应比较第i个字符和第next[next[i]]个字符是否相等
		{
			j = next[j];
		}
	}
}

int index_kmp(const char S[], const char P[], const int next[])
{
	int i = 0, j = 0;
	int len1 = strlen(S);
	int len2 = strlen(P);

	while(i<len1 && j<len2)
	{
		if(j == -1 || S[i] == P[j])//j=-1说明模式串第0个字符和主串相应字符失配
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}

	}
	if(j==len2)
		return i-j;
	else
		return -1;
}

int main()
{
	char S[] = "BBC ABCDAB ABCDABCDABDE";
	char P[] = "ABCDABD";
	int P_len = strlen(P);
	int *next = (int *)malloc(sizeof(int)*P_len);
	get_next(P, next);

	for(int i = 0; i<P_len; i++)
	{
		printf("next[%d]=%d\n", i, next[i]);
	}
	int result = index_kmp(S, P, next);
	printf("result = %d\n", result);

	return 0;
}
