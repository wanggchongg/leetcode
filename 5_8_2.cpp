#include <iostream>
using namespace std;

int cal_score(double score[], int judge_type[], int n)
{
	double expert = 0, public = 0;
	int ex_num = 0, pu_num = 0;
	int result = 0;
	if(n<=0)
		return 0;
	for(int i=0; i<n; i++)
	{
		if(judge_type[i] == 1)
		{
			expert += score[i];
			ex_num++;
		}
		else if(judge_type[i] == 2)
		{
			public += score[i];
			pu_num++;
		}
	}
	if(ex_num)
		expert = (int)(expert/ex_num);
	if(pu_num)
		public = (int)(public/pu_num);

	if(!ex_num)
		return (int)public;
	if(!pu_num)
		return (int)expert;

	return (int)(0.6*expert+0.4*public);
}

int main()
{
	return 0;
}