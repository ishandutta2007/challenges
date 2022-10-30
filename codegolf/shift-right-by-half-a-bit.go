/*

The challenge is to implement a program or function (subsequently referred to as "program") that takes a nonnegative integer n as input and returns n/sqrt(2) (the input divided by the square root of two) as output, rounded to a nonnegative integer.

You may take your input and output in any reasonable format; for example stdin/stdout, files, or arguments/return values would all be acceptable.

You are required to use, at minimum, the largest fixed-size integer type offered by your language, and if an unsigned variant of this is available, you must use it.
If your language has no built-in integer type (e.g. JavaScript) you are allowed to use its default numerical type (e.g. floating point); for languages with no concept of a number (e.g. regex), input and output can be e.g. the length of a string.

It is not required to reject negative integers; a submission that returns correct answers for negative inputs is allowed, but not required. Undefined behavior with negative inputs is allowed.

You are allowed and encouraged to use arbitrary-precision integer types if you so desire, but the type must either be a built-in, part of a standard library, or implemented from scratch in your program.
As such, there are two categories of competition in this challenge:

Precision limited by built-in types (fixed-size integer, floating point, etc.)
Arbitrary precision (recursion and memory allocation, if used, can be assumed to be unlimited, where appropriate to the language in question)
Despite what the title might imply, you may use any rounding algorithm you want (floor, ceiling, nearest half up, nearest half even, arbitrary, or even random),
as long as the difference between the integer returned value and the theoretical exact (irrational) value is always less than 1 for all inputs that fit in your chosen integer type (but exactly 0 for an input of 0).
All inputs up to the maximum representable value must return a correct output.

In a way, the job of this program is to calculate the irrational number sqrt(2) to the requested precision, presenting it in the form of an integer. This is why solutions using arbitrary-precision types are encouraged, but not required.

This is a code-golf challenge. Standard loopholes are denied. The program with the least number of bytes wins.
That said, this challenge is not only about which answer wins overall; it's also about seeing how concisely the challenge can be solved in each language, seeing how each language "prefers" to handle rounding, and how hard it is to solve in esoteric languages.
And for those submissions that choose to use arbitrary precision, it's about seeing how concisely this can be done in the language.

Test cases
Within the Precision-limited category, only the cases that are in range of the language's capability are required to pass.

If your solution is too slow to demonstrably pass the larger inputs (or runs out of memory/stack), it becomes all the more important to explain it sufficiently well, so that it can be understood that it would pass.

Input → Floor or Ceiling
0 → 0 (this is the only input that can only result in one valid output)
1 → 0 or 1
2 → 1 or 2
3 → 2 or 3
4 → 2 or 3
5 → 3 or 4
10 → 7 or 8
32 → 22 or 23
500 → 353 or 354
1000 → 707 or 708
1000000 → 707106 or 707107
186444716 → 131836322 or 131836323
1000000000 → 707106781 or 707106782
2147483647 → 1518500249 or 1518500250
3037000499 → 2147483647 or 2147483648
4294967295 → 3037000499 or 3037000500
4503599627370496 → 3184525836262886 or 3184525836262887
9223372036854775807 → 6521908912666391105 or 6521908912666391106
18446744073709551615 → 13043817825332782211 or 13043817825332782212
10000000000000000000000000000000000000 → 7071067811865475244008443621048490392 or 7071067811865475244008443621048490393
956287480911872131784896176254337633353980911149964074434383 → 676197362516585909969655173274459790030028262421622111830069 or 676197362516585909969655173274459790030028262421622111830070

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	test("0", "0")
	test("1", "0")
	test("2", "1")
	test("3", "2")
	test("4", "2")
	test("5", "3")
	test("10", "7")
	test("32", "22")
	test("500", "353")
	test("1000", "707")
	test("1000000", "707106")
	test("186444716", "131836322")
	test("1000000000", "707106781")
	test("2147483647", "1518500249")
	test("3037000499", "2147483647")
	test("4294967295", "3037000499")
	test("4503599627370496", "3184525836262886")
	test("9223372036854775807", "6521908912666391105")
	test("18446744073709551615", "13043817825332782211")
	test("10000000000000000000000000000000000000", "7071067811865475244008443621048490392")
	test("956287480911872131784896176254337633353980911149964074434383", "676197362516585909969655173274459790030028262421622111830069")
}

func test(s, r string) {
	n := new(big.Int)
	n.SetString(s, 0)
	p := shb(n)
	fmt.Println(p)
	assert(p.String() == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func shb(n *big.Int) *big.Int {
	x := new(big.Float)
	x.SetInt(n)

	l := len(n.String())
	y := big.NewFloat(2)
	y.SetPrec(uint(l) * 10)
	y.Sqrt(y)

	z := new(big.Float)
	z.Quo(x, y)

	i, _ := z.Int(nil)
	return i
}
