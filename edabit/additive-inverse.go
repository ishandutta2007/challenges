/*

A number added with its additive inverse equals zero. Create a function that returns an array of additive inverses.
Examples

additiveInverse([5, -7, 8, 3]) ➞ [-5, 7, -8, -3]

additiveInverse([1, 1, 1, 1, 1]) ➞ [-1, -1, -1, -1, -1]

additiveInverse([-5, -25, 35]) ➞ [5, 25, -35]

Notes

    Don't forget to return the result.
    If you get stuck on a challenge, find help in the Resources tab.
    If you're really stuck, unlock solutions in the Solutions tab.

*/

package main

func main() {
	eq(inv([]int{5, -7, 8, 3}), []int{-5, 7, -8, -3})
	eq(inv([]int{1, 1, 1, 1, 1}), []int{-1, -1, -1, -1, -1})
	eq(inv([]int{-5, -25, 35}), []int{5, 25, -35})
}

func inv(a []int) []int {
	p := make([]int, len(a))
	for i := range p {
		p[i] = -a[i]
	}
	return p
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eq(a, b []int) {
	assert(len(a) == len(b))
	for i := range a {
		assert(a[i] == b[i])
	}
}
