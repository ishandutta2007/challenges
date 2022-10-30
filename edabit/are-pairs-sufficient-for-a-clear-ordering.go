/*

Create a function that returns true if an array of pairs are sufficient for a clear ordering of all items.

To illustrate:

clearOrdering([["D", "A"], ["C", "B"], ["A", "C"]]) ➞ true
// Since unequivocally: "D" < "A" < "C" < "B"

On the other hand:

clearOrdering([["D", "A"], ["B", "A"], ["C", "D"]]) ➞ false
// Since we know that "C" < "D" < "A", and we know "B" < "A"
// but we don't know anything about "B"s relationship with "C" or "D".

Examples

clearOrdering([["S", "T"], ["T", "U"], ["U", "V"]]) ➞ true

clearOrdering([["T", "S"], ["T", "U"], ["U", "V"], ["V", "W"]]) ➞ false

Notes

See Comments for a good visualization of the question.

*/

package main

import (
	"errors"
)

func main() {
	assert(clearorder([][2]rune{{'D', 'A'}, {'C', 'B'}, {'A', 'C'}}) == true)
	assert(clearorder([][2]rune{{'D', 'A'}, {'B', 'A'}, {'C', 'D'}}) == false)
	assert(clearorder([][2]rune{{'S', 'T'}, {'T', 'U'}, {'U', 'V'}}) == true)
	assert(clearorder([][2]rune{{'T', 'S'}, {'T', 'U'}, {'U', 'V'}, {'V', 'W'}}) == false)
	assert(clearorder([][2]rune{{'A', 'D'}, {'C', 'D'}}) == false)
	assert(clearorder([][2]rune{{'A', 'D'}, {'D', 'C'}}) == true)
	assert(clearorder([][2]rune{{'c', 'd'}, {'a', 'b'}, {'b', 'c'}}) == true)
	assert(clearorder([][2]rune{{'d', 'c'}, {'a', 'b'}, {'b', 'c'}}) == false)
	assert(clearorder([][2]rune{{'a', 'b'}, {'b', 'c'}, {'c', 'd'}, {'e', 'f'}, {'d', 'e'}}) == true)
	assert(clearorder([][2]rune{{'b', 'a'}, {'b', 'c'}, {'c', 'd'}, {'e', 'f'}, {'d', 'e'}}) == false)
}

func clearorder(p [][2]rune) bool {
	id := mkassoc(p)
	g := newgraph(len(id))
	for _, p := range p {
		g.addedge(id[p[0]], id[p[1]])
	}

	l, err := g.topsort()
	if err != nil {
		return false
	}

	for i := 0; i < len(l)-1; i++ {
		if !g.connected(l[i], l[i+1]) {
			return false
		}
	}

	return true
}

func mkassoc(p [][2]rune) (id map[rune]int) {
	id = make(map[rune]int)
	nid := 0
	for i := range p {
		for _, r := range p[i] {
			if _, f := id[r]; !f {
				id[r] = nid
				nid++
			}
		}
	}
	return
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://en.wikipedia.org/wiki/Topological_sorting#Kahn's_algorithm
// https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
type Graph struct {
	list [][]int
}

func newgraph(n int) *Graph {
	return &Graph{list: make([][]int, n)}
}

func (g *Graph) addedge(u, v int) {
	g.list[u] = append(g.list[u], v)
}

func (g *Graph) connected(u, v int) bool {
	for _, w := range g.list[u] {
		if v == w {
			return true
		}
	}
	return false
}

func (g *Graph) topsort() ([]int, error) {
	in := make([]int, len(g.list))
	for i := range g.list {
		for _, v := range g.list[i] {
			in[v]++
		}
	}

	var q []int
	for i := range in {
		if in[i] == 0 {
			q = append(q, i)
		}
	}

	var (
		t []int
		l int
	)
	for len(q) > 0 {
		u := q[0]
		q = q[1:]
		t = append(t, u)

		for _, v := range g.list[u] {
			if in[v]--; in[v] == 0 {
				q = append(q, v)
			}
		}
		l++
	}

	if l != len(g.list) {
		return nil, errors.New("graph has a cycle")
	}
	return t, nil
}
