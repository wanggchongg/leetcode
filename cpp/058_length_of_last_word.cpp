#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s) {
    int len = 0;
    int count = 0;
    int result = 0;
    int space = 0;
    int i;
    len = strlen(s);
    if(len<=0)
    	return 0;
    for(i=0; i<len; i++)
    {
    	if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z')
    	{
    		count++;
    		space = 0;
    	}
    	else if(s[i] == ' ')
    	{
    		space++;
    		if(space==1)
    		{
	    		result = count;
	    		count = 0;
	    	}
    	}
    }
    if(!space)
    	result = count;
    return result;
}

int main()
{
	char s[] = "  sdfasf dsfasdf dsf";
	int res;
	res = lengthOfLastWord(s);
	printf("res = %d\n", res);
	return 0;
}
