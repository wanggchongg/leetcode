#include <stdio.h>
#include <string.h>

int romanToInt(char *s)
{
	int len = strlen(s);
	if(len<1)
		return 0;
	int map[100] = {0};
	map['I'] = 1;
	map['V'] = 5;
	map['X'] = 10;
	map['L'] = 50;
	map['C'] = 100;
	map['D'] = 500;
	map['M'] = 1000;
	int sum = 0;
	int i = 0;
	len-=1;
	sum = map[s[len]];
	for(i=len;i>0;i--)
	{
		if(map[s[i]] > map[s[i-1]])
			sum -= map[s[i-1]];
		else
			sum += map[s[i-1]];
	}
	return sum;
}

int main()
{
	char s[] = "MMMCMXCIX";
	int sum;
	sum = romanToInt(s);
	printf("sum=%d\n", sum);
}
