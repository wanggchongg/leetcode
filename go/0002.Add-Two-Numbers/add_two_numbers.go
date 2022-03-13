package _002_Add_Two_Numbers

import (
	"leetcode/structures"
)

type ListNode = structures.ListNode

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var head = &ListNode{Val: 0}
	carry, tail := 0, head

	for l1 != nil || l2 != nil || carry != 0{
		n1, n2 := 0, 0
		if l1 != nil {
			n1 = l1.Val
			l1 = l1.Next
		}

		if l2 != nil {
			n2 = l2.Val
			l2 = l2.Next
		}

		tail.Next = &ListNode{Val: (n1 + n2 + carry) % 10}
		tail = tail.Next

		carry = (n1 + n2 + carry) / 10
	}

	return head.Next
}