#include <iostream>
#include <vector>
using namespace std;

struct LNode {
	int key;
	LNode *next;
	LNode(int key):key(key), next(NULL) {}
};

// 两个指针p、q沿next向后遍历，并保证p之前的元素(除首元素外)比key小, p与q之间的元素(除p所指元素外)比key大
// 最后交换首元素和p所指元素的值
LNode *Partition(LNode *begin, LNode *end) {
	int key = begin->key;
	LNode *p = begin;
	LNode *q = begin->next;
	int temp = 0;
	while (q != end) {
		if (q->key < key) {
			p = p->next;
			temp = p->key;
			p->key = q->key;
			q->key = temp;
		}
		q = q->next;
	}
	temp = begin->key;
	begin->key = p->key;
	p->key = temp;
	return p;
}

// 调用时end赋值为NULL
void QuickSort(LNode *begin, LNode *end) {
	if (begin != end) {
		LNode *partition = Partition(begin, end);
		QuickSort(begin, partition);
		QuickSort(partition->next, end);
	}
}



int Partition(vector<int>& nums, int begin, int end) {
	int key = nums[begin];
	int i = begin, j = begin + 1;
	int temp = 0;
	while (j <= end) {
		if (nums[j] < key) {
			i++;
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
		j++;
	}
	temp = nums[begin];
	nums[begin] = nums[i];
	nums[i] = temp;
	return i;
}


void QuickSort(vector<int> &nums, int begin, int end) {
	if (begin <= end) {
		int partition = Partition(nums, begin, end);
		QuickSort(nums, begin, partition-1);
		QuickSort(nums, partition+1, end);
	}
}

int main() {
	return 0;
}
