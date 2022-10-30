/*

A Walsh matrix is a special kind of square matrix with applications in quantum computing (and probably elsewhere, but I only care about quantum computing).

Properties of Walsh matrices

The dimensions are the same power of 2. Therefore, we can refer to these matrices by two's exponent here, calling themW(0), W(1), W(2)...

W(0) is defined as [[1]].

For n>0, W(n) looks like:

[[W(n-1)  W(n-1)]
 [W(n-1) -W(n-1)]]

So W(1) is:

[[1  1]
 [1 -1]]

And W(2) is:

[[1  1  1  1]
 [1 -1  1 -1]
 [1  1 -1 -1]
 [1 -1 -1  1]]

The pattern continues...
Your task

Write a program or function that takes as input an integer n and prints/returns W(n) in any convenient format. This can be an array of arrays, a flattened array of booleans, a .svg image, you name it, as long as it's correct.

Standard loopholes are forbidden.
A couple things:

For W(0), the 1 need not be wrapped even once. It can be a mere integer.

You are allowed to 1-index results—W(1) would then be [[1]].
Test cases

0 -> [[1]]
1 -> [[1  1]
      [1 -1]]
2 -> [[1  1  1  1]
      [1 -1  1 -1]
      [1  1 -1 -1]
      [1 -1 -1  1]]
3 -> [[1  1  1  1  1  1  1  1]
      [1 -1  1 -1  1 -1  1 -1]
      [1  1 -1 -1  1  1 -1 -1]
      [1 -1 -1  1  1 -1 -1  1]
      [1  1  1  1 -1 -1 -1 -1]
      [1 -1  1 -1 -1  1 -1  1]
      [1  1 -1 -1 -1 -1  1  1]
      [1 -1 -1  1 -1  1  1 -1]]

8 -> Pastebin

This is code-golf, so the shortest solution in each language wins! Happy golfing!

*/

package main

import "fmt"

func main() {
	for i := 0; i <= 5; i++ {
		dump(i, walsh(i))
	}
}

func dump(n int, m [][]int) {
	fmt.Println(n)
	for i := range m {
		for j := range m[i] {
			fmt.Printf("% d ", m[i][j])
		}
		fmt.Println()
	}
	fmt.Println()
}

func walsh(n int) [][]int {
	if n < 0 {
		return nil
	}
	if n == 0 {
		return [][]int{{1}}
	}

	w := walsh(n - 1)
	l := 1 << n
	m := make([][]int, l)
	t := make([]int, l*l)
	for i := range m {
		m[i] = t[i*l : (i+1)*l]
	}

	for i := range w {
		for j := range w[i] {
			m[i][j] = w[i][j]
			m[i][j+l/2] = w[i][j]
			m[i+l/2][j] = w[i][j]
			m[i+l/2][j+l/2] = -w[i][j]
		}
	}

	return m
}
