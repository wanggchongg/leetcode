#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

#define min(x, y) ((x<=y)?x:y)

typedef struct Island
{
	bool f;
	int x;
	int y;
}Island;

int main()
{
	int n = 0;
	int sum = 0;

	int absX = 0;
	int absY = 0;

	int absXT = 0;
	int absYT = 0;

	while(cin>>n)
	{
		Island *island = (Island *)malloc(sizeof(Island)*n);

		for(int i=0; i<n; i++)
		{
			cin>>island[i].x>>island[i].y;
			island[i].f = true;
		}

		int xy = 0, xyT = 0, index = 0;
		for(int i=0; i<n; i++)
		{
			for(int j=1; j<n; j++)
			{
				if(!island[j].f)
					continue;
				xyT = island[j].x + island[j].y;
				int indexT = j;
				if(xy>xyT)
					index = j;
				else
					index = indexT;
			}
			absX = abs(island[i].x - island[i].x);
			absY = abs(island[i-1].y - island[i].y);
			sum += min(absX, absY);
		}
		cout<<sum<<endl;
	}
	return 0;
}

