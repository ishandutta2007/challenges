/*

A bipartite graph is a graph whose vertices can be divided into two disjoint set, such that no edge connects two vertices in the same set. A graph is bipartite if and only if it is 2-colorable.

Challenge

Your task is to, given the adjacency matrix of an undirected simple graph, determine whether it is a bipartite graph. That is, if an edge connects vertices i and j, both (i, j) and (j, i) entry of the matrix are 1.

Since the graph is undirected and simple, its adjacency matrix is symmetric and contains only 0 and 1.

Specifics

You should take an N-by-N matrix as input (in any form, e.g. list of lists, list of strings, C-like int** and size, flattened array, raw input, etc.).

The function/program should return/output a truthy value if the graph is bipartite, and falsy otherwise.

Test Cases
['00101',
 '00010',
 '10001',
 '01000',
 '10100'] : False
['010100',
 '100011',
 '000100',
 '101000',
 '010000',
 '010000'] : True (divide into {0, 2, 4, 5} and {1, 3})
['00',
 '00'] : True

*/

package main

func main() {
	assert(bipartite([][]int{
		{0, 0, 1, 0, 1},
		{0, 0, 0, 1, 0},
		{1, 0, 0, 0, 1},
		{0, 1, 0, 0, 0},
		{1, 0, 1, 0, 0},
	}) == false)

	assert(bipartite([][]int{
		{0, 1, 0, 1, 0, 0},
		{1, 0, 0, 0, 1, 1},
		{0, 0, 0, 1, 0, 0},
		{1, 0, 1, 0, 0, 0},
		{0, 1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0},
	}) == true)

	assert(bipartite([][]int{
		{0, 0},
		{0, 0},
	}) == true)

	assert(bipartite([][]int{
		{0, 0, 0, 1, 1, 1},
		{0, 0, 0, 1, 1, 1},
		{0, 0, 0, 1, 1, 1},
		{1, 1, 1, 0, 0, 0},
		{1, 1, 1, 0, 0, 0},
		{1, 1, 1, 0, 0, 0},
	}) == true)

	assert(bipartite([][]int{
		{0, 0, 0, 1, 0, 1, 0, 1},
		{0, 0, 0, 1, 1, 1, 1, 1},
		{0, 0, 0, 1, 1, 1, 0, 0},
		{1, 1, 1, 0, 0, 0, 0, 0},
		{0, 1, 1, 0, 0, 0, 0, 0},
		{1, 1, 1, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0},
		{1, 1, 0, 0, 0, 0, 0, 0},
	}) == true)

	assert(bipartite([][]int{
		{0, 1, 0, 1},
		{1, 0, 1, 0},
		{0, 1, 0, 1},
		{1, 0, 1, 0},
	}) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func colorable2(a [][]int, s int, c []int) bool {
	c[s] = 1
	for q := []int{s}; len(q) > 0; q = q[1:] {
		u := q[0]
		if a[u][u] == 1 {
			return false
		}

		for v := 0; v < len(a); v++ {
			if a[u][v] == 0 {
				continue
			}
			if c[v] == -1 {
				c[v] = 1 - c[u]
				q = append(q, v)
			} else if c[v] == c[u] {
				return false
			}
		}
	}
	return true
}

/*

https://www.geeksforgeeks.org/bipartite-graph/
If the graph is fully connected (all vertices can go to other vertices), running one iteration of two colorable on any vertex is enough.
For disconnected graphs, all of the vertices need to be checked if they are two colorable.

*/

func bipartite(a [][]int) bool {
	c := make([]int, len(a))
	for i := range c {
		c[i] = -1
	}

	for i := range c {
		if c[i] == -1 {
			if !colorable2(a, i, c) {
				return false
			}
		}
	}
	return true
}
