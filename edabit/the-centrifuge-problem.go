/*

A centrifuge, as you probably know, is a laboratory device used to separate fluids based on density.
The separation is achieved through centripetal force by spinning a collection of test tubes at high speeds.
This means, the configuration needs to be in balance.

Create a function that takes two numbers as arguments n and k and returns true if the configuration is balanced and false if it's not.
To check out the formula, look at the resources tab.

The Centrifuge Problem with 6 Holes, n=6

Here are the valid configurations for n = 6, k = 2, 3, 4 and 6.
Examples

cFuge(6, 4) ➞ true

cFuge(2, 1) ➞ false

cFuge(3, 3) ➞ true

Notes

    One test tube k = 1 is never in balance.
    One hole n = 1 is never in balance, even empty.

*/

package main

func main() {
	itab := [][2]int{
		{6, 4},
		{5, 1},
		{12, 7},
		{1, 1},
		{21, 18},
		{1, 0},
		{4, 2},
		{5, 3},
		{21, 13},
		{3, 3},
		{50, 1},
		{8, 6},
		{9, 5},
		{2, 1},
		{59, 59},
		{11, 4},
		{3, 3},
	}
	otab := []bool{
		true,
		false,
		true,
		false,
		true,
		false,
		true,
		false,
		false,
		true,
		false,
		true,
		false,
		false,
		true,
		false,
		true,
	}

	for i := range itab {
		assert(centrifuge(itab[i][0], itab[i][1]) == otab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://mattbaker.blog/2018/06/25/the-balanced-centrifuge-problem/
// You can balance k identical test tubes, 1 ≤ k ≤ n, in an n-hole centrifuge if and only if both k and n-k can be expressed as a sum of prime divisors of n.
func centrifuge(n, k int) bool {
	if n < 1 || k < 1 || k > n {
		return false
	}

	p := factor(n)
	if len(p) == 0 {
		return false
	}

	x := coins(p, k)
	y := coins(p, n-k)
	return x > 0 && y > 0
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

func factor(n int) (f []int) {
	if n < 2 {
		return []int{}
	}
	for i := int(2); i <= n; i++ {
		for n%i == 0 {
			n /= i
			f = append(f, i)
		}
	}
	return
}
