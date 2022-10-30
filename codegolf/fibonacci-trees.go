/*

Background

Fibonacci trees Tn are a sequence of rooted binary trees of height n−1. They are defined as follows:

T0 has no nodes.
T1 has a single node (the root).
The root node of Tn+2 has Tn+1 as its left subtree and Tn as its right subtree.

T0 T1   T2      T3           T4
    O    O       O            O
        /       / \         /   \
       O       O   O       O     O
              /           / \   /
             O           O   O O
                        /
                       O

Each tree in this sequence is the most unbalanced possible state of an AVL tree of same height.
Challenge

Given the number n, output the n-th Fibonacci tree.

By the usual sequence rules, your function or program may behave as one of the following:

    Take n

as input, and output the n-th tree (n
can be 0- or 1-indexed; the given example is 0-based)
Take n as input, and output the first n trees
Take no input, and output the sequence of trees indefinitely

A binary tree can be output in any acceptable ways, including but not limited to

    a built-in tree object if your language has one,
    a nested array, an ADT, or its textual representation,
    a human-readable ASCII/Unicode art, or
    a flattened list of nodes labeled as numbers in level order.

Shortest code in bytes wins.

*/

package main

import "fmt"

func main() {
	for i := 0; i < 32; i++ {
		fmt.Println(count(fibtree(i)))
	}
}

type Node struct {
	Left, Right *Node
}

func fibtree(n int) *Node {
	var (
		a, c *Node
		b    = new(Node)
	)

	if n == 0 {
		return a
	}
	if n == 1 {
		return b
	}
	for i := 1; i < n; i++ {
		c = &Node{
			Left:  b,
			Right: a,
		}
		a, b = b, c
	}
	return c
}

func count(n *Node) int {
	if n == nil {
		return 0
	}
	return 1 + count(n.Left) + count(n.Right)
}
