/*

In many table-top games it is common to use different dice to simulate random events. A “d” or “D” is used to indicate a die with a specific number of faces, d4 indicating a four-sided die, for example.
If several dice of the same type are to be rolled, this is indicated by a leading number specifying the number of dice. Hence, 2d6 means the player should roll two six-sided dice and sum the result face values.

Task

Write a program to compute the most likely outcomes for the sum of two dice rolls. Assume each die has numbered faces starting at 1 and that each face has equal roll probability.
Input

The input consists of a single line with two integer numbers, N,M, specifying the number of faces of the two dice.
Constraints

4≤N,M≤20

Number of faces.
Output

A line with the most likely outcome for the sum; in case of several outcomes with the same probability, they must be listed from lowest to highest value in separate lines.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(6, 6, []int{7})
	test(6, 4, []int{5, 6, 7})
	test(12, 20, []int{13, 14, 15, 16, 17, 18, 19, 20, 21})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, m int, r []int) {
	p := likelist(n, m)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func likelist(n, m int) []int {
	r := []int{}
	p := make([]int, (n+1)*(m+1))
	c := 0
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			k := i + j
			if p[k]++; p[k] > c {
				c = k
				r = r[:0]
			}
			if p[k] == c {
				r = append(r, k)
			}
		}
	}
	return r
}
