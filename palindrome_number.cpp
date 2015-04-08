#include <stdio.h>

bool isPalindrome(int x)
{
	int temp1 = x;
	int temp2 = 0;
	int base = 0;
	int head = 1;
	int conn = 0;
	int i;
	if(x<0)
		return false;
	if(x<10)
		return true;
	while(temp1)
	{
		temp1/=10;
		base++;
	}
	conn = base-1;
	for(i=0;i<conn;i++)
		head *= 10;
	conn = base/2;
	for(i=0;i<conn;i++)
	{
		temp1=x/head;
		x%=head;
		head/=100;
		temp2=x%10;
		x/=10;
		if(temp1!=temp2)
			break;
	}
	return (i==conn)?true:false;
}

int main()
{
	int n = 1241;
	if(isPalindrome(n))
		printf("true\n");
	else
		printf("false\n");
	return 0;
}
