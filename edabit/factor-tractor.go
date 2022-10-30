/*

Write a program to find all the prime factors of a given number.
The program must return an array containing all the prime factors, sorted in ascending order.
Remember that 1 is neither prime nor composite and should not be included in your output array.
Examples

primeFactorize(25) ➞ [5, 5]

primeFactorize(19) ➞ [19]

primeFactorize(77) ➞ [7, 11]

Notes

    Output array must be sorted in ascending order
    The only positive integer which is neither prime nor composite is 1. Return an empty array if 1 is the input.

*/

package main

func main() {
	eq(factorize(25), []uint{5, 5})
	eq(factorize(19), []uint{19})
	eq(factorize(77), []uint{7, 11})
	eq(factorize(32), []uint{2, 2, 2, 2, 2})
	eq(factorize(17), []uint{17})
	eq(factorize(35), []uint{5, 7})
	eq(factorize(2), []uint{2})
	ne(factorize(2), []uint{1, 2})
	ne(factorize(1), []uint{1})
	ne(factorize(35), []uint{7, 5})
	eq(factorize(2591), []uint{2591})
	eq(factorize(2532), []uint{2, 2, 3, 211})
}

func factorize(n uint) []uint {
	var r []uint
loop:
	for n > 1 {
		for i := uint(2); i <= n; i++ {
			if n%i == 0 {
				n /= i
				r = append(r, i)
				continue loop
			}
		}
	}
	return r
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eq(a, b []uint) {
	assert(len(a) == len(b))
	for i := range a {
		assert(a[i] == b[i])
	}
}

func ne(a, b []uint) {
	if len(a) != len(b) {
		return
	}
	for i := range a {
		if a[i] != b[i] {
			return
		}
	}
	assert(false)
}
