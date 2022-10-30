/*

Text to DNA golf

Challenge

Convert input into a DNA output.
Algorithm

    Convert text into ASCII code points (e.g. codegolf -> [99, 111, 100, 101, 103, 111, 108, 102])
    String the ASCII codes together (e.g. 99111100101103111108102)
    Convert to binary (e.g. 10100111111001101001011010001000011001101011011110000110010111111011000000110)
    Pad 0s onto the end to make an even number of characters (e.g. 101001111110011010010110100010000110011010110111100001100101111110110000001100)
    Replace 00 with A, 01 with C, 10 with G, and 11 with T (e.g. GGCTTGCGGCCGGAGACGCGGTCTGACGCCTTGTAAATA)
    Output

Test Cases

codegolf > GGCTTGCGGCCGGAGACGCGGTCTGACGCCTTGTAAATA
ppcg > GGCTAATTGTCGCACTT
} > TTGG (padding)

Specifications

    This is code-golf
    Your program must accept spaces in input.
    Your program must work for codegolf.

*/

package main

import (
	"bytes"
	"fmt"
	"math/big"
)

func main() {
	test("codegolf", "GGCTTGCGGCCGGAGACGCGGTCTGACGCCTTGTAAATA")
	test("ppcg", "GGCTAATTGTCGCACTT")
	test("}", "TTGG")
}

func test(s, r string) {
	p := txt2dna(s)
	fmt.Println(s, p)
	assert(p == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func txt2dna(s string) string {
	p := str2bin(s)
	w := new(bytes.Buffer)
	for i := 0; i < len(p); i += 2 {
		var c rune
		switch p[i:(i + 2)] {
		case "00":
			c = 'A'
		case "01":
			c = 'C'
		case "10":
			c = 'G'
		case "11":
			c = 'T'
		}
		w.WriteRune(c)
	}
	return w.String()
}

func str2bin(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		fmt.Fprintf(w, "%d", r)
	}

	x := new(big.Int)
	x.SetString(w.String(), 10)

	p := fmt.Sprintf("%b", x)
	if len(p)&1 != 0 {
		p += "0"
	}
	return p
}
