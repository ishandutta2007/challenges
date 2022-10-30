/*

Find the index of a string within a hex encoded string.

You will be given a string which needs to be found in another string which has previously been translated into hex. You will need to return the first index of the needle within the hex encoded string.
Examples

firstIndex("68 65 6c 6c 6f 20 77 6f 72 6c 64", "world") ➞ 6

firstIndex("47 6f 6f 64 62 79 65 20 77 6f 72 6c 64", "world") ➞ 8

firstIndex("42 6f 72 65 64 20 77 6f 72 6c 64", "Bored") ➞ 0

*/

package main

import (
	"encoding/hex"
	"strings"
)

func main() {
	assert(firstindex("68 65 6c 6c 6f 20 77 6f 72 6c 64", "world") == 6)
	assert(firstindex("47 6f 6f 64 62 79 65 20 77 6f 72 6c 64", "world") == 8)
	assert(firstindex("74 68 65 20 6e 65 65 64 6c 65 20 69 73 20 74 6f 20 62 65 20 66 6f 75 6e 64", "needle") == 4)
	assert(firstindex("a3 24 25 2d 2d 2d a3 24 20 77 6f 72 6c 64 2d 2d 2d", "world") == 9)
	assert(firstindex("42 6f 72 65 64 20 77 6f 72 6c 64", "Bored") == 0)
}

func firstindex(h, w string) int {
	h = strings.Replace(h, " ", "", -1)
	s, err := hex.DecodeString(h)
	if err != nil {
		return -1
	}
	return strings.Index(string(s), w)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
