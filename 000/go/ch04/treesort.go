// treesort.
package main 

import (
	"fmt"
	)

type tree struct {
	value 		int
	left, right *tree
}

// sort sorts value in place
func Sort(values []int) {
	var root *tree
	for _, v := range values {
		root = add(root, v)
	}
	appendValues(values[:0], root)
}
// appendValues appedns the elements of t to values in order
// and returns the resulting slice.
func appendValues(values []int, t *tree) []int {
	if t != nil {
		values = appendValues(values, t.left)
		values = append(values, t.value)
		values = appendValues(values, t.right)
	}
	return values
}
func add(t *tree, value int) *tree {
	if t == nil {
		t = new(tree)
		t.value = value
		return t
	}
	if value < t.value {
		t.left = add(t.left, value)
	} else {
		t.right = add(t.right, value)
	}
	return t
}
func test_tree() {
	var a = []int {10, 8, 3, 4, 2, 6, 5, 7, 11, 9 }
	fmt.Println("befor sort: ", a)
	Sort(a)
	fmt.Println("Sorted: ", a)
}
func main() {
	test_tree()
}