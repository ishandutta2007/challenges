/*

It is JJ's birthday and you decide to gift him a string S (consisting of English alphabet only) of length N.
But you also know that JJ does not like palindromes so you decide that none of the substrings of S of length ≥2 should be a palindrome.

Can you find any suitable string which can be gifted to JJ?

Recall that a string is called palindrome if it reads the same backwards and forwards, for e.g. noon and level are palindromic strings.

Input Format

The first line contains T - the number of test cases. Then the test cases follow.
The first and only line of each test case contains an integer N - the length of the string S to be constructed.

Output Format

For each test case, output a string S of length N such that none of its substrings (of length ≥2) is a palindrome.

If there are multiple strings which satisfy the condition, print any.

Constraints
1≤T≤100
1≤N≤1000

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	fmt.Println(construct(2))
	fmt.Println(construct(4))
	fmt.Println(construct(16))
}

func construct(n int) string {
	w := new(bytes.Buffer)
	r := 'a'
	for i := 0; i < n; i++ {
		w.WriteRune(r)
		if r++; r == 'd' {
			r = 'a'
		}
	}
	return w.String()
}
