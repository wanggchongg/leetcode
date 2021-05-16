// 题目2 : 回文字符序列
// 时间限制:2000ms
// 单点时限:1000ms
// 内存限制:256MB
// 描述
// 给定字符串，求它的回文子序列个数。回文子序列反转字符顺序后仍然与原序列相同。例如字符串aba中，回文子序列为"a", "a", "aa", "b", "aba"，共5个。内容相同位置不同的子序列算不同的子序列。

// 输入
// 第一行一个整数T，表示数据组数。之后是T组数据，每组数据为一行字符串。

// 输出
// 对于每组数据输出一行，格式为"Case #X: Y"，X代表数据编号（从1开始），Y为答案。答案对100007取模。

// 数据范围
// 1 ≤ T ≤ 30

// 小数据

// 字符串长度 ≤ 25

// 大数据

// 字符串长度 ≤ 1000



// 样例输入
// 5
// aba
// abcbaddabcba
// 12111112351121
// ccccccc
// fdadfa
// 样例输出
// Case #1: 5
// Case #2: 277
// Case #3: 1333
// Case #4: 127
// Case #5: 17


#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>

using namespace std;

char a[1005];
const int INF = 100007;
int num[1005];
int dp[1005][1005];

int main(){
    int n;
    while(scanf("%d",&n) != EOF)
    {
	    for(int q = 1; q <= n;q++){
	        scanf("%s",a);
	        int len = strlen(a);
	        map<char,int> ma;
	        for(int i =0;i < len;i++){
	            if(ma.find(a[i]) == ma.end()){
	                ma[a[i]] = i;
	                num[i] = ma[a[i]];
	            }
	            else{
	                num[i] = ma[a[i]];
	                ma[a[i]] = i;
	            }
	        }
	        memset(dp,0,sizeof(dp));
	        for(int d = 0;d < len;d++){
	            for(int s = 0 ;s < len;s++){
	                int e = d+s;
	                if(e >= len) break;
	                if(d == 0){
	                    dp[s][e] = 1;
	                }
	                else{
	                    int en = e;
	                    while(num[e] >= s && num[e] != e) {
	                        dp[s][en] += dp[num[e]+1][en-1] + 1;
	                        dp[s][en] %= INF;
	                        e = num[e];
	                    }
	                    //printf("a   %d\n",dp[s][e-1]);
	                    dp[s][en] += dp[s][en-1] + 1;
	                    dp[s][en] %= INF;
	                //  printf("%d\n",dp[s][en]);
	                }
	            }
	        }
	        printf("Case #%d: %d\n",q,dp[0][len-1]);
	    }
	}
    return 0;
}