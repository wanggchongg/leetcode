//01背包之金矿模型
#include <iostream>
using namespace std;
#define max(x, y) ((x>=y)?x:y)

const int max_n = 100;//程序支持的最多金矿数
const int max_people = 10000;//程序支持的最多人数

int peopleTotal;//可以用于挖金子的人数
int n;//金矿数
int peopleNeed[max_n];//每座金矿需要的人数
int gold[max_n];//每座金矿能够挖出来的金子数
int maxGold[max_people][max_n];//maxGold[i][j]保存了i个人挖前j个金矿能够得到的最大金子数，等于-1时表示未知

//初始化数据
void init()
{
    for(int i=0; i<n; i++)
        cin>>peopleNeed[i]>>gold[i];
    for(int i=0; i<=peopleTotal; i++)
        for(int j=0; j<n; j++)
            maxGold[i][j] = -1;//等于-1时表示未知 [对应动态规划中的“做备忘录”]
}

//获得在仅有people个人和前mineNum个金矿时能够得到的最大金子数，注意“前多少个”也是从0开始编号的
int GetMaxGold(int people, int mineNum)
{
    //申明返回的最大金子数
    int retMaxGold;

    //如果这个问题曾经计算过  [对应动态规划中的“做备忘录”]
    if(maxGold[people][mineNum] != -1)
    {
        //获得保存起来的值
        retMaxGold = maxGold[people][mineNum];
    }
    else if(mineNum == 0)//如果仅有一个金矿时 [对应动态规划中的“边界”]
    {
        //当给出的人数足够开采这座金矿
        if(people >= peopleNeed[mineNum])
        {
            //得到的最大值就是这座金矿的金子数
            retMaxGold = gold[mineNum];
        }
        else//否则这唯一的一座金矿也不能开采
        {
            //得到的最大值为0个金子
            retMaxGold = 0;
        }
    }
    else if(people >= peopleNeed[mineNum])//如果给出的人够开采这座金矿 [对应动态规划中的“最优子结构”]
    {
        //考虑开采与不开采两种情况，取最大值
        retMaxGold = max(GetMaxGold(people - peopleNeed[mineNum],mineNum -1) + gold[mineNum], GetMaxGold(people,mineNum - 1));
    }
    else//否则给出的人不够开采这座金矿 [对应动态规划中的“最优子结构”]
    {
        //仅考虑不开采的情况
        retMaxGold  = GetMaxGold(people,mineNum - 1);
    }

    //做备忘录
    maxGold[people][mineNum] = retMaxGold;
    return retMaxGold;
}

int main()
{
	while(cin>>peopleTotal>>n)
	{//初始化数据
	    init();
	    //输出给定peopleTotal个人和n个金矿能够获得的最大金子数，再次提醒编号从0开始，所以最后一个金矿编号为n-1
	    cout<<"total_gold="<<GetMaxGold(peopleTotal,n-1)<<endl;
    }
    return 0;
}
