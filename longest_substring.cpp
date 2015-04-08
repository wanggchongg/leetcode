#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char *s) {
	int len = strlen(s);
	if(len <= 1)
		return len;
    int map[127];
    memset(map, -1, sizeof(int)*127);

    int max = 0, temp = 0;
    int index = -1, i;
    for(i=0; i<len; i++)
    {
		if(map[s[i]]>index)
		{
			index = map[s[i]];
			temp = i-index;
		}
		else
			temp++;

    	if(max<temp)
    		max = temp;
    	map[s[i]] = i;
    	printf("temp=%d,max=%d\n", temp, max);
    }
    return max;
}

int main()
{
	char s[] = "asjrgapa";
	int max;
	max = lengthOfLongestSubstring(s);
	printf("max = %d\n", max);
	return 0;
}
