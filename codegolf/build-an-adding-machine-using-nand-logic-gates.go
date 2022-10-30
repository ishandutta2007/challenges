/*

This is "programming" at its most fundamental.

Build a diagram of (two-wire) NAND logic gates that will take the input wires A1, A2, A4, A8, B1, B2, B4, B8,
representing two binary numbers A to B from 0 to 15, and return values on the output wires C1, C2, C4, and C8 representing C, which is the sum of A and B modulo 16.

Your score is determined by the number of NAND gates (1 point per gate). To simplify things, you may use AND, OR, NOT, and XOR gates in your diagram, with the following corresponding scores:

NOT: 1
AND: 2
OR: 3
XOR: 4

Each of these scores corresponds to the number of NAND gates that it takes to construct the corresponding gate.

Lowest score wins.

*/

package main

func main() {
	for a := 0; a < 16; a++ {
		for b := 0; b < 16; b++ {
			x := add4(a, b)
			y := (a + b) % 16
			assert(x == y)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

https://en.wikipedia.org/wiki/NAND_logic
https://www.electronics-tutorials.ws/combination/comb_7.html

*/

func nand(a, b int) int {
	return ^(a & b) & 1
}

func and(a, b int) int {
	return nand(nand(a, b), nand(a, b))
}

func or(a, b int) int {
	return nand(nand(a, a), nand(b, b))
}

func xor(a, b int) int {
	return nand(nand(a, nand(a, b)), nand(b, nand(a, b)))
}

func hadd(a, b int) (S, C int) {
	S = xor(a, b)
	C = and(a, b)
	return
}

func fadd(a, b, c int) (S, C int) {
	s1, c1 := hadd(a, b)
	s2, c2 := hadd(s1, c)

	S = s2
	C = or(c1, c2)
	return
}

func add4(a, b int) int {
	a0 := (a >> 0) & 1
	a1 := (a >> 1) & 1
	a2 := (a >> 2) & 1
	a3 := (a >> 3) & 1

	b0 := (b >> 0) & 1
	b1 := (b >> 1) & 1
	b2 := (b >> 2) & 1
	b3 := (b >> 3) & 1

	s0, c0 := fadd(a0, b0, 0)
	s1, c1 := fadd(a1, b1, c0)
	s2, c2 := fadd(a2, b2, c1)
	s3, _ := fadd(a3, b3, c2)

	return s0 | s1<<1 | s2<<2 | s3<<3
}
