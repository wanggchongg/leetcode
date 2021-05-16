// Remove Duplicates from Sorted Array II Total Accepted: 45173 Total Submissions: 147990 My Submissions Question Solution
// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?

// For example,
// Given sorted array nums = [1,1,1,2,2,3],

// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
	int removeDuplicates(vector<int> &nums) {
		if (nums.size() == 0) {
			return 0;
		}
		if (nums.size() == 1) {
			return 1;
		}
		int del_count = 0;
		int same_count = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[i-1]) {
				same_count++;
			}
			else {
				same_count = 1;
			}

			if (same_count > 2) {
				del_count++;
			}
			nums[i-del_count] = nums[i];
		}
		return nums.size() - del_count;
	}
};

int main() {
	Solution solution;
	vector<int> nums;
	int result;
	int n, value;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> value;
			nums.push_back(value);
		}
		result =  solution.removeDuplicates(nums);
		cout << result << endl;
		for (int i = 0; i < result; i++) {
			cout << nums[i] << " ";
		}
		cout << endl;
		nums.clear();
	}
	return 0;
}