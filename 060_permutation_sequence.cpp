// Permutation Sequence Total Accepted: 30855 Total Submissions: 135250 My Submissions Question Solution
// The set [1,2,3,…,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Note: Given n will be between 1 and 9 inclusive.

#include <iostream>
#include <vector>
using namespace std;

// 思想：
// 假设有n个元素，第K个permutation是
// a1, a2, a3, .....   ..., an
// 那么a1是哪一个数字呢？

// 那么这里，我们把a1去掉，那么剩下的permutation为
// a2, a3, .... .... an, 共计n-1个元素。 n-1个元素共有(n-1)!组排列，那么这里就可以知道

// 设变量K1 = K
// a1 = K1 / (n-1)!// 第一位的选择下标

// 同理，a2的值可以推导为
// K2 = K1 % (n-1)!
// a2 = K2 / (n-2)!

// 。。。。。

// K(n-1) = K(n-2) /2!
// a(n-1) = K(n-1) / 1!

// an = K(n-1)

class Solution {
public:
    string getPermutation(int n, int k) {
    	string result;
    	if(n<1 || n>9 || k<0)
    		return result;
    	vector<bool> visited(n, false);

    	int factor = 1;
    	for(int i=1; i<n; i++)
    	{
    		factor *= i;
    	}
    	k = k - 1;

    	for(int i=0; i<n; i++)
    	{
    		int index = k / factor;
    		k = k % factor;

    		for(int j=0; j<n; j++)
    		{
    			if(visited[j] == false)
    			{
    				if(index == 0)
    				{
    					visited[j] = true;
    					result.push_back('0'+j+1);
    					break;
    				}
    				else
    					index--;
    			}
    		}
    		if(i < n-1)
    			factor /= (n-1-i);
    	}

    	return result;
    }
};

int main()
{
	Solution solution;
	string result;
	int n, k;
	while(cin>>n>>k)
	{
		result = solution.getPermutation(n, k);
		cout<<result<<endl;
	}
	return 0;
}