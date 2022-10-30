/*

The random Fibonacci sequence is defined as follows:

f[n]={ f[n-1] + f[n-2] with probability 1/2
       f[n-1] - f[n-2] with probability 1/2
       f[1] = f[2] = 1

i.e. whether the next term is the sum or difference of the previous two is chosen at random, independently of previous terms. Your task is to implement this sequence.

Each random realization of the sequence must use consistent values. For example, if f3=2, f4 must then be either 2+1=3 or 2−1=1. This can be thought of as the sequence "remembering" previous values.
This means that this example program is invalid, as previous values in the sequence are not maintained by later values. Furthermore, you should explain how your program meets the 1/2 probability requirement.

As is standard for sequence challenges, you can perform one of three tasks:

Take a positive integer n as input and output fn
Take a positive integer n as input and output f1,f2,...,fn
Output the sequence indefinitely with no end
Again, as is standard, you may use either 0 or 1 indexing, but the two initial values f1=f2=1 must be used.

This is code-golf, so the shortest code, in bytes, wins.

Examples
n -> possible values of f_n | probabilities of values
1 -> 1                      | 1
2 -> 1                      | 1
3 -> 2, 0                   | 1/2, 1/2
4 -> 3, 1, -1               | 1/4, 1/2, 1/4
5 -> 5, 3, 1, -1            | 1/8, 1/8, 3/8, 3/8
6 -> 8, 4, 2, 0, -2         | 1/16, 1/8, 1/4, 5/16, 1/4

*/

package main

import (
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	test(1, []int{1})
	test(2, []int{1})
	test(3, []int{2, 0})
	test(4, []int{3, 1, -1})
	test(5, []int{5, 3, 1, -1})
	test(6, []int{8, 4, 2, 0, -2})
}

func test(n int, r []int) {
	m := make(map[int]bool)
	for _, v := range r {
		m[v] = true
	}
	for i := 0; i < 1e6; i++ {
		v := f(n)
		if !m[v] {
			panic(v)
		}
	}
}

func f(n int) int {
	if n <= 0 {
		return 0
	}

	m := map[int]int{
		1: 1,
		2: 1,
	}
	for i := 3; i <= n; i++ {
		if rand.Intn(2) == 0 {
			m[i] = m[i-1] + m[i-2]
		} else {
			m[i] = m[i-1] - m[i-2]
		}
	}
	return m[n]
}
