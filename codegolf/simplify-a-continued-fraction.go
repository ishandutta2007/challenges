/*

Continued fractions are expressions that describe fractions iteratively. They can be represented graphically:

a0 + 1/(a1 + 1/(a2 + 1/(a3 + ...)))
a0+1a1+1a2+1⋱+1an

Or they can be represented as a list of values: [a0;a1,a2,…,an]

The challenge:
take a base number: a0 and a list of denominator values: [a1,a2,…,an] and simplify the continued fraction to a simplified rational fraction: return or print numerator and denominator separately.

Examples:
1–√9: [4;2,1,3,1,2]: 170/39
e: [1;0,1,1,2,1,1]: 19/7
π: [3;7,15,1,292,1]: 104348/33215
ϕ: [1;1,1,1,1,1]: 13/8

Example implementation: (python)

def foo(base, sequence):
    numerator = 1
    denominator = sequence[-1]
    for d in sequence[-2::-1]:
        temp = denominator
        denominator = d * denominator + numerator
        numerator = temp
    return numerator + base * denominator, denominator

Winning:
shortest code in bytes: --no builtins that do the entire problem allowed--

*/

package main

import "fmt"

func main() {
	test(4, []int{2, 1, 3, 1, 2}, 170, 39)
	test(1, []int{0, 1, 1, 2, 1, 1}, 19, 7)
	test(3, []int{7, 15, 1, 292, 1}, 104348, 33215)
	test(1, []int{1, 1, 1, 1, 1}, 13, 8)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(b int, s []int, rn, rd int) {
	n, d := simplify(b, s)
	fmt.Println(n, d)
	assert(n == rn)
	assert(d == rd)
}

func simplify(b int, s []int) (int, int) {
	l := len(s)
	if l == 0 {
		return 0, 0
	}

	n := 1
	d := s[l-1]
	for i := l - 2; i >= 0; i-- {
		n, d = d, s[i]*d+n
	}
	return n + b*d, d
}
