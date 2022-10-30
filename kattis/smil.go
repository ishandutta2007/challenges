/*

Siffermaskinen i Lund (SMIL, “The Number Machine in Lund”) was a first-generation computer built at Lund University, in operation from 1956 to 1970.
It was based on the computer architecture developed by John von Neumann at the Institute of Advanced Studies at Princeton.

Your task is to find the smiles in the memory of SMIL. A smile is sequence of symbols of the form “:)”, “;)”, “:-)”, or “;-)”.

Input

A single line of at most 2048 symbols, such as letters from the English alphabet, digits, space, and many punctuation marks. (To be precise, the symbols are from the ASCII range 32 to 126.)
The line contains at least one “:)”.

Output

A nonempty sequence of integers, separated by whitespace, of memory addresses at which a smile appears.
The order is not important. The address of a smile is the address of the “eyes,” i.e., the first symbol.
SMIL’s memory addresses are enumerated 0, 1, …, 2047. The input line starts at address 0.

*/

package main

import (
	"fmt"
	"reflect"
	"regexp"
)

func main() {
	test(":)xsy:->>;-)::)3", []int{0, 9, 13})
	test(":-):);-):)", []int{0, 3, 5, 8})
	test("::))(:", []int{1})
	test("):):", []int{1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []int) {
	p := smileys(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func smileys(s string) []int {
	re := regexp.MustCompile(":\\)|;\\)|:-\\)|;-\\)")
	in := re.FindAllStringIndex(s, -1)

	r := make([]int, len(in))
	for i := range r {
		r[i] = in[i][0]
	}
	return r
}
