#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//求子数组的最小和
//利用的是dp的思想，依次遍历数组中的每个元素，把他们相加，如果加起来大于0，则
//把当前元素之和清为0，否则则和最小和比较，更新最小和，最后得到必是子数组的最小和
//时间复杂度：o(n) 空间复杂度：o(1)
int minSum(vector<int> &num)
{
	int min_sum = 0, sum = 0;

	for(int i=0; i<num.size(); i++)
	{
		sum += num[i];
		if(sum > 0) sum = 0;
		if(sum < min_sum)
			min_sum = sum;
	}
	if(min_sum == 0) //数组中只有正数
	{
		min_sum = num[0];
		for(int i=1; i<num.size(); i++)
		{
			if(num[i]<min_sum)
				min_sum = num[i];
		}
	}
	return min_sum;
}

//求子数组的最大和
//利用的是dp的思想，依次遍历数组中的每个元素，把他们相加，如果加起来小于0，则
//把当前元素之和清为0，否则则和最大和比较，更新最大和，最后得到必是子数组的最大和
//时间复杂度：o(n)
int maxSum(vector<int> &num)
{
	int max_sum = 0, sum = 0;

	for(int i=0; i<num.size(); i++)
	{
		sum += num[i];
		if(sum < 0) sum = 0;
		if(sum > max_sum)
			max_sum = sum;
	}
	if(max_sum == 0) //数组中只有负数
	{
		max_sum = num[0];
		for(int i=1; i<num.size(); i++)
		{
			if(num[i]>max_sum)
				max_sum = num[i];
		}
	}
	return max_sum;
}

//求子数组的和的绝对值的最小值
//暴力穷举法
//时间复杂度：o(n^2) 空间复杂度：o(1)
int minAbsSum1(vector<int> &num)
{
	int min_abs_sum = INT_MAX;
	for(int i=0; i<num.size(); i++)
	{
		int cur_sum = 0;
		for(int j=i; j<num.size(); j++)
		{
			cur_sum += num[j];
			if(abs(cur_sum) < min_abs_sum)
				min_abs_sum = abs(cur_sum);
		}
	}
	return min_abs_sum;
}

//求子数组的和的绝对值的最小值
//先计算所有sum[0-j] 0<= j <n，然后对sum[0-j]的数组进行排序，那么对于任何i,j段的和等于：sum[i-j]= sum[0-j] - sum[0-i];
//设置数组sum用来存储子数组0-j的和
//因为已经对sum进行了排序，排序后只需要找到sum[z]-sum[z-1],sum[z]  (0<=z<sum.size())的绝对值的最小值即可。z为排序后的索引
//如果是sum[z]情形，z为排序后的索引，则minAbs = abs(sum[0-i])
//如果是sum[z]-sum[z-1]情形，则minAbs = abs(sum[i]-sum[j])
//时间复杂度：o(nlogn) 空间复杂度：o(n)
int minAbsSum2(vector<int> &num)
{
	if(num.size()==0) return 0;
	if(num.size()==1) return abs(num[0]);
	int min_abs_sum;
	vector<int> sum;
	int cur_sum = 0;
	for(int i=0; i<num.size(); i++)
	{
		cur_sum += num[i];
		if(cur_sum == 0)
			return 0;
		sum.push_back(cur_sum);
	}
	sort(sum.begin(), sum.end());

	min_abs_sum = abs(sum[0]);
	for(int i=0; i<sum.size()-1; i++)
	{
		int temp1 = abs(sum[i+1]);
		int temp2 = abs(sum[i+1]-sum[i]);
		cur_sum = (temp1<temp2)?temp1:temp2;
		if(cur_sum == 0)
			return 0;
		if(cur_sum<min_abs_sum)
			min_abs_sum = cur_sum;
	}
	return min_abs_sum;
}

//求子数组的和的绝对值的最da值
//暴力穷举法
//时间复杂度：o(n^2) 空间复杂度：o(1)
int maxAbsSum1(vector<int> &num)
{
	int max_abs_sum = 0;
	for(int i=0; i<num.size(); i++)
	{
		int cur_sum = 0;
		for(int j=i; j<num.size(); j++)
		{
			cur_sum += num[j];
			if(abs(cur_sum) > max_abs_sum)
				max_abs_sum = abs(cur_sum);
		}
	}
	return max_abs_sum;
}

//求子数组的和的绝对值的最大值
//先计算所有sum[0-j] 0<= j <n，然后对sum[0-j]的数组进行排序，那么对于任何i,j段的和等于：sum[i-j]= sum[0-j] - sum[0-i];
//设置数组sum用来存储子数组0-j的和
//因为已经对sum进行了排序，排序后只需要找到sum[sum.size()-1]-sum[0],sum[z]  (0<=z<sum.size())的绝对值的最大值即可。z为排序后的索引
//如果是sum[z]情形，z为排序后的索引，则maxAbs = abs(sum[0-i])
//如果是sum[sum.size()-1]-sum[0]情形，则maxAbs = abs(sum[i]-sum[j])
//时间复杂度：o(nlogn) 空间复杂度：o(n)
int maxAbsSum2(vector<int> &num)
{
	if(num.size()==0) return 0;
	if(num.size()==1) return abs(num[0]);
	int max_abs_sum;
	vector<int> sum;
	int cur_sum = 0;
	for(int i=0; i<num.size(); i++)
	{
		cur_sum += num[i];
		if(cur_sum == 0)
			return 0;
		sum.push_back(cur_sum);
	}
	sort(sum.begin(), sum.end());
	max_abs_sum = abs(sum[sum.size()-1]-sum[0]);
	for(int i=0; i<sum.size(); i++)
	{
		cur_sum = abs(sum[i]);
		if(cur_sum>max_abs_sum)
			max_abs_sum = cur_sum;
	}
	return max_abs_sum;
}

int main()
{
	int n;
	while(cin>>n)
	{
		vector<int> num;
		int number;
		for(int i=0; i<n; i++)
		{
			cin>>number;
			num.push_back(number);
		}
		cout<<"minSum = "<<minSum(num)<<endl;
		cout<<"maxSum = "<<maxSum(num)<<endl;
		cout<<"minAbsSum1 = "<<minAbsSum1(num)<<endl;
		cout<<"minAbsSum2 = "<<minAbsSum2(num)<<endl;
		cout<<"maxAbsSum1 = "<<maxAbsSum1(num)<<endl;
		cout<<"maxAbsSum2 = "<<maxAbsSum2(num)<<endl;
		cout<<"------------------------------------"<<endl;
	}
	return 0;
}