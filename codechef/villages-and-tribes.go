/*

There are n villages in a line in an area. There are two kinds of tribes A and B that reside there.
A village can be either empty or occupied by one of the tribes.
An empty village is said to be controlled by a tribe of village A if it is surrounded by villages of tribes A from the left and from the right.
Same goes for the tribe B.

Find out the number of villages that are either occupied by or controlled by tribes A and B, respectively.

Input

The first line of the input contains an integer T denoting the number of test cases.

The first line of the input contains a string s denoting the configuration of the villages, each character of which can be 'A', 'B' or '.'.

Output

For each test case, output two space-separated integers denoting the number of villages either occupied by or controlled by tribe A and B, respectively.

Constraints
1 ≤ T ≤ 20
1 ≤ |s| ≤ 10^5

*/

package main

import "fmt"

func main() {
	test("A..A..B...B", 4, 5)
	test("..A..", 1, 0)
	test("A....A", 6, 0)
	test("..B..B..B..", 0, 7)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, ra, rb int) {
	a, b := villages(s)
	fmt.Println(a, b)
	assert(a == ra)
	assert(b == rb)
}

func villages(s string) (a, b int) {
	p, t := -1, -1
	for i, r := range s {
		switch r {
		case 'A':
			if t == 1 {
				a += (i - p - 1)
			}
			p, t, a = i, 1, a+1

		case 'B':
			if t == 2 {
				b += (i - p - 1)
			}
			p, t, b = i, 2, b+1
		}
	}
	return
}
