/*

"coconuts" has 8 letters.
A byte in binary has 8 bits.
A byte can represent a character.

We can use the word "coconuts" to communicate with each other in binary if we use upper case letters as 1s and lower case letters as 0s.

Create a function that translates a word in plain text, into Coconut.
Worked Example

The binary for "coconuts" is
01100011 01101111 01100011 01101111 01101110 01110101 01110100 01110011
c         o        c       o       n        u        t       s

Since 0s are lowercase and 1s are uppercase, we can map the binary like this.
cOConuTS cOCoNUTS cOConuTS cOCoNUTS cOCoNUTs cOCOnUtS cOCOnUts cOCOnuTS

coconut_translator("coconuts") ➞ "cOConuTS cOCoNUTS cOConuTS cOCoNUTS cOCoNUTs cOCOnUtS cOCOnUts cOCOnuTS"

Examples

coconutTranslator("Hi") ➞ "cOcoNuts cOCoNutS"

coconutTranslator("edabit") ➞ "cOConUtS cOConUts cOConutS cOConuTs cOCoNutS cOCOnUts"

coconutTranslator("123") ➞ "coCOnutS coCOnuTs coCOnuTS"

Notes

    All inputs will be strings.
    Make sure to separate the coconuts with spaces.

*/

package main

import (
	"bytes"
	"unicode"
)

func main() {
	assert(coconut("Hi") == "cOcoNuts cOCoNutS")
	assert(coconut("edabit") == "cOConUtS cOConUts cOConutS cOConuTs cOCoNutS cOCOnUts")
	assert(coconut("123") == "coCOnutS coCOnuTs coCOnuTS")
	assert(coconut("coconuts") == "cOConuTS cOCoNUTS cOConuTS cOCoNUTS cOCoNUTs cOCOnUtS cOCOnUts cOCOnuTS")
	assert(coconut("") == "")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func coconut(s string) string {
	const word = "coconuts"

	b := new(bytes.Buffer)
	for i, r := range s {
		for j, w := range word {
			ch := w
			if r&(1<<(len(word)-j-1)) != 0 {
				ch = unicode.ToUpper(ch)
			}
			b.WriteRune(ch)
		}
		if i+1 < len(s) {
			b.WriteRune(' ')
		}
	}
	return b.String()
}
