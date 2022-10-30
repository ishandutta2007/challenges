/*

Description -
Write a program that outputs the first recurring character in a string.

Formal Inputs & Outputs -
Input Description
A string of alphabetical characters. Example:

ABCDEBC
Output description
The first recurring character from the input. From the above example:
B

Challenge Input
IKEUNFUVFV
PXLJOUDJVZGQHLBHGXIW
*l1J?)yn%R[}9~1"=k7]9;0[$

Bonus
Return the index (0 or 1 based, but please specify) where the original character is found in the string.

*/

package main

import "fmt"

func main() {
	frch("ABCDEBC")
	frch("IKEUNFUVFV")
	frch("PXLJOUDJVZGQHLBHGXIW")
	frch("*l1J?)yn%R[}9~1\"=k7]9;0[$")
}

func frch(s string) int {
	m := make(map[rune]int)
	for i, c := range s {
		if n, found := m[c]; found {
			fmt.Printf("index %d has the original character %c\n", n, c)
			return i
		}
		m[c] = i
	}
	fmt.Println("no recurring characters")
	return -1
}
