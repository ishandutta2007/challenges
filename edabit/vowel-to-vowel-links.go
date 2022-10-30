/*

Given a sentence as txt, return True if any two adjacent words have this property:
One word ends with a vowel, while the word immediately after begins with a vowel (a e i o u).

Examples

vowel_links("a very large appliance") ➞ True

vowel_links("go to edabit") ➞ True

vowel_links("an open fire") ➞ False

vowel_links("a sudden applause") ➞ False

Notes

You can expect sentences in only lowercase, with no punctuation.

*/

package main

import "strings"

func main() {
	assert(vlinks("a very large appliance") == true)
	assert(vlinks("go to edabit") == true)
	assert(vlinks("an open fire") == false)
	assert(vlinks("a sudden applause") == false)
	assert(vlinks("the large appliances") == true)
	assert(vlinks("creative environment") == true)
	assert(vlinks("beneficial luggage") == false)
	assert(vlinks("the eagle swooped down low") == true)
	assert(vlinks("this is not a drill") == false)
	assert(vlinks("please log on to edabit") == true)
	assert(vlinks("the quick brown fox was sad") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func vlinks(s string) bool {
	t := strings.Split(s, " ")
	if len(t) < 2 {
		return false
	}
	for i := 0; i < len(t)-1; i++ {
		p, q := t[i], t[i+1]
		if isvowel(p[len(p)-1]) && isvowel(q[0]) {
			return true
		}
	}
	return false
}

func isvowel(c byte) bool {
	return strings.IndexRune("aeiou", rune(c)) >= 0
}
