#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
using namespace std;

bool isTrue(int xNum, int yNum, int zNum, int x, int y, int z)
{
	if(xNum==x&&yNum==y&&zNum==z)
		return true;
	else if(xNum==x&&yNum==z&&zNum==y)
		return true;
	else if(xNum==y&&yNum==x&&zNum==z)
		return true;
	else if(xNum==y&&yNum==z&&zNum==x)
		return true;
	else if(xNum==z&&yNum==x&&zNum==y)
		return true;
	else if(xNum==z&&yNum==y&&zNum==x)
		return true;
	else
		return false;
}

int main()
{
	int x=0, y=0, z=0;

	while(cin>>x>>y>>z)
	{
		string seq;
		cin>>seq;

		int maxSum = 0;
		int Cr = 0, Cy = 0, Cb = 0;
		int xNum = 0, yNum = 0, zNum = 0;

		int tempSum = 0;
		for(int i=0; i<seq.size(); i++)
		{
			if(seq[i] == 'R')
			{
				Cr++;
			}
			else if(seq[i] == 'Y')
			{
				Cy++;
			}
			else if(seq[i] == 'B')
			{
				Cb++;
			}
			xNum = abs(Cr-Cy);
			yNum = abs(Cr-Cb);
			zNum = abs(Cy-Cb);

			tempSum = tempSum + 1;

			if(isTrue(xNum, yNum, zNum, x, y, z))
			{
				if(maxSum<tempSum)
					maxSum = tempSum;
				tempSum = 0;
				Cr = 0;
				Cy = 0;
				Cb = 0;
			}
		}
		if(maxSum<tempSum)
			maxSum = tempSum;
		cout<<maxSum<<endl;
	}
	return 0;
}
