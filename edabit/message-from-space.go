/*

You have received an encrypted message from space. Your task is to decrypt the message with the following simple rules:

    Message string will consist of capital letters, numbers, and brackets only.
    When there's a block of code inside the brackets, such as [10AB], it means you need to repeat the letters AB for 10 times.
    Message can be embedded in multiple layers of blocks.
    Final decrypted message will only consist of capital letters.

Create a function that takes encrypted message str and returns the decrypted message.
Examples

spaceMessage("ABCD") ➞ "ABCD"

spaceMessage("AB[3CD]") ➞ "ABCDCDCD"
// "AB" = "AB"
// "[3CD]" = "CDCDCD"

spaceMessage("IF[2E]LG[5O]D") ➞ "IFEELGOOOOOD"

Notes

N/A

*/

package main

import (
	"bytes"
	"fmt"
	"io"
	"strings"
)

func main() {
	assert(spacecode("ABCD") == "ABCD")
	assert(spacecode("AB[3CD]") == "ABCDCDCD")
	assert(spacecode("AB[2[3CD]]") == "ABCDCDCDCDCDCD")
	assert(spacecode("IF[2E]LG[5O]D") == "IFEELGOOOOOD")
	assert(spacecode("AB[2C[2EF]G]") == "ABCEFEFGCEFEFG")
	assert(spacecode("MU[2B][2A][2S][2H][2I]RISN[4O]TAMA[4Z]ING") == "MUBBAASSHHIIRISNOOOOTAMAZZZZING")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func spacecode(s string) string {
	return gen(strings.NewReader(s), 1, 0)
}

func gen(r io.Reader, n, d int) string {
	w := new(bytes.Buffer)
loop:
	for {
		var ch rune
		_, err := fmt.Fscanf(r, "%c", &ch)
		if err != nil {
			break
		}

		switch ch {
		case '[':
			var m int
			fmt.Fscanf(r, "%d", &m)
			w.WriteString(gen(r, m, d+1))
		case ']':
			if d > 0 {
				break loop
			}
		default:
			w.WriteRune(ch)
		}
	}

	var p string
	if n > 0 {
		p = strings.Repeat(w.String(), n)
	}
	return p
}
