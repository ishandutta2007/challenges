/*

This comes from one of my favorite interview questions, though apparently it is now a fairly well-known puzzle. I have no way of knowing, but if you have already heard the answer it would be polite to let others try instead.
Task:

Write a function that takes as input a singly-linked list and returns true if it loops back on itself, and false if it terminates somewhere.

Here's some example code in C as a starting point so you can see what I mean, but feel free to write your answer in whatever language you like:

struct node
{
    void *value;
    struct node *next;
};

int has_loops(struct node *first)
{
    // write your own loop detection here
}

Hints:

There is a way to make this function run in O(n) time with a constant amount of extra memory. Good on you if you figure it out, but any working answer deserves some upvotes in my book.

*/

package main

func main() {
	l1 := &List{Value: 1}
	l2 := &List{Value: 2}
	l3 := &List{Value: 3}
	assert(cycle(link(l1, l2, l3)) == false)
	assert(cycle(link(l1, l2, l3, l1)) == true)
	assert(cycle(link(l2, l2)) == true)
	assert(cycle(link(l3, l1, l2)) == false)
	assert(cycle(link(l3, l1, l3)) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type List struct {
	Value int
	Next  *List
}

func link(l ...*List) *List {
	if len(l) == 0 {
		return nil
	}
	for i := range l {
		l[i].Next = nil
	}
	for i := 1; i < len(l); i++ {
		l[i-1].Next = l[i]
	}
	return l[0]
}

func cycle(l *List) bool {
	a, b := l, l
	for b != nil && b.Next != nil {
		a = a.Next
		b = b.Next.Next
		if a == b {
			return true
		}
	}
	return false
}
