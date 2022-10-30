/*

Your challenge is to write a program that when first run, will do one of the actions below at random with equal chances of both:

A cat program

A standard cat program: read everything from STDIN and put it on STDOUT (or your language's closest equivalent).
Do nothing and halt

This shouldn't output anything.
The behaviour is permanent - once the program chooses between the two options, it should do that no matter how much times you run the script. It's fine if this resets when you reboot.

Please provide an explanation on how to reset the program (which file to delete for example)

Standard loopholes are forbidden.

This is a code-golf, so the shortest code (in bytes or equivalent) wins.

*/

package main

import (
	"fmt"
	"io"
	"math/rand"
	"os"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	collapse()
}

func collapse() {
	if n := state(); n == 0 {
		io.Copy(os.Stdout, os.Stdin)
	}
}

func state() int {
	n := rand.Intn(2)

	r, err := os.Open("state.txt")
	if err == nil {
		fmt.Fscan(r, "%d", &n)
		r.Close()
	}

	w, err := os.Create("state.txt")
	if err == nil {
		fmt.Fprintln(w, n)
		w.Close()
	}

	return n
}
