/*

Interpret a triple of 32-bit integers as a vector of 32 integers modulo 5. Write an addition routine for these vectors.

Example:

def add32((a0,a1,a2),(b0,b1,b2)):
    c0 = c1 = c2 = 0
    m = 1
    for i in range(32):
        a  = ((a0//m)&1) + 2*((a1//m)&1) + 4*((a2//m)&1)
        b  = ((b0//m)&1) + 2*((b1//m)&1) + 4*((b2//m)&1)
        c  = (a+b)%5
        c0+= m*(c&1)
        c1+= m*((c&2)//2)
        c2+= m*((c&4)//4)
        m += m
    return c0,c1,c2

Note:

You only need to be internally consistent, not consistent with my sample code. If you use a different representation of the integers mod 5, that's fine as long as you provide a translation table of the form:

0 = 000 or 101
1 = 001 or 110
2 = 010 or 111
3 = 011
4 = 100
Scoring:

Characters + number of arithmetic operations required. The sample code takes 331 characters and 34 operations per bit (note that I'm not counting the function call or iteration, nor interpreter overhead); hence gets a score of 331+1056=1686.

Clarification:

This is a trick called bitslicing. It's natural to pack integers mod 5 directly into words (spaces added for clarity:

0 1 2 3 4 -> 000 001 010 001 101
but you end up sacrificing a few bits at the end of each word. To keep your data aligned but pack the most in, store the data in slices

                 0 0 0 0 1 = a2
a = 0 1 2 3 4 -> 0 0 1 1 0 = a1
                 0 1 0 1 0 = a0
Example 2

A language-agnostic example was requested, so here it is. Suppose we use the representation

0 = 100
1 = 001
2 = 010 or 101
3 = 110
4 = 011
and 111 and 000 are meaningless. Then, the following sum is valid according to our representation:

                  1 0 0 1 1 0 1 0
0 1 2 2 3 4 0 2 = 0 0 1 0 1 1 0 1
                  0 1 0 1 0 1 0 0
+
                  0 1 0 0 1 0 1 1
1 2 1 2 0 1 0 3 = 0 0 0 1 0 0 0 1
                  1 1 1 0 0 1 0 0
---------------------------------
                  0 1 1 0 1 1 1 1
1 3 3 4 3 0 0 0 = 0 1 1 1 1 0 0 0
                  1 0 0 1 0 0 0 0
Remark

As Keith Randall has demonstrated, this can be done with all bits in parallel using logical operators. We can view such a solution as a circuit with a certain number of gates.
Perhaps I should call this "circuit golf". I chose 5 instead of 3 because it's too easy to brute-force (optimal is 6 gates/trit).

*/

package main

import "fmt"

func main() {
	fmt.Println(add32(0, 1, 2, 2, 3, 4))
}

func add32(a0, a1, a2, b0, b1, b2 uint32) (c0, c1, c2 uint32) {
	m := uint32(1)
	for i := 0; i < 32; i++ {
		a := ((a0 / m) & 1) + 2*((a1/m)&1) + 4*((a2/m)&1)
		b := ((b0 / m) & 1) + 2*((b1/m)&1) + 4*((b2/m)&1)
		c := (a + b) % 5
		c0 += m * (c & 1)
		c1 += m * ((c & 2) / 2)
		c2 += m * ((c & 4) / 4)
		m += m
	}
	return
}
