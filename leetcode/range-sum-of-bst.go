/*

Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	const null = math.MinInt32
	test([]int{10, 5, 15, 3, 7, null, 18}, 7, 15)
	test([]int{10, 5, 15, 3, 7, 13, 18, 1, null, 6}, 6, 10)
}

func test(a []int, L, R int) {
	var r *Node
	for i := range a {
		p := r.insert(a[i])
		if r == nil {
			r = p
		}
	}
	fmt.Println(r.rangesum(L, R))
}

type Node struct {
	val         int
	left, right *Node
}

func nod(val int) *Node {
	return &Node{
		val: val,
	}
}

func (n *Node) insert(val int) *Node {
	p := nod(val)
	if n == nil {
		return p
	}
	for {
		if val < n.val {
			if n.left == nil {
				n.left = p
				break
			} else {
				n = n.left
			}
		} else {
			if n.right == nil {
				n.right = p
				break
			} else {
				n = n.right
			}
		}
	}
	return p
}

func (n *Node) rangesum(L, R int) int {
	if n == nil {
		return 0
	}

	switch {
	case n.val < L:
		return n.right.rangesum(L, R)
	case n.val > R:
		return n.left.rangesum(L, R)
	default:
		return n.val + n.left.rangesum(L, R) + n.right.rangesum(L, R)
	}
}
