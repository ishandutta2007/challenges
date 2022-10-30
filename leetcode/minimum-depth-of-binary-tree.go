/*

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

*/

package main

import "fmt"

func main() {
	test([]interface{}{3, 9, 20, nil, nil, 15, 7})
	test([]interface{}{1, 3, 4, 5, 6, 7, 8, 9, 10})
	test([]interface{}{1024})
	test([]interface{}{1, 2, 3, nil, nil, 5, 6, 7})
}

func test(a []interface{}) {
	t := mktree(a)
	fmt.Println(t.mindepth())
}

func min(a, b int) int {
	if a < b {
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

func (n *Node) mindepth() int {
	if n == nil {
		return 0
	}
	return 1 + min(n.left.mindepth(), n.right.mindepth())
}
