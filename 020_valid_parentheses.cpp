#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char *s) {
    int len = 0;
    char *stack = NULL;
    int top = 0;
  	int i;
    len = strlen(s);
    if(len <= 0)
    	return true;
    stack = (char *)malloc(len+1);

    for(i=0; i<len; i++)
    {
    	if(s[i]=='('||s[i]=='['||s[i]=='{')
    	{
    		stack[top] = s[i];
    		top++;
    		continue;
    	}
    	else if(s[i] == ')')
    	{
    		if(top&&stack[top-1]=='(')
    		{
    			top--;
    			continue;
    		}
    		else
    			return false;
    	}
    	else if(s[i] == ']')
    	{
    		if(top&&stack[top-1]=='[')
    		{
    			top--;
    			continue;
    		}
    		else
    			return false;
    	}
    	else if(s[i] == '}')
    	{
    		if(top&&stack[top-1]=='{')
    		{
    			top--;
    			continue;
    		}
    		else
    			return false;
    	}
    	else
    		return false;
    }
    if(top)
    	return false;
    else
    	return true;
}

int main()
{
	char s[] = "(){[[]}";
	bool bol;
	bol = isValid(s);
	if(bol)
		printf("true\n");
	else
		printf("false\n");
	return 0;
}
