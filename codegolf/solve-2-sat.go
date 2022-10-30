/*

The general SAT (boolean satisfiability) problem is NP-complete. But 2-SAT, where each clause has only 2 variables, is in P. Write a solver for 2-SAT.

Input:

A 2-SAT instance, encoded in CNF as follows. The first line contains V, the number of boolean variables and N, the number of clauses.
Then N lines follow, each with 2 nonzero integers representing the literals of a clause. Positive integers represent the given boolean variable and negative integers represent the variable's negation.

Example 1
input

4 5
1 2
2 3
3 4
-1 -3
-2 -4

which encodes the formula (x1 or x2) and (x2 or x3) and (x3 or x4) and (not x1 or not x3) and (not x2 or not x4).

The only setting of the 4 variables that makes the whole formula true is x1=false, x2=true, x3=true, x4=false, so your program should output the single line
output

0 1 1 0

representing the truth values of the V variables (in order from x1 to xV). If there are multiple solutions, you may output any nonempty subset of them, one per line. If there is no solution, you must output UNSOLVABLE.
Example 2
input

2 4
1 2
-1 2
-2 1
-1 -2

output

UNSOLVABLE

Example 3
input

2 4
1 2
-1 2
2 -1
-1 -2

output

0 1

Example 4
input

8 12
1 4
-2 5
3 7
2 -5
-8 -2
3 -1
4 -3
5 -4
-3 -7
6 7
1 7
-7 -1

output

1 1 1 1 1 1 0 0
0 1 0 1 1 0 1 0
0 1 0 1 1 1 1 0

(or any nonempty subset of those 3 lines)

Your program must handle all N,V < 100 in a reasonable time. Try this example to make sure your program can handle a big instance. Smallest program wins.

*/

package main

import "fmt"

func main() {
	test([][2]int{
		{1, 2},
		{2, 3},
		{3, 4},
		{-1, -3},
		{-2, -4},
	}, true)

	test([][2]int{
		{1, 2},
		{-1, 2},
		{-2, 1},
		{-1, -2},
	}, false)

	test([][2]int{
		{1, 2},
		{-1, 2},
		{-1, -2},
	}, true)

	test([][2]int{
		{1, 4},
		{-2, 5},
		{3, 7},
		{2, -5},
		{-8, -2},
		{3, -1},
		{4, -3},
		{5, -4},
		{-3, -7},
		{6, 7},
		{1, 7},
		{-7, -1},
	}, true)

	test([][2]int{
		{1, 2},
		{-2, 3},
		{-1, -2},
		{3, 4},
		{-3, 5},
		{-4, -5},
		{-3, 4},
	}, true)

	test([][2]int{
		{1, 3},
		{1, -4},
		{2, -4},
		{2, -5},
		{3, -5},
		{1, -6},
		{2, -6},
		{3, -6},
		{4, 6},
		{5, 7},
		{6, 7},
	}, true)

	test([][2]int{
		{1, -2},
		{-1, 2},
		{-1, -2},
		{1, -3},
	}, true)
}

func test(cl [][2]int, b bool) {
	var z SAT2
	z.Load(cl)

	p := z.Solve()
	fmt.Println(p)

	if b {
		assert(len(p) > 0)
		assert(z.Validate(p))
	} else {
		assert(len(p) == 0)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type SAT2 struct {
	cl    [][2]int
	g, gt [][]int
	v, vt []bool
	order []int
	comp  []int
	count int
}

func (z *SAT2) Load(clauses [][2]int) error {
	n := 0
	for _, c := range clauses {
		n = max(n, max(abs(c[0]), abs(c[1])))
		if c[0] == 0 || c[1] == 0 {
			return fmt.Errorf("variables needs to start at 1 index")
		}
	}
	z.g = make([][]int, 2*(n+1))
	z.gt = make([][]int, 2*(n+1))
	z.v = make([]bool, 2*(n+1))
	z.vt = make([]bool, 2*(n+1))
	z.comp = make([]int, 2*(n+1))
	z.cl = append(z.cl, clauses...)

	for _, c := range clauses {
		a, b := abs(c[0]), abs(c[1])
		na, nb := n+a, n+b
		if c[0] < 0 {
			a, na = na, a
		}
		if c[1] < 0 {
			b, nb = nb, b
		}

		z.g[na] = append(z.g[na], b)
		z.g[nb] = append(z.g[nb], a)

		z.gt[b] = append(z.gt[b], na)
		z.gt[a] = append(z.gt[a], nb)
	}
	return nil
}

func (z *SAT2) Validate(vals []int) bool {
	n := len(vals)
	for _, c := range z.cl {
		i := abs(c[0]) - 1
		j := abs(c[1]) - 1
		if i < 0 || i >= n || j < 0 || j >= n {
			return false
		}

		a := vals[i] != 0
		b := vals[j] != 0
		if c[0] < 0 {
			a = !a
		}
		if c[1] < 0 {
			b = !b
		}

		if !(a || b) {
			return false
		}
	}
	return true
}

// https://cp-algorithms.com/graph/2SAT.html
// https://www.geeksforgeeks.org/2-satisfiability-2-sat-problem/
func (z *SAT2) Solve() []int {
	for i := 1; i < len(z.v); i++ {
		if !z.v[i] {
			z.dfs1(i)
		}
	}

	z.count = 0
	for {
		n := len(z.order)
		if n == 0 {
			break
		}
		v := z.order[n-1]
		z.order = z.order[:n-1]

		if !z.vt[v] {
			z.dfs2(v)
			z.count++
		}
	}

	r := []int{}
	n := len(z.g)/2 - 1
	for i := 1; i <= n; i++ {
		if z.comp[i] == z.comp[i+n] {
			return nil
		}
		r = append(r, truth(z.comp[i] > z.comp[i+n]))
	}
	return r
}

func (z *SAT2) dfs1(u int) {
	if z.v[u] {
		return
	}

	z.v[u] = true
	for _, v := range z.g[u] {
		z.dfs1(v)
	}
	z.order = append(z.order, u)
}

func (z *SAT2) dfs2(u int) {
	if z.vt[u] {
		return
	}

	z.vt[u] = true
	for _, v := range z.gt[u] {
		z.dfs2(v)
	}
	z.comp[u] = z.count
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}
