/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3



But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3



Note:
Bonus points if you could solve it both recursively and iteratively.

*/

package main

import "fmt"

func main() {
	test([]interface{}{4, 2, 7, 1, 3, 6, 9})
	test([]interface{}{1, 2, 2, 3, 4, 4, 3})
	test([]interface{}{1, 2, 2, nil, 3, nil, 3})
}

func test(a []interface{}) {
	t := mktree(a)
	t.dump()
	fmt.Println(t.symmetricr(), t.symmetrici())
	fmt.Println()
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

func (n *Node) symmetricr() bool {
	if n == nil {
		return true
	}
	return n.symmetricr0(n.left, n.right)
}

func (n *Node) symmetricr0(l, r *Node) bool {
	if l == nil && r == nil {
		return true
	}
	if !(l != nil && r != nil) {
		return false
	}
	return l.val == r.val && n.symmetricr0(l.left, r.right) && n.symmetricr0(l.right, r.left)
}

func (n *Node) symmetrici() bool {
	if n == nil {
		return true
	}

	s := []*Node{n.left, n.right}
	for ; len(s) >= 2; s = s[2:] {
		l, r := s[0], s[1]
		if l == nil && r == nil {
			continue
		}
		if !(l != nil && r != nil) || l.val != r.val {
			return false
		}
		s = append(s, l.left, r.right)
		s = append(s, l.right, r.left)
	}
	return true
}
