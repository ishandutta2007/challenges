/*

The Farey sequence of order n is the set of all fractions with a denominator between 1 and n, reduced and returned in ascending order. Given n, return the Farey sequence as an array, with each fraction being represented by a string in the form "numerator/denominator".

Examples

farey(1) ➞ ["0/1", "1/1"]

farey(4) ➞ ["0/1", "1/4", "1/3", "1/2", "2/3", "3/4", "1/1"]

farey(5) ➞ ["0/1", "1/5", "1/4", "1/3", "2/5", "1/2", "3/5", "2/3", "3/4", "4/5", "1/1"]

Notes

The Farey sequence will always begin with "0/1" and end with "1/1".

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(farey(1), []string{"0/1", "1/1"})
	test(farey(2), []string{"0/1", "1/2", "1/1"})
	test(farey(3), []string{"0/1", "1/3", "1/2", "2/3", "1/1"})
	test(farey(4), []string{"0/1", "1/4", "1/3", "1/2", "2/3", "3/4", "1/1"})
	test(farey(5), []string{"0/1", "1/5", "1/4", "1/3", "2/5", "1/2", "3/5", "2/3", "3/4", "4/5", "1/1"})
	test(farey(6), []string{"0/1", "1/6", "1/5", "1/4", "1/3", "2/5", "1/2", "3/5", "2/3", "3/4", "4/5", "5/6", "1/1"})
	test(farey(7), []string{"0/1", "1/7", "1/6", "1/5", "1/4", "2/7", "1/3", "2/5", "3/7", "1/2", "4/7", "3/5", "2/3", "5/7", "3/4", "4/5", "5/6", "6/7", "1/1"})
	test(farey(8), []string{"0/1", "1/8", "1/7", "1/6", "1/5", "1/4", "2/7", "1/3", "3/8", "2/5", "3/7", "1/2", "4/7", "3/5", "5/8", "2/3", "5/7", "3/4", "4/5", "5/6", "6/7", "7/8", "1/1"})
	test(farey(9), []string{"0/1", "1/9", "1/8", "1/7", "1/6", "1/5", "2/9", "1/4", "2/7", "1/3", "3/8", "2/5", "3/7", "4/9", "1/2", "5/9", "4/7", "3/5", "5/8", "2/3", "5/7", "3/4", "7/9", "4/5", "5/6", "6/7", "7/8", "8/9", "1/1"})
	test(farey(10), []string{"0/1", "1/10", "1/9", "1/8", "1/7", "1/6", "1/5", "2/9", "1/4", "2/7", "3/10", "1/3", "3/8", "2/5", "3/7", "4/9", "1/2", "5/9", "4/7", "3/5", "5/8", "2/3", "7/10", "5/7", "3/4", "7/9", "4/5", "5/6", "6/7", "7/8", "8/9", "9/10", "1/1"})
	test(farey(11), []string{"0/1", "1/11", "1/10", "1/9", "1/8", "1/7", "1/6", "2/11", "1/5", "2/9", "1/4", "3/11", "2/7", "3/10", "1/3", "4/11", "3/8", "2/5", "3/7", "4/9", "5/11", "1/2", "6/11", "5/9", "4/7", "3/5", "5/8", "7/11", "2/3", "7/10", "5/7", "8/11", "3/4", "7/9", "4/5", "9/11", "5/6", "6/7", "7/8", "8/9", "9/10", "10/11", "1/1"})
	test(farey(12), []string{"0/1", "1/12", "1/11", "1/10", "1/9", "1/8", "1/7", "1/6", "2/11", "1/5", "2/9", "1/4", "3/11", "2/7", "3/10", "1/3", "4/11", "3/8", "2/5", "5/12", "3/7", "4/9", "5/11", "1/2", "6/11", "5/9", "4/7", "7/12", "3/5", "5/8", "7/11", "2/3", "7/10", "5/7", "8/11", "3/4", "7/9", "4/5", "9/11", "5/6", "6/7", "7/8", "8/9", "9/10", "10/11", "11/12", "1/1"})
	test(farey(13), []string{"0/1", "1/13", "1/12", "1/11", "1/10", "1/9", "1/8", "1/7", "2/13", "1/6", "2/11", "1/5", "2/9", "3/13", "1/4", "3/11", "2/7", "3/10", "4/13", "1/3", "4/11", "3/8", "5/13", "2/5", "5/12", "3/7", "4/9", "5/11", "6/13", "1/2", "7/13", "6/11", "5/9", "4/7", "7/12", "3/5", "8/13", "5/8", "7/11", "2/3", "9/13", "7/10", "5/7", "8/11", "3/4", "10/13", "7/9", "4/5", "9/11", "5/6", "11/13", "6/7", "7/8", "8/9", "9/10", "10/11", "11/12", "12/13", "1/1"})
}

func test(s, t []string) {
	assert(reflect.DeepEqual(s, t))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://en.wikipedia.org/wiki/Farey_sequence
func farey(n uint) []string {
	if n == 0 {
		return []string{}
	}

	p := []string{"0/1"}
	a, b, c, d := uint(0), uint(1), uint(1), n
	for c <= n {
		k := (n + b) / d
		a, b, c, d = c, d, k*c-a, k*d-b
		p = append(p, fmt.Sprintf("%d/%d", a, b))
	}
	return p
}
