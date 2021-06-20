package main

import (
	"reflect"
	"testing"
)

func TestLRUCache(t *testing.T) {
	type Args struct {
		function string
		params []int
	}

	tests := []struct {
		args    Args
		want    interface{}
	} {
		{
			args: Args{
				function: "LRUCache",
				params: []int{2},
			},
			want: LRUCache{},
		},
		{
			args: Args{
				function: "put",
				params: []int{1, 1},
			},
			want: nil,
		},
		{
			args: Args{
				function: "put",
				params: []int{2, 2},
			},
			want: nil,
		},
		{
			args: Args{
				function: "get",
				params: []int{1},
			},
			want: 1,
		},
		{
			args: Args{
				function: "put",
				params: []int{3, 3},
			},
			want: nil,
		},
		{
			args: Args{
				function: "get",
				params: []int{2},
			},
			want: -1,
		},
		{
			args: Args{
				function: "put",
				params: []int{4, 4},
			},
			want: nil,
		},
		{
			args: Args{
				function: "get",
				params: []int{1},
			},
			want: -1,
		},
		{
			args: Args{
				function: "get",
				params: []int{3},
			},
			want: 3,
		},
		{
			args: Args{
				function: "get",
				params: []int{4},
			},
			want: 4,
		},
	}

	lruCache := LRUCache{}
	for _, tt := range tests {
		t.Run("TEST", func(t *testing.T) {
			if tt.args.function == "LRUCache" {
				lruCache = Constructor(tt.args.params[0])
				if reflect.TypeOf(lruCache) != reflect.TypeOf(tt.want) {
					t.Errorf("function LRUCache got = %v, want %v", reflect.TypeOf(lruCache), reflect.TypeOf(tt.want.(LRUCache)))
				}
			}

			if tt.args.function == "put" {
				lruCache.Put(tt.args.params[0], tt.args.params[1])
			}

			if tt.args.function == "get" {
				got := lruCache.Get(tt.args.params[0])
				if got != tt.want.(int) {
					t.Errorf("function get got = %v, want %v", tt.args.params[0], tt.want.(int))
				}
			}
		})
	}
}