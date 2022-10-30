/*

Given a Binary Search Tree (BST) implementation, complete the traverse function which is present in the BST class.
Here you have to perform the level-order traversal on BST which is another term for Breadth First Traversal.

Examples

traverse() ➞  [10, 4, 20, 1, 5]

      10
      /   \
    4    20
  /  \
1    5

traverse() ➞ [100, 70, 200, 34, 80, 300]

       100
       /    \
    70    200
  /    \          \
34   80      300

Notes

Make sure you don't modify the code that is already in the Code tab. Only complete the traverse() function and return an array.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	v1 := []int{10, 4, 1, 5, 20}
	r1 := []int{10, 4, 20, 1, 5}
	test(v1, r1)

	v2 := []int{100, 70, 34, 80, 200, 300}
	r2 := []int{100, 70, 200, 34, 80, 300}
	test(v2, r2)

	v3 := []int{100, 200, 70, 34, 80, 85, 85, 111}
	r3 := []int{100, 70, 200, 34, 80, 111, 85, 85}
	test(v3, r3)

	v4 := []int{1}
	r4 := []int{1}
	test(v4, r4)

	v5 := []int{100, 25, 22, 75, 122, 111, 112, 55}
	r5 := []int{100, 25, 122, 22, 75, 111, 55, 112}
	test(v5, r5)
}

func test(v, r []int) {
	b := &bst{}
	for i := range v {
		b.insert(v[i])
	}
	p := b.traverse()
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type node struct {
	val   int
	left  *node
	right *node
}

type bst struct {
	root *node
}

func (b *bst) insert(v int) *node {
	n := &node{val: v}

	l, p := &b.root, b.root
	for {
		if p == nil {
			*l = n
			break
		}

		if p.val >= v {
			l, p = &p.left, p.left
		} else {
			l, p = &p.right, p.right
		}
	}
	return n
}

func (b *bst) traverse() []int {
	r := []int{}
	q := []*node{b.root}
	for ; len(q) > 0; q = q[1:] {
		p := q[0]
		if p == nil {
			continue
		}

		r = append(r, p.val)
		q = append(q, p.left)
		q = append(q, p.right)
	}

	return r
}
