/*

An array a is called beautiful if for every pair of numbers ai, aj, (i ≠ j), there exists an ak such that ak = ai * aj. Note that k can be equal to i or j too.

Find out whether the given array a is beautiful or not!

*/
package main

import (
	"fmt"
)

func main() {
	a := []int{0, 1}
	fmt.Println(beautifulSlow(a), beautiful(a))

	a = []int{1, 2}
	fmt.Println(beautifulSlow(a), beautiful(a))

	a = []int{5, 6}
	fmt.Println(beautifulSlow(a), beautiful(a))

	a = []int{-1, -1}
	fmt.Println(beautifulSlow(a), beautiful(a))

	a = []int{1, 1, 1, 0}
	fmt.Println(beautifulSlow(a), beautiful(a))

	a = []int{1, -1, 1, 0, 5}
	fmt.Println(beautifulSlow(a), beautiful(a))
}

func beautifulSlow(a []int) string {
	m := make(map[int]bool)
	for i := range a {
		m[a[i]] = true
	}
	for i := 0; i < len(a); i++ {
		for j := i + 1; j < len(a); j++ {
			k := a[i] * a[j]
			if !m[k] {
				return "no"
			}
		}
	}
	return "yes"
}

// if each pair of a and b has to be in the array
// means we can only have at most 1 number outside of [-1, 0, 1]
// since if ab=n, and if there existed another value m > 1, we
// would need an infinite array to store them, because the new generated number will combine with other
// pairs to make larger numbers.
// this restrict the coefficients to be inside [-1, 1] and at most 1 number outside of that range
func beautiful(a []int) string {
	var z, o, n, d int
	for _, v := range a {
		switch {
		case v == 0:
			z++
		case v == 1:
			o++
		case v == -1:
			n++
		default:
			d++
		}
	}
	if d > 1 {
		return "no"
	}
	if n > 0 && d > 0 {
		return "no"
	}
	if n > 1 && o == 0 {
		return "no"
	}
	return "yes"
}
