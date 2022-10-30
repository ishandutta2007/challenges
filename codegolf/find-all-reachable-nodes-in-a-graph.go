/*

You are given a directed graph in an adjacency dictionary format. This can be whatever format is most natural for your language.
For instance, in python, this would be a dictionary with keys of nodes and values which are lists of nodes which that node has an edge to. For instance:

G={1: [2, 3], 2: [3], 3: [1], 4:[2]}
Be reasonable. A dictionary of frozen sets is not allowed, even if it makes your code shorter. A list of lists is fine, if your language doesn't have dictionaries.

Your task is to implement a function that takes a directed graph and a starting node, and outputs all nodes reachable from the starting node.
The output format is also flexible. A return value from a function is fine, so is print, etc.

Test case:

G={1: [2, 3], 2: [3], 3: [1], 4:[2]}
s=1

R(G,s)
{1,2,3}
Fewest characters wins. I will clarify if needed.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test(map[int][]int{
		1: {2, 3},
		2: {3},
		3: {1},
		4: {2},
	}, 1, []int{1, 2, 3})

	test(map[int][]int{}, 20, []int{20})
}

func test(g map[int][]int, s int, r []int) {
	p := reachable(g, s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func reachable(g map[int][]int, s int) []int {
	m := make(map[int]bool)
	r := []int{}
	q := []int{s}
	for len(q) > 0 {
		if v := q[0]; !m[v] {
			r = append(r, v)
			q = append(q, g[v]...)
			m[v] = true
		}
		q = q[1:]
	}
	sort.Ints(r)
	return r
}
