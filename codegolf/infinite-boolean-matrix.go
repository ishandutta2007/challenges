/*

It's geeky to see a Boolean Matrix animation, but a live one would be better. Echoing only 1s and 0s create a program that creates an infinite loop of integer matrix.

1s and 0s are randomly echoed like an error.

*/

package main

import (
	"crypto/rand"
	"fmt"
)

func main() {
	var b [4096]byte
	for {
		rand.Read(b[:])
		for i := range b {
			fmt.Printf("%d", b[i]&1)
		}
	}
}
