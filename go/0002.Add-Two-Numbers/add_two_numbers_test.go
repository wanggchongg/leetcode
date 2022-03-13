package _002_Add_Two_Numbers

import (
	"fmt"
	"testing"

	"leetcode/structures"
)

type question struct {
	tParams
	tResult
}

type tParams struct {
	one []int
	two []int
}

type tResult []int

func TestAddTwoNumbers(t *testing.T) {
	tests := []question{
		{
			tParams{[]int{}, []int{}},
			[]int{},
		},
		{
			tParams{one:[]int{1, 2, 3}, two:[]int{1, 2}},
			[]int{2, 4, 3},
		},
	}

	fmt.Printf("------------------------Leetcode Problem 0002------------------------\n")
	for _, test := range tests {
		t.Run("TEST", func(t *testing.T) {
			result := structures.List2Ints(
				addTwoNumbers(structures.Ints2List(test.tParams.one), structures.Ints2List(test.tParams.two)))

			if !structures.SliceIntEqual(test.tResult, result) {
				t.Errorf("【input】:%v\t【output】:%v\t【got】:%v\n", test.tParams, test.tResult, result)
			} else {
				fmt.Printf("【input】:%v\t【output】:%v\t【got】:%v\n", test.tParams, test.tResult, result)
			}
		})
	}
	fmt.Printf("\n\n\n")
}