/*

Description

A number is input in computer then a new no should get printed by adding one to each of its digit. If you encounter a 9, insert a 10 (don't carry over, just shift things around).

For example, 998 becomes 10109.
Bonus

This challenge is trivial to do if you map it to a string to iterate over the input, operate, and then cast it back. Instead, try doing it without casting it as a string at any point, keep it numeric (int, float if you need it) only.
Credit

This challenge was suggested by user /u/chetvishal, many thanks! If you have a challenge idea please share it in /r/dailyprogrammer_ideas and there's a good chance we'll use it.

*/

package main

import (
	"bytes"
	"fmt"
	"strconv"
)

func main() {
	assert(increment(998) == 10109)
	assert(increment(555) == 666)
	assert(increment(1000) == 2111)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func increment(n uint) uint {
	s := fmt.Sprint(n)
	w := new(bytes.Buffer)
	for _, r := range s {
		if '0' <= r && r <= '8' {
			w.WriteRune(r + 1)
		} else {
			w.WriteString("10")
		}
	}

	r, _ := strconv.ParseUint(w.String(), 0, 64)
	return uint(r)
}
