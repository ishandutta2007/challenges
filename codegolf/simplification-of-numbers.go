/*

How, you can’t remember the 6 or 7-digit phone number that appeared on the TV screen for a second?! Using the special technique described below, you will turn into a walking phonebook!

Obviously, the number 402 is easier to remember than the number 110010010, and the number 337377 is easier to remember than the number 957472.
This means that the memorized number, on the one hand, should contain as few digits as possible, and on the other hand, it is desirable that the number contains as many repeating numbers as possible.

As a criterion for the difficulty of remembering, we take the sum of the number of digits in number and the number of different digits in number.
A memorized number can be written in another number system, perhaps then it will be easier to remember. For example, the number 65535 in the hexadecimal notation looks like FFFF.

Task
You need to write a program for selecting the base of the number system to minimize the complexity criterion.
The base of the number system must be selected in the range from 2 to 36, then the numbers 0-9 and the English letters A-Z can be used to represent the number.

Input
The input contains a decimal integer from 1 to 999999999.

Output
The output must contain the base of the number system (from 2 to 36), minimizing the criterion of memorization complexity, and the number in the selected number system, separated by one space.
If several bases give the same value for the criterion, then choose the smallest among them.

Notes
The letters must be uppercase(A-Z).
Test Cases
Input       Output
1              2 1
2              3 2
65535       16 FFFF
123          12 A3

*/

package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	test(1, 2, "1")
	test(2, 3, "2")
	test(65535, 16, "FFFF")
	test(123, 12, "A3")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int64, rb int, rv string) {
	b, v := simplify(n)
	fmt.Println(b, v)
	assert(b == rb)
	assert(v == rv)
}

func simplify(n int64) (b int, v string) {
	m := math.MaxInt
	for i := 2; i <= 36; i++ {
		s := strconv.FormatInt(n, i)
		c := score(s)
		if c < m {
			b, v, m = i, strings.ToUpper(s), c
		}
	}
	return
}

func score(s string) int {
	m := make(map[rune]int)
	for _, r := range s {
		m[r]++
	}
	return len(m) + len(s)
}
