/*

Note: The winning answer will be selected on 4/12/17 the current winner is Jolf, 1 byte.

I'm surprised that we haven't had a what's my middle name challenge on this site yet. I did alot of searching but found nothing. If this is a dup, please flag it as such.
Your challenge

Parse a string that looks like Jo Jean Smith and return Jean.
Test cases

Input: Samantha Vee Hills
Output: Vee

Input: Bob Dillinger
Output: (empty string or newline)

Input: John Jacob Jingleheimer Schmidt
Output: Jacob Jingleheimer

Input: Jose Mario Carasco-Williams
Output: Mario

Input: James Alfred Van Allen
Output: Alfred Van

(That last one is incorrect technically, but fixing that would be too hard.)
Notes:

    Names will always have at least 2 space-separated parts, with unlimited middle names between them or can be a list/array of strings.
    Names may contain the alphabet (case-insensitive) and - (0x2d)
    You may output a trailing newline.
    You may require input to have a trailing newline.
    Input from STDIN, a function parameter, or command-line argument is allowed, but hard-coding it in is not allowed.
    Standard loopholes forbidden.
    Output may be function return value, STDOUT, STDERR, etc.
    Trailing spaces/newlines/tabs in the output are allowed.
    Any questions? Comment below!

This is code-golf, so the shortest anwser in bytes wins!

*/

package main

import "strings"

func main() {
	assert(middle("Samantha Vee Hills") == "Vee")
	assert(middle("Bob Dillinger") == "")
	assert(middle("John Jacob Jingleheimer Schmidt") == "Jacob Jingleheimer")
	assert(middle("Jose Mario Carasco-Williams") == "Mario")
	assert(middle("James Alfred Van Allen") == "Alfred Van")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func middle(s string) string {
	t := strings.Split(s, " ")
	if len(t) <= 2 {
		return ""
	}
	return strings.Join(t[1:len(t)-1], " ")
}
