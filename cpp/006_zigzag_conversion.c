#include <stdio.h>


char *convert(char *s, int nRows) {
	int len = strlen(s);
	char *result = (char *)malloc(len+1);
    memset(result, 0, len+1);
    if(len<=1||nRows<=1)
    {
    	strcpy(result, s);
    	return result;
    }
    int i = 0;
    int count = 0;
    int row = 0;
    int j = 0;
    int step1 = 0, step2 = 0;
    for(row=0; row<nRows; row++)
    {
    	step1 = 2*(nRows-row-1);
    	step2 = 2*row;
    	j = row;
    	count = 0;
    	while(j<len)
    	{
    		result[i] = s[j];
    		if(step1==0)
    		{
    			j += step2;
    		}
    		else if(step2==0)
    		{
    			j += step1;
    		}
    		else if(step1&&step2)
    		{
	    		if(count%2==0)
	    		{
	    			j += step1;
	    		}
	    		else
	    		{
	    			j += step2;
	    		}
    		}
    		i++;
    		count++;
    	}
    }
    return result;
}

int main()
{
	//PAHNAPLSIIGYIR
	char s[] = "A";
	int nRows = 1;
	char *result = NULL;
	result = convert(s, nRows);
	printf("result=%s\n", result);
	return 0;
}
