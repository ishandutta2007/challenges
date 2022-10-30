/*

I am very surprised that this has not been asked yet (or I didn't search hard enough). Either way, this challenge is very simple:

Input: A program in the form of a string. Additionally, the input may or may not contain:

    Leading and trailing spaces
    Trailing newlines
    Non-ASCII characters

Output: Two integers, one representing UTF-8 character count and one representing byte count, you may choose which order.
Trailing newlines are allowed. Output can be to STDOUT or returned from a function.
IT can be in any format as long as the two numbers are distinguishable from each other (2327 is not valid output).

Notes:

    You may consider newline as \n or \r\n.
    Here is a nice byte & character counter for your tests. Also, here is a meta post with the same thing (Thanks to @Zereges).

Sample I/O: (All outputs are in the form {characters} {bytes})

Input: void p(int n){System.out.print(n+5);}

Output: 37 37

Input: (~R∊R∘.×R)/R←1↓ιR

Output: 17 27

Input:


friends = ['john', 'pat', 'gary', 'michael']
for i, name in enumerate(friends):
    print "iteration {iteration} is {name}".format(iteration=i, name=name)

Output: 156 156

This is code golf - shortest code in bytes wins!

*/

package main

import (
	"fmt"
	"unicode/utf8"
)

func main() {
	test(`void p(int n){System.out.print(n+5);}`, 37, 37)
	test(`(~R∊R∘.×R)/R←1↓ιR`, 17, 27)
	test(`friends = ['john', 'pat', 'gary', 'michael']
for i, name in enumerate(friends):
    print "iteration {iteration} is {name}".format(iteration=i, name=name)

`, 156, 156)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, rr, rc int) {
	r, c := count(s)
	fmt.Println(r, c)
	assert(r == rr && c == rc)
}

func count(s string) (int, int) {
	return utf8.RuneCountInString(s), len(s)
}
