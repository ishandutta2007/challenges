/*

A number/string is a palindrome if the digits/characters are the same when read both forward and backward.
Examples include "racecar" and 12321. Given a positive number n, check if n or the binary representation of n is palindromic. Return the following:

    "Decimal only." if only n is a palindrome.
    "Binary only." if only the binary representation of n is a palindrome.
    "Decimal and binary." if both are palindromes.
    "Neither!" if neither are palindromes.

Examples

palindromeType(1306031) ➞ "Decimal only."
// decimal = 1306031
// binary  = "100111110110110101111"

palindromeType(427787) ➞ "Binary only."
// decimal = 427787
// binary  = "1101000011100001011"

palindromeType(313) ➞ "Decimal and binary."
// decimal = 313
// binary  = 100111001

palindromeType(934) ➞ "Neither!"
// decimal = 934
// binary  = "1110100110"

Notes

Check the Resources tab for ways to convert to binary.

*/

package main

import (
	"fmt"
)

func main() {
	assert(palindrome(1934391) == "Decimal and binary.")
	assert(palindrome(9994521) == "Binary only.")
	assert(palindrome(5841485) == "Decimal and binary.")
	assert(palindrome(8337738) == "Neither!")
	assert(palindrome(7447) == "Decimal and binary.")
	assert(palindrome(18985) == "Binary only.")
	assert(palindrome(7) == "Decimal and binary.")
	assert(palindrome(1306031) == "Decimal only.")
	assert(palindrome(1) == "Decimal and binary.")
	assert(palindrome(1903127) == "Binary only.")
	assert(palindrome(4) == "Decimal only.")
	assert(palindrome(48084) == "Decimal only.")
	assert(palindrome(427787) == "Binary only.")
	assert(palindrome(456) == "Neither!")
	assert(palindrome(313) == "Decimal and binary.")
	assert(palindrome(3664663) == "Decimal only.")
	assert(palindrome(585585) == "Decimal and binary.")
	assert(palindrome(14441) == "Decimal only.")
	assert(palindrome(8494948) == "Decimal only.")
	assert(palindrome(932) == "Neither!")
	assert(palindrome(7115931) == "Binary only.")
	assert(palindrome(101) == "Decimal only.")
	assert(palindrome(6286333) == "Binary only.")
	assert(palindrome(934) == "Neither!")
}

func palindrome(n uint) string {
	s := fmt.Sprintf("%d", n)
	t := fmt.Sprintf("%b", n)

	x := ispalindrome(s)
	y := ispalindrome(t)
	switch {
	case x && y:
		return "Decimal and binary."
	case x && !y:
		return "Decimal only."
	case !x && y:
		return "Binary only."
	}
	return "Neither!"
}

func ispalindrome(s string) bool {
	l := len(s)
	for i := 0; i < l/2; i++ {
		if s[i] != s[l-i-1] {
			return false
		}
	}
	return true
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
