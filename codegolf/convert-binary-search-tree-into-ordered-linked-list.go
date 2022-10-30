/*

Write the shortest possible program that turns a binary search tree into an ordered doubly-linked list, by modifying the pointers to the left and the right children of each node.

Arguments: a pointer to the root of the binary tree.

Return value: a pointer to the head of the linked list.

The binary tree node has three fields:

    the ordering key, an integer
    a pointer to the left child
    a pointer to the right child

The pointers should be modified so that "left child" points to the previous node of the list and "right child" points to the next node of the list.

    Y̶o̶u̶'̶r̶e̶ ̶n̶o̶t̶ ̶a̶l̶l̶o̶w̶e̶d̶ ̶t̶o̶ ̶c̶r̶e̶a̶t̶e̶/̶a̶l̶l̶o̶c̶a̶t̶e̶ ̶m̶o̶r̶e̶ ̶n̶o̶d̶e̶s̶.
    The tree and the list are both ordered increasingly.
    You have to write the implementation of the node object.
    The tree is not necessarily complete

Example:

input:
   5 <- root
  / \
 2   8
/ \ / \
1 4 6 9

output:
head -> 1-2-4-5-6-8-9

EDIT: I removed the 1st rule, since people complained it was not possible to do using functional programming languages.

*/

package main

import "fmt"

func main() {
	n := &Node{
		value: 5,

		left: &Node{
			value: 2,
			left:  &Node{value: 1},
			right: &Node{value: 4},
		},

		right: &Node{
			value: 8,
			left:  &Node{value: 6},
			right: &Node{value: 9},
		},
	}

	print(conv(n))
}

type Node struct {
	value       int
	left, right *Node
}

type Element struct {
	value int
	next  *Element
}

func conv(n *Node) *Element {
	var h, t *Element
	walk(n, &h, &t)
	return h
}

func walk(n *Node, h, t **Element) {
	if n == nil {
		return
	}

	walk(n.left, h, t)

	e := &Element{value: n.value}
	if *h == nil {
		*h = e
	} else {
		(*t).next = e
	}
	*t = e

	walk(n.right, h, t)
}

func print(e *Element) {
	for ; e != nil; e = e.next {
		fmt.Printf("%d ", e.value)
	}
	fmt.Println()
}
