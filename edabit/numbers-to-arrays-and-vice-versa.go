/*

Write two functions:

    toArray(), which converts a number to an array of its digits.
    toNumber(), which converts an array of digits back to its number.

Examples

toArray(235) ➞ [2, 3, 5]

toArray(0) ➞ [0]

toNumber([2, 3, 5]) ➞ 235

toNumber([0]) ➞ 0

Notes

All test cases will be weakly positive numbers: >= 0

*/

package main

func main() {
	tab := []struct {
		a []uint
		n uint
	}{
		{[]uint{2, 3, 5}, 235},
		{[]uint{1, 9}, 19},
		{[]uint{0}, 0},
	}

	for _, p := range tab {
		eqa(toarray(p.n), p.a)
		eqi(tonumber(p.a), p.n)
	}
}

func toarray(n uint) []uint {
	var p []uint
	for {
		p = append(p, n%10)
		if n /= 10; n == 0 {
			break
		}
	}
	for i, l := 0, len(p); i < l/2; i++ {
		p[i], p[l-i-1] = p[l-i-1], p[i]
	}
	return p
}

func tonumber(p []uint) uint {
	n := uint(0)
	for i := range p {
		n *= 10
		n += p[i]
	}
	return n
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eqa(a, b []uint) {
	assert(len(a) == len(b))
	for i := range a {
		assert(a[i] == b[i])
	}
}

func eqi(a, b uint) {
	assert(a == b)
}
