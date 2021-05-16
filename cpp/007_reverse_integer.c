#include <stdio.h>
#include <limits.h>


int reverse(int x)
{
	int nOld = x;
	int nRtn = 0;
	int nCount = 0;
	int nTemp = 0;
	int nTTT = 0;
	while(nOld)
	{
	    nTTT = nOld%10;
	    nRtn = nRtn*10+nTTT;
	    nOld = nOld/10;
	    nCount++;
	    if(nCount==9)
	    {
	    	if(nRtn>=214748364||nRtn<=-214748364)
	    	{
	    		nTemp = nRtn;
	    	}
	    }
	    if(nCount==10)
	    {
	    	if(nTemp>214748364||nTemp<-214748364)
	    	{
	    		return 0;
	    	}
	    	else if(nTemp==214748364||nTemp==-214748364)
	    	{
	    		if(nTTT>6||nTTT<-7)
	    		{
	    			return 0;
	    		}
	    	}
	    }
	}
	return nRtn;
}



// int reverse(int x)
// {
//     long nRtn = 0;
//     while(x)
//     {
//         nRtn = nRtn*10+x%10;
//         x = x/10;
//     }
//     return nRtn;
// }

int main()
{
	int nn = -2147483648;
	int nr = 0;
	nr = reverse(nn);
	printf("nn = %d\nnr = %d\n",nn, nr);
	return 0;
}
