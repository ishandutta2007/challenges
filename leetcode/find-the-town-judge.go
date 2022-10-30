/*

In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.

You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

Note:

1 <= N <= 1000
trust.length <= 10000
trust[i] are all different
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N

*/

package main

import "fmt"

func main() {
	fmt.Println(findjudge(2, [][2]int{{1, 2}}))
	fmt.Println(findjudge(3, [][2]int{{1, 3}, {2, 3}}))
	fmt.Println(findjudge(3, [][2]int{{1, 2}, {2, 3}, {3, 1}}))
	fmt.Println(findjudge(3, [][2]int{{1, 2}, {2, 3}}))
	fmt.Println(findjudge(4, [][2]int{{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}}))
}

func findjudge(n int, t [][2]int) int {
	if n <= 0 {
		return -1
	}

	b := make([]int, (n+1)*n)
	g := make([][]int, n+1)
	for i := range g {
		g[i] = b[i*n:]
	}

	i := 0
	m := 0
	for _, p := range t {
		a, b := p[0]-1, p[1]-1
		if a < 0 || a >= n || b < 0 || b >= n {
			return -1
		}

		if g[a][b] == 0 {
			g[a][b] = 1
			g[n][b]++
			if m < g[n][b] {
				m = g[n][b]
				i = b + 1
			}
		}
	}

	if m+1 >= n {
		return i
	}
	return -1
}
