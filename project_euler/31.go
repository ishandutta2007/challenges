/*

In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:

    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).

It is possible to make £2 in the following way:

    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins?

*/

package main

import "fmt"

func main() {
	solve()
}

func solve() {
	fmt.Println(coins([]int{1, 2, 5, 10, 20, 50, 100, 200}, 200))
}

func coins(c []int, m int) int {
	n := len(c)
	l := make([][]int, m+1)
	t := make([]int, (m+1)*n)
	for i := 0; i < m+1; i++ {
		l[i] = t[i*n:]
	}

	for i := 0; i < n; i++ {
		l[0][i] = 1
	}
	for i := 1; i < m+1; i++ {
		for j := 0; j < n; j++ {
			x, y := 0, 0
			if i >= c[j] {
				x = l[i-c[j]][j]
			}
			if j >= 1 {
				y = l[i][j-1]
			}
			l[i][j] = x + y
		}
	}
	return l[m][n-1]
}
