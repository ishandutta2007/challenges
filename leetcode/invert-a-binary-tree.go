/*

Invert a binary tree.

Trivia:
This problem was inspired by this original tweet by Max Howell:

    Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.

*/

package main

import "fmt"

func main() {
	test([]interface{}{4, 2, 7, 1, 3, 6, 9})
}

func test(a []interface{}) {
	t := mktree(a)
	t.dump()
	t.invert()
	t.dump()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type Node struct {
	val   int
	lvl   int
	left  *Node
	right *Node
}

func mktree(a []interface{}) *Node {
	var r *Node
	p := []**Node{&r}
	l := []int{0}
	for _, v := range a {
		switch v := v.(type) {
		case int:
			n := &Node{val: v, lvl: l[0]}
			p = append(p, &n.left, &n.right)
			l = append(l, n.lvl+1, n.lvl+1)
			*p[0] = n
		case nil:
		default:
			panic(fmt.Errorf("unknown type %T", v))
		}
		p = p[1:]
		l = l[1:]
	}
	return r
}

func (n *Node) invert() *Node {
	if n == nil {
		return nil
	}
	n.left, n.right = n.right.invert(), n.left.invert()
	return n
}

func (n *Node) flatten() []*Node {
	if n == nil {
		return nil
	}

	l := []*Node{}
	p := []*Node{n}
	for ; len(p) > 0; p = p[1:] {
		l = append(l, p[0])
		if p[0].left != nil {
			p = append(p, p[0].left)
		}
		if p[0].right != nil {
			p = append(p, p[0].right)
		}
	}
	return l
}

func (n *Node) dump() {
	var c []string
	l := n.flatten()
	s := ""
	for i := 0; i < len(l); i++ {
		s += fmt.Sprintf("%d ", l[i].val)
		if i+1 < len(l) && l[i].lvl != l[i+1].lvl {
			c = append(c, s)
			s = ""
		}
	}
	if s != "" {
		c = append(c, s)
	}

	w := 0
	for i := range c {
		w = max(w, len(c[i]))
	}

	for i := range c {
		for j := 0; j < (w-len(c[i]))/2; j++ {
			fmt.Printf(" ")
		}
		fmt.Println(c[i])
	}
	fmt.Println()
}
