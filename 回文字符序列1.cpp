#include <iostream>
#include <string>
using namespace std;

int dp[1005][1005];
const int INF = 100007;

int main()
{
	int t = 0;
	string str;
	while(cin>>t)
	{
		for(int i=1; i<=t; i++)
		{
			cin>>str;
			for(int j=0; j<str.size(); j++)
			{
				dp[j][j] = 1;
				for(int k=j-1; k>=0; k--)
				{
					dp[k][j] = dp[k][j-1] + dp[k+1][j] - dp[k+1][j-1];
					if(str[k] == str[j])
						dp[k][j] = dp[k][j] + dp[k+1][j-1] + 1;
					dp[k][j] += INF;
					dp[k][j] %= INF;
				}
			}
			cout<<"Case #"<<i<<": "<<dp[0][str.size()-1]<<endl;
		}
	}
	return 0;
}
