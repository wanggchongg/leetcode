// Search in Rotated Sorted Array II Total Accepted: 39136 Total Submissions: 124915 My Submissions Question Solution
// Follow up for "Search in Rotated Sorted Array":
// What if duplicates are allowed?

// Would this affect the run-time complexity? How and why?

// Write a function to determine if a given target is in the array.

#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
	int search(vector<int> &nums, int target) {
		int start = 0, end = nums.size()-1, mid = 0;

		while (start <= end) {
			mid = start + (end - start) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			if (nums[start] < nums[mid]) {
				if (nums[start] <= target && target <= nums[mid]) {
					end = mid - 1;
				}
				else {
					if (nums[start] == target)
						return start;
					start = mid + 1;
				}
			}

			else {
				if (nums[mid] <= target && target <= nums[end]) {
					start = mid + 1;
				}
				else {
					if (nums[end] == target)
						return end;
					end = mid - 1;
				}
			}
		}

		return -1;
	}
};

int main() {
	Solution solution;
	int n;
	vector<int> nums;
	int value;
	int target;
	int result;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> value;
			nums.push_back(value);
		}
		cin >> target;
		result = solution.search(nums, target);
		cout << result << endl;
		nums.clear();
	}
	return 0;
}