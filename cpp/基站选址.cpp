// 题目3 : 基站选址
// 时间限制:2000ms
// 单点时限:1000ms
// 内存限制:256MB
// 描述
// 需要在一个N × M的网格中建立一个通讯基站，通讯基站仅必须建立在格点上。

// 网格中有A个用户，每个用户的通讯代价是用户到基站欧几里得距离的平方。

// 网格中还有B个通讯公司，维护基站的代价是基站到最近的一个通讯公司的路程（路程定义为曼哈顿距离）。

// 在网格中建立基站的总代价是用户通讯代价的总和加上维护基站的代价，最小总代价。

// 输入
// 第一行为一个整数T，表示数据组数。

// 每组数据第一行为四个整数：N, M, A, B。

// 接下来的A+B行每行两个整数x, y，代表一个坐标，前A行表示各用户的坐标，后B行表示各通讯公司的坐标。

// 输出
// 对于每组数据输出一行"Case #X: Y"，X代表数据编号（从1开始），Y代表所求最小代价。

// 数据范围
// 1 ≤ T ≤ 20

// 1 ≤ x ≤ N

// 1 ≤ y ≤ M

// 1 ≤ B ≤ 100

// 小数据

// 1 ≤ N, M ≤ 100

// 1 ≤ A ≤ 100

// 大数据

// 1 ≤ N, M ≤ 107

// 1 ≤ A ≤ 1000

// 样例输入
// 2
// 3 3 4 1
// 1 2
// 2 1
// 2 3
// 3 2
// 2 2
// 4 4 4 2
// 1 2
// 2 4
// 3 1
// 4 3
// 1 4
// 1 3
// 样例输出
// Case #1: 4
// Case #2: 13


#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
#define modnum 100007
long long cost=0;
long long maxll=9223372036854775807;
long long mincost=maxll;
long long totalAx=0;
long long totalAxSquare=0;
long long totalAy=0;
long long totalAySquare=0;
vector<long long> bx;
vector<long long> by;
int N,M,A,B;
long long cal(long long totalSquare,long long total,long long x,long long num)
{
    long long ans=0;
    ans+=totalSquare+num*x*x-2*total*x;
    return ans;
}

long long calAll(long long x,long long y)
{
    long long ans=maxll;
    for(int i=0;i<bx.size();i++)
    {
        ans=min(ans,abs(bx[i]-x)+abs(by[i]-y));
    }
    return ans+cal(totalAxSquare,totalAx,x,A)+cal(totalAySquare,totalAy,y,A);
}

int main()
{
    int T=0;
    int Case=0;
    while(cin>>T)
    {
	    while(T)
	    {
	        bx.clear();
	        by.clear();
	        totalAx=0;
	        totalAxSquare=0;
	        totalAy=0;
	        totalAySquare=0;

	        T--;
	        Case++;

	        cin>>N>>M>>A>>B;
	        int temp=0;
	        for(int i=0;i<A;i++)
	        {
	            cin>>temp;
	            totalAx+=temp;
	            totalAxSquare+=temp*temp;
	            cin>>temp;
	            totalAy+=temp;
	            totalAySquare+=temp*temp;
	        }
	        for(int i=0;i<B;i++)
	        {
	            cin>>temp;
	            bx.push_back(temp);
	            cin>>temp;
	            by.push_back(temp);
	        }
	        long long x,y;
	        x=totalAx/A;
	        y=totalAy/A;
	        long long ans=maxll;
	        ans=min(ans,calAll(x,y));
	        ans=min(ans,calAll(x,y+1));
	        ans=min(ans,calAll(x+1,y));
	        ans=min(ans,calAll(x+1,y+1));

	        cout<<"Case #"<<Case<<": "<<ans<<endl;
	    }
	}
	return 0;
}