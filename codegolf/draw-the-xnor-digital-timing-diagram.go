/*

Below is a (schematic) Digital timing diagram, for the XNOR logic gate.

    ┌─┐ ┌─┐ ┌─────┐ ┌─┐ ┌─┐ ┌───┐
A ──┘ └─┘ └─┘     └─┘ └─┘ └─┘   └──
  ┌───┐ ┌───┐ ┌─┐ ┌─────┐   ┌─┐ ┌─┐
B ┘   └─┘   └─┘ └─┘     └───┘ └─┘ └
    ┌─────┐   ┌─┐   ┌─┐   ┌───┐
X ──┘     └───┘ └───┘ └───┘   └────
Your goal is to reproduce it exactly as depicted.

Rules:

You can either print it or return a multiline string;

Arbitrary number of traling and/or leading newlines are allowed;

Trailing (but not leading !) whitespace is allowed;

If you can not use the extended ASCII box-drawing characters, you may substitute them for the unicode equivalents (at no byte penalty).

This is code-golf so the shortest answer in bytes wins.

Binary Representation

For your convenience, binary representation of the diagram above is as follows:

INP A=0101011101010110
INP B=1101101011100101
  ___
X=A⊕B=0111001001001100
Sample Output

enter image description here

Sidenote

While working on this question, I've implemented two different bash solutions for it, one is 122 characters/bytes long (as depicted above), and another one is exactly 100 bytes long.

I do not have plans to post them (as I don't normally post answers to my own questions), so that is just for reference.

I also believe that at least some sub-100 byte solutions are possible.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	diagram("0101011101010110", "1101101011100101")
}

func diagram(a, b string) {
	output(a, 'A')
	output(b, 'B')
	output(xnor(a, b), 'X')
}

func output(s string, c rune) {
	u := new(bytes.Buffer)
	l := new(bytes.Buffer)
	n := len(s)
	b := 0
	for i := 0; i <= n; i++ {
		a := 0
		if i < n {
			a = truth(s[i])
		}
		switch {
		case b == 0 && a == 1:
			fmt.Fprintf(u, "┌")
			fmt.Fprintf(l, "┘")
		case b == 1 && a == 0:
			fmt.Fprintf(u, "┐")
			fmt.Fprintf(l, "└")
		case a == 0:
			fmt.Fprintf(u, " ")
			fmt.Fprintf(l, "─")
		case a == 1:
			fmt.Fprintf(u, "─")
			fmt.Fprintf(l, " ")
		}
		b = a
	}
	fmt.Printf("  %v\n%c %v\n", u, c, l)
}

func truth(c byte) int {
	if c == '1' {
		return 1
	}
	return 0
}

func xnor(a, b string) string {
	x := new(bytes.Buffer)
	for i := 0; i < len(a) && i < len(b); i++ {
		c := byte('0')
		if truth(a[i])^truth(b[i]) == 0 {
			c = '1'
		}
		x.WriteByte(c)
	}
	return x.String()
}
