/*

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

*/

package main

import "fmt"

func main() {
	test([]interface{}{3, 9, 20, nil, nil, 15, 7})
	test([]interface{}{1, 3, 4, 5, 6, 7, 8, 9, 10})
}

func test(a []interface{}) {
	t := mktree(a)
	fmt.Println(t.maxdepth())
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type Node struct {
	val   int
	left  *Node
	right *Node
}

func mktree(a []interface{}) *Node {
	var r *Node
	p := []**Node{&r}
	for _, v := range a {
		switch v := v.(type) {
		case int:
			n := &Node{val: v}
			p = append(p, &n.left, &n.right)
			*p[0] = n
		case nil:
		default:
			panic(fmt.Errorf("unknown type %T", v))
		}
		p = p[1:]
	}
	return r
}

func (n *Node) maxdepth() int {
	if n == nil {
		return 0
	}
	return 1 + max(n.left.maxdepth(), n.right.maxdepth())
}
