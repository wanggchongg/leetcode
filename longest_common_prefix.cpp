#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char *strs[], int n) {
    int nAlph, nArra;
    char alph1;
    int minLen, tmpLen;
    char *result = (char *)malloc(n+1);
    memset(result, 0, n+1);
    if(!strs || n<1) //异常情况
    	return result;
    if(n==1) //只有一个字符串时,直接返回此字符串
    {
    	strcpy(result, strs[0]);
    	return result;
    }
    minLen = strlen(strs[0]);
    for(nArra=1; nArra<n; nArra++) //计算字符串最短长度,存在长度为0时返回空串
    {
    	tmpLen = strlen(strs[nArra]);
    	if(minLen<tmpLen)
		{
			minLen = tmpLen;
		}
		if(minLen==0)
			return result;
    }
    for(nAlph=0; nAlph<minLen; nAlph++)//挨个比较字符差异
    {
    	alph1 = strs[0][nAlph];
    	for(nArra=1; nArra<n; nArra++)
    	{
    		if(alph1 != strs[nArra][nAlph])//字符不同时,立即返回已辨明的前缀
    		{
    			memcpy(result, strs[0], nAlph);
    			return result;
    		}
    	}
    }
    //每个字符串都相同的情况
    memcpy(result, strs[0], nAlph);
    return result;
}

int main()
{
	char *strs[3]; //定义一个指针数组
	char str1[] = "ccccc";
	char str2[] = "ccc";
	char str3[] = "ccccc";
	strs[0] = str1;
	strs[1] = str2;
	strs[2] = str3;
	printf("%s\n", longestCommonPrefix(strs, 3));
	return 0;
}
