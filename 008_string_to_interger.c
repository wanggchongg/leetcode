#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int myAtoi(char *str)
{
	if(!str)
		return 0;
	int result = 0;
	int minus_flag = 0;
	int numbe_flag = 0;
	int minus_coun = 0;
	int len = strlen(str);
	int i;
	for(i=0; i<len; i++)
	{
		if(str[i]==' '&&numbe_flag==0&&minus_coun==0)
		{
			continue;
		}
		else if(str[i]=='-'&&numbe_flag==0&&minus_coun==0)
		{
			minus_flag = 1;
			minus_coun++;
			continue;
		}
		else if(str[i]=='+'&&numbe_flag==0&&minus_coun==0)
		{
			minus_flag = 0;
			minus_coun++;
			continue;
		}

		if(str[i]>='0'&&str[i]<='9')
		{
			if(minus_flag==0&&(result>214748364||result==214748364&&str[i]>='7'))
				return INT_MAX;
			else if(minus_flag==1&&(result>214748364||result==214748364&&str[i]>='8'))
				return INT_MIN;
			numbe_flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else
		{
			break;
		}
	}
	return minus_flag?(0-result):result;
}

int main()
{
	char s[] = "- 321";
	int res = 0;
	res = myAtoi(s);
	printf("result = %d\n", res);
}
