#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *addBinary(char *a, char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len_c = (len_a>=len_b)?len_a:len_b;
    char *c = (char *)malloc(len_c+3);
    memset(c, 0, len_c+3);

    int i = len_a-1, j = len_b-1, k=len_c;
    int temp = 0;
    while(i>=0||j>=0)
    {
    	if(i>=0&&j>=0)
    	{
    		temp = temp + a[i] - '0' + b[j] - '0';
    	}
    	if(i<0)
    	{
    		temp = temp + b[j] - '0';
    	}
    	if(j<0)
    	{
    		temp = temp + a[i] - '0';
    	}
    	c[k] = temp % 2 + '0';
    	temp /= 2;
    	i--; j--; k--;
    }

    printf("temp=%d\n", temp);
    if(temp)
    {
    	c[0] = temp + '0';
    	c[len_c+1] = 0;
    }
    else
    {
    	c = c + 1;
    	c[len_c+1] = 0;
    }
    return c;
}

int main()
{
	char a[] = "111";
	char b[] = "1100110";
	char *res;
	res = addBinary(a, b);
	printf("%s\n", res);
	return 0;
}
