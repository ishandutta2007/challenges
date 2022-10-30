/*

Task
Given two positive integers a, b and a Unicode mathematical inequality symbol c, determine if a c b is true.

You many take the character or its Unicode codepoint for the input c. You may output your language's truthy/falsy values, or two distinct values for true and false respectively.

Standard code-golf rules apply. The shortest code in bytes wins.

List of symbols to support
Symbol  |  Hex   |  Dec   |  Name
--------+--------+--------+-------------
<       |  003C  |  60    |  Less than
=       |  003D  |  61    |  Equal to
>       |  003E  |  62    |  Greater than
≠       |  2260  |  8800  |  Not equal to
≤       |  2264  |  8804  |  Less than or equal to
≥       |  2265  |  8805  |  Greater than or equal to
≮       |  226E  |  8814  |  Not less than
≯       |  226F  |  8815  |  Not greater than
≰       |  2270  |  8816  |  Neither less than nor equal to
≱       |  2271  |  8817  |  Neither greater than nor equal to
The last four symbols may look broken in Chrome. They are four symbols <>≤≥ with slash overstrike, indicating negation.

Truthy test cases
1 < 2
1 = 1
2 > 1
1 ≠ 2
2 ≠ 1
1 ≤ 1
1 ≤ 2
2 ≥ 1
1 ≥ 1
2 ≮ 1
1 ≮ 1
1 ≯ 1
1 ≯ 2
2 ≰ 1
1 ≱ 2
Falsy test cases
1 < 1
2 < 1
1 = 2
2 = 1
1 > 1
1 > 2
1 ≠ 1
2 ≤ 1
1 ≥ 2
1 ≮ 2
2 ≯ 1
1 ≰ 1
1 ≰ 2
2 ≱ 1
1 ≱ 1

*/

package main

func main() {
	assert(compare(1, '<', 2) == true)
	assert(compare(1, '=', 1) == true)
	assert(compare(2, '>', 1) == true)
	assert(compare(1, '≠', 2) == true)
	assert(compare(2, '≠', 1) == true)
	assert(compare(1, '≤', 1) == true)
	assert(compare(1, '≤', 2) == true)
	assert(compare(2, '≥', 1) == true)
	assert(compare(1, '≥', 1) == true)
	assert(compare(2, '≮', 1) == true)
	assert(compare(1, '≮', 1) == true)
	assert(compare(1, '≯', 1) == true)
	assert(compare(1, '≯', 2) == true)
	assert(compare(2, '≰', 1) == true)
	assert(compare(1, '≱', 2) == true)

	assert(compare(1, '<', 1) == false)
	assert(compare(2, '<', 1) == false)
	assert(compare(1, '=', 2) == false)
	assert(compare(2, '=', 1) == false)
	assert(compare(1, '>', 1) == false)
	assert(compare(1, '>', 2) == false)
	assert(compare(1, '≠', 1) == false)
	assert(compare(2, '≤', 1) == false)
	assert(compare(1, '≥', 2) == false)
	assert(compare(1, '≮', 2) == false)
	assert(compare(2, '≯', 1) == false)
	assert(compare(1, '≰', 1) == false)
	assert(compare(1, '≰', 2) == false)
	assert(compare(2, '≱', 1) == false)
	assert(compare(1, '≱', 1) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func compare(x int, op rune, y int) bool {
	switch op {
	case '<':
		return x < y
	case '=':
		return x == y
	case '>':
		return x > y
	case '≠':
		return x != y
	case '≤':
		return x <= y
	case '≥':
		return x >= y
	case '≮':
		return !(x < y)
	case '≯':
		return !(x > y)
	case '≰':
		return !(x <= y)
	case '≱':
		return !(x >= y)
	}
	return false
}
