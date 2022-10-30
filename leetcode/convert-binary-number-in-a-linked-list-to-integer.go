/*

Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.

*/

package main

import "fmt"

func main() {
	fmt.Println(decimal(mklist(1, 0, 1)))
	fmt.Println(decimal(mklist(0)))
	fmt.Println(decimal(mklist(1)))
	fmt.Println(decimal(mklist(1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0)))
	fmt.Println(decimal(mklist(0, 0)))
	fmt.Println(decimal(mklist(0, 0, 1, 1)))
}

type List struct {
	data int
	next *List
}

func mklist(v ...int) *List {
	var h *List

	p := &h
	for _, v := range v {
		q := &List{data: v}
		*p, p = q, &q.next
	}
	return h
}

func decimal(l *List) int64 {
	if l == nil {
		return -1
	}

	v := int64(0)
	for {
		v |= int64(l.data & 1)
		if l.next == nil {
			break
		}
		l = l.next
		v <<= 1
	}
	return v
}
