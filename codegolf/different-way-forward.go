/*

Given a list of integers produce a Forward Difference at a specified order/depth.

For the list of integers:

(10, 18, -12, 4, 8, -3, -5, 67, 9, 14)

The Forward Differences at the various orders/depths are:

0   10,   18,  -12,    4,    8,   -3,   -5,  67,  9,  14
1      8,  -30,   16,    4,  -11,   -2,   72, -58,  5
2       -38,   46,  -12,  -15,    9,   74, -130, 63
3           84,  -58,   -3,   24,   65, -204, 193
4            -142,   55,   27,   41, -269, 397
5               197,  -28,   14, -310, 666
6                 -225,   42, -324, 976
7                    267, -366, 1300
8                      -633, 1666
9                         2299

So with the input of

4, (10, 18, -12, 4, 8, -3, -5, 67, 9, 14)

You would return the list

(-142,   55,   27,   41, -269, 397)

Input

The input can be via STDIN or function parameters.

An integer specifying the depth to return. This will be 0 to the length of the list minus 1

A list of integers to calculate the forward difference for
Output

The output can be via STDOUT or returned by the function.

The forward differences for the specified depth as a list of integers
Rules

Built in and 3rd Party functions that do this directly are not allowed.

Standard loophole restrictions apply.

Shortest code wins

*/

package main

import "reflect"

func main() {
	test([]int{10, 18, -12, 4, 8, -3, -5, 67, 9, 14}, 4, []int{-142, 55, 27, 41, -269, 397})
	test([]int{10, 18, -12, 4, 8, -3, -5, 67, 9, 14}, 9, []int{2299})
}

func test(a []int, n int, r []int) {
	p := forward(a, n)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func forward(a []int, n int) []int {
	for i := 0; i < n; i++ {
		m := len(a)
		if m == 0 {
			break
		}

		for j := 0; j < m-1; j++ {
			a[j] = a[j+1] - a[j]
		}
		a = a[:m-1]
	}
	return a
}
