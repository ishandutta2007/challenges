/*

It's time to send and receive secret messages.

Create two functions that take a string and an array and returns a coded or decoded message.

The first letter of the string, or the first element of the array represents the Character Code of that letter. The next elements are the differences between the characters: e.g. A +3 --> C or z -1 --> y.
Examples

encrypt("Hello") ➞ [72, 29, 7, 0, 3]
// H = 72, the difference between the H and e is 29 (upper- and lowercase).
// The difference between the two l's is obviously 0.

decrypt([ 72, 33, -73, 84, -12, -3, 13, -13, -68 ]) ➞ "Hi there!"

encrypt("Sunshine") ➞ [83, 34, -7, 5, -11, 1, 5, -9]

Notes

    The input of the encrypt function will always be a string.
    The input of the decrypt function will always be an array with numbers.

*/

package main

import (
	"bytes"
	"reflect"
)

func main() {
	test(encrypt("Hello"), []rune{72, 29, 7, 0, 3})
	test(decrypt([]rune{72, 33, -73, 84, -12, -3, 13, -13, -68}), "Hi there!")
	test(encrypt("?"), []rune{63})
	test(decrypt([]rune{84, 20, -3, -69, 78, -9, 4, -2, 1, -6, 13, 6, -3, 1, -83, 65, 17, -13, -69, 83, 1, -2, -17, 13, -7, -2, -55, 0}), "The neighbours are strange..")
	test(encrypt("It's a secret!"), []rune{73, 43, -77, 76, -83, 65, -65, 83, -14, -2, 15, -13, 15, -83})
	test(decrypt([]rune{79, -4}), "OK")
	test(decrypt([]rune{84, 27, -2, 2, 3, 0, -3, 8, -75, -12, 19, -19, 80, -3, -77, 73, 5, -78, 84, -12, -3, -69, 71, -6, 17, -14, 1, 9, -64}), "Tomorrow, 3 pm in the garden.")
	test(encrypt("Sunshine"), []rune{83, 34, -7, 5, -11, 1, 5, -9})
}

func test(x, y interface{}) {
	assert(reflect.DeepEqual(x, y))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func encrypt(s string) []rune {
	var p []rune
	var u rune
	for _, r := range s {
		p = append(p, r-u)
		u = r
	}
	return p
}

func decrypt(p []rune) string {
	var u rune
	w := new(bytes.Buffer)
	for _, r := range p {
		w.WriteRune(r + u)
		u += r
	}
	return w.String()
}
