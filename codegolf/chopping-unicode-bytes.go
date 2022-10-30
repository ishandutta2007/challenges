/*

Introduction

Each Unicode codepoint can be represented as a sequence of up to 4 bytes. Because of this, it is possible to interpret some 2, 3, or 4-byte characters as multiple 1-byte characters. (See here for a UTF-8 to bytes converter).
Challenge

Given a UTF-8 character, output it split into a sequence of 1-byte characters. If the character is 1-byte already, return it unchanged.

    Your program must take one, and exactly one, UTF-8 character as input. You may use any input method you wish, as long as it has been decided on meta that is is a valid method. You cannot take input as a bytearray or series of bytes; then the challenge would just be converting hex to ASCII.
    Your program must output one or more ASCII 1-byte characters. Again, any output method is allowed as long as it has been marked valid on meta. Edit: As per the conversation in the comments, output should be in Code Page 850.

Note: see this post for valid I/O methods.
Example I/O

    ܀ (0x700)
    ▄Ç (0xdc 0x80)

    a (0x61)
    a (0x61)

    聂 (0x8042)
    Þüé (0xe8 0x81 0x82)

Rules

This is code-golf, so shortest answer in bytes wins!

*/

package main

import (
	"bytes"
	"fmt"
	"unicode/utf8"

	"golang.org/x/text/encoding/charmap"
)

func main() {
	assert(chop('܀') == "▄Ç")
	assert(chop('a') == "a")
	assert(chop('聂') == "Þüé")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func chop(r rune) string {
	var (
		b [utf8.UTFMax]byte
		w = new(bytes.Buffer)
	)

	utf8.EncodeRune(b[:], r)
	for i := range b {
		if b[i] == 0 {
			break
		}
		fmt.Fprintf(w, "%c", charmap.CodePage850.DecodeByte(b[i]))
	}
	return w.String()
}
