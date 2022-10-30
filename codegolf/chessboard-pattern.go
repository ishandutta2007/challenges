/*

Input: a positive number n, smaller than 80, from stdin or as a command-line argument.

Output: A square chessboard pattern, the size of the input number. The dark fields are represented by the letter X, the white fields by a space. The top-left field should be X.

A complete program is required. This is code-golf so the shortest code in bytes wins

Examples:

Input: 1

Output:

X

Input: 8

Output:

X X X X
 X X X X
X X X X
 X X X X
X X X X
 X X X X
X X X X

*/

package main

import "fmt"

func chessboard(n int) {
	z := 1
	for y := 0; y < n; y++ {
		for x := 0; x < n; x++ {
			fmt.Printf("%c", 32+56*z)
			z = 1 - z
		}
		z = 1 - z
		fmt.Println()
	}
	fmt.Println()
}

func main() {
	chessboard(1)
	chessboard(8)
}
