//字符串s中的最长回文串是s的倒转s'和s的最长连续公共子串
//采用KMP算法，判断s'的子串是否在s中，直到得到最长的连续公共子串为止

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//next[i] = k 意思是模式串P的第i个字符与主串相应字符失配时，此字符重新与模式串比较的字符位置为k
void get_next(const char P[], int len, int next[])
{
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

int index_kmp(const char S[], int len1, const char P[], int len2, const int next[])
{
	int i = 0, j = 0;
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


char *longestPalindrome(char *s)
{
	int len = strlen(s);
	if(len <= 1) return s;

	char *s_t = (char *)malloc(len+1);

	bool res_bol = true;
	for(int i=len-1, j=0; i>=0; i--, j++)
	{
		s_t[j] = s[i];
		if(s_t[j] != s[j]) res_bol = false;
	}
	s_t[len] = 0;
	if(res_bol)
	{
		free(s_t);
		return s;
	}

	int *next = (int *)malloc(sizeof(int) * (len+1));
	int max_len = 1; //初始最长回文字串长度为1
	int max_pos = 0; //初始最长回文字串位置为0
	int sub_len = 2; //起始公共连续子串的长度设为2
	int sub_pos = 0;
	char *ptr = s_t; //将s的倒置作为字串
	while(ptr[sub_len-1])
	{
		get_next(ptr, sub_len, next);
		if((sub_pos = index_kmp(s, len, ptr, sub_len, next)) < 0)
		{
			ptr++;
		}
		else
		{
			if(sub_len>max_len)
			{
				max_pos = sub_pos;
				max_len = sub_len;
				//cout<<"max_pos="<<max_pos<<", max_len="<<max_len<<endl;
			}
			sub_len++;
		}
	}

	free(s_t);
	free(next);

	ptr = s;
	ptr += max_pos;
	ptr[max_len] = 0;
	return ptr;
}

int main()
{
	char s[] = "abcdcbbef";
	char *result = NULL;

	result = longestPalindrome(s);
	printf("result = %s\n", result);
	return 0;
}
