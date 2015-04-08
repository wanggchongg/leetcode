#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *convertToTitle(int n) {
	char *result = (char *)malloc(11);
	memset(result, 0, 11);
	if(n<1) return result;
	int i = 10;
	int temp = 0;
	while(n)
	{
		n--;
		temp = n % 26;
		result[i--] = 'A' + temp;
		n = n/26;
	}
	if(i)
		result = result + i + 1;
	return result;
}

int main()
{
	char *result;
	result = convertToTitle(26235423);
	printf("%s\n", result);
	return 0;
}
