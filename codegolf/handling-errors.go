/*

What's great about golfing is not having to deal with errors. Except this time you won't get off so lightly! I need to do some arithmetic with certain limitations, and I wan't to know what goes wrong if anything.

Challenge
Given a list of signed integer values [n1..n11], give the following result or the first error that occurred.

(((((((((n1+n2)-n3)^n4)/n5)*n6)+n7)-n8)^n9)/n10)*n11
The same in reverse polish notation:

n1 n2 + n3 - n4 ^ n5 / n6 * n7 + n8 - n9 ^ n10 / n11 *
The operators have the following limitations:

0^0 → error 0^0 is undefined
0^a when a<0 → error Negative exponent
a/0 → error Division by zero
a/b when mod a b != 0 → error Uneven division
for any operator: result < 0 → error Integer underflow
for any operator: result > 99 → error Integer overflow
for any operator: either input value or result == 13 → error 13 is bad luck!
Errors occur left to right, so 13/0 = error 13 is bad luck!.

Scoring
The shortest code in bytes wins. To encourage readability string literals used for errors won't count towards the score.

The output format isn't strict but all seven errors plus a correct value must be distinguishable. Your program/function must retain control flow until the end, so e.g. any exceptions must be caught.

Standard loopholes are disallowed.

Examples
[6,7,14,2,0,1,2,3,4,0,6]   → error `13 is bad luck!`
[6,6,14,2,0,1,2,3,4,0,6]   → error `Integer underflow`
[6,6,12,0,0,1,2,3,4,0,6]   → error `0^0 is undefined`
[6,6,12,2,0,1,2,3,4,0,6]   → error `Division by zero`
[6,6,10,6,12,1,2,3,4,0,6]  → error `Uneven division`
[6,6,10,6,8,17,2,13,4,0,6] → error `Integer overflow`
[6,6,10,6,8,7,99,13,4,0,6] → error `Integer overflow`
[6,6,10,6,8,7,9,99,4,0,6]  → error `Integer underflow`
[6,6,10,6,8,7,9,55,-2,0,0] → error `Negative exponent`
[6,6,10,6,8,7,9,56,2,0,8]  → error `Division by zero`
[6,6,10,6,8,7,9,56,2,9,12] → error `Integer overflow`
[6,6,10,6,8,7,9,56,2,9,11] → 99

*/

package main

func main() {
	assert(eval([11]int{6, 7, 14, 2, 0, 1, 2, 3, 4, 0, 6}) == "13 is bad luck!")
	assert(eval([11]int{6, 6, 14, 2, 0, 1, 2, 3, 4, 0, 6}) == "Integer underflow")
	assert(eval([11]int{6, 6, 12, 0, 0, 1, 2, 3, 4, 0, 6}) == "0^0 is undefined")
	assert(eval([11]int{6, 6, 12, 2, 0, 1, 2, 3, 4, 0, 6}) == "Division by zero")
	assert(eval([11]int{6, 6, 10, 6, 12, 1, 2, 3, 4, 0, 6}) == "Uneven division")
	assert(eval([11]int{6, 6, 10, 6, 8, 17, 2, 13, 4, 0, 6}) == "Integer overflow")
	assert(eval([11]int{6, 6, 10, 6, 8, 7, 99, 13, 4, 0, 6}) == "Integer overflow")
	assert(eval([11]int{6, 6, 10, 6, 8, 7, 9, 99, 4, 0, 6}) == "Integer underflow")
	assert(eval([11]int{6, 6, 10, 6, 8, 7, 9, 55, -2, 0, 0}) == "Negative exponent")
	assert(eval([11]int{6, 6, 10, 6, 8, 7, 9, 56, 2, 0, 8}) == "Division by zero")
	assert(eval([11]int{6, 6, 10, 6, 8, 7, 9, 56, 2, 9, 12}) == "Integer overflow")
	assert(eval([11]int{6, 6, 10, 6, 8, 7, 9, 56, 2, 9, 11}) == 99)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eval(a [11]int) any {
	r := 0
	for i := range a {
		switch i {
		case 0:
			r = a[i]
		case 1, 6:
			r += a[i]
		case 2, 7:
			r -= a[i]
		case 3, 8:
			switch {
			case r == 0 && a[i] == 0:
				return "0^0 is undefined"
			case a[i] < 0:
				return "Negative exponent"
			}
			r = ipow(r, a[i])
		case 4, 9:
			switch {
			case a[i] == 0:
				return "Division by zero"
			case r%a[i] != 0:
				return "Uneven division"
			}
			r /= a[i]
		case 5, 10:
			r *= a[i]
		}

		switch {
		case r < 0:
			return "Integer underflow"
		case r > 99:
			return "Integer overflow"
		case r == 13:
			return "13 is bad luck!"
		}
	}
	return r
}

func ipow(x, p int) int {
	r := 1
	for i := 0; i < p; i++ {
		r *= x
	}
	return r
}
