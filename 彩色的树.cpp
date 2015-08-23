题目1 : 彩色的树
时间限制:2000ms
单点时限:1000ms
内存限制:256MB
描述
给定一棵n个节点的树，节点编号为1, 2, …, n。树中有n - 1条边，任意两个节点间恰好有一条路径。这是一棵彩色的树，每个节点恰好可以染一种颜色。初始时，所有节点的颜色都为0。现在需要实现两种操作:

1. 改变节点x的颜色为y；

2. 询问整棵树被划分成了多少棵颜色相同的子树。即每棵子树内的节点颜色都相同，而相邻子树的颜色不同。

输入
第一行一个整数T，表示数据组数，以下是T组数据。

每组数据第一行是n，表示树的节点个数。接下来n - 1行每行两个数i和j，表示节点i和j间有一条边。接下来是一个数q，表示操作数。之后q行，每行表示以下两种操作之一：

1. 若为"1"，则询问划分的子树个数。

2. 若为"2 x y"，则将节点x的颜色改为y。

输出
每组数据的第一行为"Case #X:"，X为测试数据编号，从1开始。

接下来的每一行，对于每一个询问，输出一个整数，为划分成的子树个数。

数据范围
1 ≤ T ≤ 20

0 ≤ y ≤ 100000

小数据

1 ≤ n, q ≤ 5000

大数据

1 ≤ n, q ≤ 100000

样例输入
2
3
1 2
2 3
3
1
2 2 1
1
5
1 2
2 3
2 4
2 5
4
1
2 2 1
2 3 2
1
样例输出
Case #1:
1
3
Case #2:
1
5

#include <iostream>
#include <vector>
#include <map>
using namespace std;

//利用hash_map存储边信息，利用vector存储节点的颜色信息
int main()
{
	int n;
	multimap<int, int> matrix; //存储边的信息
	while(cin>>n)
	{
		//cout<<"n="<<n<<endl;
		for(int i=1; i<=n; i++)
		{
			cout<<"Case #"<<i<<":"<<endl;
			int node_n;
			cin>>node_n;
			//cout<<"node_n="<<node_n<<endl;
			vector<int> node(node_n, 0); //存储节点的颜色值
			int a = 0, b = 0;
			for(int j=0; j<node_n-1; j++)
			{
				cin>>a>>b;
				//cout<<"a="<<a<<", b="<<b<<endl;
				matrix.insert(pair<int, int>(a-1, b-1)); //插入边信息
			}
			//cout<<"matrix.size="<<matrix.size()<<endl;
			int oper_n;
			cin>>oper_n;
			int option = 0;
			int nodeth = 0, color = 0;
			bool no2Flag = false;
			bool again1Flag = false;
			for(int j=0; j<oper_n; j++)
			{
				cin>>option;
				if(option == 1 && !no2Flag) //一直没有节点颜色改变的情况
					cout<<1<<endl;
				else if(option == 1 && no2Flag) //有节点颜色改变的情况下，求划分子树的个数
				{
					int result = 0;
					for(int k=0; k<node_n; k++) //计算划分子树的个数
					{
						bool sameFlag = false; //某节点是否有颜色相同的子节点的标志
						int count = matrix.count(k); //某一节点与子节点的边个数
						multimap<int, int>::iterator iter; //multimap的迭代器
						if(count)
							iter = matrix.find(k); //寻找第一条与子节点的边
						while(count--)
						{
							if(node[k] == node[iter->second]) //母节点与子节点的颜色一样
							{
								sameFlag = true; //记录此节点有颜色相同的相邻节点的标志
								break; //停止此节点与其他子节点的比较
							}
						}
						if(!sameFlag) //此节点没有颜色相同的相邻节点的情况
							result++; //子树个数加1
					}
					cout<<result<<endl;
					again1Flag = true;
				}
				else if(option == 1 && again1Flag) //有节点改变的情况下，连续出现1的命令
					cout<<result<<endl;
				else if(option == 2) //命令为2的情况
				{
					cin>>nodeth>>color;
					node[nodeth-1] = color; //修改此节点的颜色值
					no2Flag = true; //修改节点颜色改变的标志
					again1Flag = false; //不再连续出现1命令
				}
			}
			matrix.clear();
		}
	}
	return 0;
}
