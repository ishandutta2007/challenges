/*

Create a recursive function that determines whether a word is a palindrome or not.

Examples

is_palindrome("madam") ➞ true

is_palindrome("adieu") ➞ false

is_palindrome("rotor") ➞ true

Notes

    All inputs are in lowercase.
    You are expected to solve this challenge via recursion.
    You can check on the Resources tab for more details about recursion.

*/

package main

func main() {
	itab := []string{
		"rascal",
		"racecar",
		"madam",
		"adieu",
		"radar",
		"rotor",
		"abacus",
		"rotator",
		"scholars",
	}
	otab := []bool{
		false,
		true,
		true,
		false,
		true,
		true,
		false,
		true,
		false,
	}

	for i := range itab {
		assert(palindrome(itab[i]) == otab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func verify(s string, i, j int) bool {
	if i >= j {
		return true
	}
	if s[i] != s[j-1] {
		return false
	}
	return verify(s, i+1, j-1)
}

func palindrome(s string) bool {
	return verify(s, 0, len(s))
}
