/*

Take a string of binary characters separated by a space, and convert it to an ASCII string.

For example...

1001000 1100101 1101100 1101100 1101111 100000 1010111 1101111 1110010 1101100 1100100
Would convert to...

Hello World
The binary string will be stored in a variable called s.

*/

package main

import (
	"bytes"
	"fmt"
	"strconv"
	"strings"
)

func main() {
	assert(conv("1001000 1100101 1101100 1101100 1101111 100000 1010111 1101111 1110010 1101100 1100100") == "Hello World")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func conv(s string) string {
	w := new(bytes.Buffer)
	t := strings.Split(s, " ")
	for _, t := range t {
		v, err := strconv.ParseInt(t, 2, 64)
		if err == nil {
			fmt.Fprintf(w, "%c", v)
		}
	}
	return w.String()
}
