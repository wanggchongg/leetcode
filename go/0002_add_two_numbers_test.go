package main

import "testing"

func TestAddTwoNumbers(t *testing.T) {
	type Args struct {
		L1, L2 *ListNode
	}

	tests := []struct {
		name    string
		args    Args
		want    int
		wantErr bool
	} {
		{

		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {

		})
	}
}