package leetcode

// 时间复杂度 o(n), 空间复杂度 o(n)
func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	for k, v := range nums {
		if idx, ok := m[target - v]; ok {
			return []int{idx, k}
		}
		m[v] = k
	}
	return nil
}

func twoSum1(nums []int, target int) []int {
	for i := 0; i < len(nums); i++ {
		for j := i+1; j < len(nums); j++ {
			if nums[i] + nums[j] == target {
				return []int{i, j}
			}
		}
	}
	return nil
}