/*

Task

Given a UTF-8 string (by any means) answer (by any means) an equivalent list where every element is the number of bytes used to encode the corresponding input character.

Examples

! → 1

Ciao → 1 1 1 1

tʃaʊ → 1 2 1 2

Adám → 1 1 2 1

ĉaŭ → 2 1 2 (single characters)

ĉaŭ → 1 2 1 1 2 (uses combining overlays)

チャオ → 3 3 3

(empty input) → (empty output)

!±≡𩸽 → 1 2 3 4

� (a null byte) → 1
Null bytes

If the only way to keep reading input beyond null bytes is by knowing the total byte count, you may get the byte count by any means (even user input).

If your language cannot handle null bytes at all, you may assume the input does not contain nulls.

*/

package main

import (
	"fmt"
	"reflect"
	"unicode/utf8"
)

func main() {
	test("!", []int{1})
	test("Ciao", []int{1, 1, 1, 1})
	test("tʃaʊ", []int{1, 2, 1, 2})
	test("Adám", []int{1, 1, 2, 1})
	test("ĉaŭ", []int{2, 1, 2})
	test("ĉaŭ", []int{1, 2, 1, 1, 2})
	test("チャオ", []int{3, 3, 3})
	test("", []int{})
	test("!±≡𩸽", []int{1, 2, 3, 4})
	test("\x00", []int{1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []int) {
	p := width(s)
	fmt.Println(s, p, r)
	assert(reflect.DeepEqual(p, r))
}

func width(s string) []int {
	p := []int{}
	for {
		_, w := utf8.DecodeRuneInString(s)
		if w == 0 {
			break
		}
		p, s = append(p, w), s[w:]
	}
	return p
}
