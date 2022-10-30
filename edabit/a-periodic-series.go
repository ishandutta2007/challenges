/*

This challenge involves a series that can start with any string of digits.
The next term in the series is found by adding the digits of the previous term,
appending that sum to the previous term, and then truncating the leftmost digits so that the number of digits in the terms is always the same.

Let's start with "1234". The sum of the digits is 10. Appending gives us "123410", then truncating the left two digits results in "3410".
The next three terms are "4108", "0813", "1312". The series becomes periodic when a term that previously appeared occurs again.

Example:

"124", "247", "713", "311", "115", "157", "713", "311" ...

This series becomes periodic at a length of 6 before "713" reappears.

Create a function whose argument is a digit string (the first term) and returns the length of the series when it first becomes periodic.
Examples

periodic("1") ➞ 1

periodic("3061") ➞ 7

periodic("02468") ➞ 178

periodic("314159265") ➞ 12210

*/

package main

import "fmt"

func main() {
	assert(periodic("124") == 6)
	assert(periodic("1") == 1)
	assert(periodic("3061") == 7)
	assert(periodic("02468") == 178)
	assert(periodic("314159265") == 12210)
	assert(periodic("2") == 1)
	assert(periodic("22") == 13)
	assert(periodic("157") == 4)
	assert(periodic("1234567") == 943)
	assert(periodic("1818") == 1)
	assert(periodic("0000001") == 778)
}

func periodic(s string) int {
	m := make(map[string]struct{})
	l := len(s)
	p := 1
	for {
		m[s] = struct{}{}
		s += sum(s)
		s = s[len(s)-l:]
		if _, f := m[s]; f {
			break
		}
		p++
	}
	return p
}

func sum(s string) string {
	r := 0
	for i := 0; i < len(s); i++ {
		r += int(s[i] - '0')
	}
	return fmt.Sprint(r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
