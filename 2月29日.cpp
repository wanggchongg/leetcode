// 描述
// 给定两个日期，计算这两个日期之间有多少个2月29日（包括起始日期）。

// 只有闰年有2月29日，满足以下一个条件的年份为闰年：

// 1. 年份能被4整除但不能被100整除

// 2. 年份能被400整除

// 输入
// 第一行为一个整数T，表示数据组数。

// 之后每组数据包含两行。每一行格式为"month day, year"，表示一个日期。month为{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"}中的一个字符串。day与year为两个数字。

// 数据保证给定的日期合法且第一个日期早于或等于第二个日期。

// 输出
// 对于每组数据输出一行，形如"Case #X: Y"。X为数据组数，从1开始，Y为答案。

// 数据范围
// 1 ≤ T ≤ 550

// 小数据：

// 2000 ≤ year ≤ 3000

// 大数据：

// 2000 ≤ year ≤ 2×10^9

// 样例输入
// 4
// January 12, 2012
// March 19, 2012
// August 12, 2899
// August 12, 2901
// August 12, 2000
// August 12, 2005
// February 29, 2004
// February 29, 2012
// 样例输出
// Case #1: 1
// Case #2: 0
// Case #3: 1
// Case #4: 3

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LeapYear
{
private:
	int year1;
	int month1;
	int day1;
	int year2;
	int month2;
	int day2;

public:
	int judgeMonth(string month)
	{
		if("January" == month) return 1;
		else if("February" == month) return 2;
		else if("March" == month) return 3;
		else if("April" == month) return 4;
		else if("May" == month) return 5;
		else if("June" == month) return 6;
		else if("July" == month) return 7;
		else if("August" == month) return 8;
		else if("September" == month) return 9;
		else if("October" == month) return 10;
		else if("November" == month) return 11;
		else return 12;
	}

	void init()
	{
		string monthStr;
		char sig;
		cin>>monthStr>>day1>>sig>>year1;
		month1 = judgeMonth(monthStr);
		cin>>monthStr>>day2>>sig>>year2;
		month2 = judgeMonth(monthStr);
	}

	int leapYearNum()
	{
		int lyNum = 0;
		int divide_4 = 0, divide_400 = 0, ndivide_100 = 0;
		if(month1<=1 || (month1<=2&&day1<=29))
			year1 -= 1;
		if(month2<=1 || (month2<=2&&day2<29))
			year2 -= 1;
		//从年份0年到开始年的闰年个数-从年分0年到结束年的闰年个数
		divide_400 = year2/400-year1/400;
		divide_4 = year2/4-year1/4;
		ndivide_100 = year2/100-year1/100;
		lyNum = divide_4 + divide_400 - ndivide_100;
		return lyNum;
	}
};

int main()
{
	int n = 0;
	LeapYear leapYear;
	while(cin>>n)
	{
		for(int i=1; i<=n; i++)
		{
			int lyNum = 0;
			leapYear.init();
			lyNum = leapYear.leapYearNum();
			cout<<"Case #"<<i<<": "<<lyNum<<endl;
		}
	}
	return 0;
}
