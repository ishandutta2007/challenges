/*

If you express some positive integer in binary with no leading zeros and replace every 1 with a ( and every 0 with a ), then will all the parentheses match?

In most cases they won't. For example, 9 is 1001 in binary, which becomes ())(, where only the first two parentheses match.

But sometimes they will match. For example, 44 is 101100 in binary, which becomes ()(()), where all the left parentheses have a matching right parenthesis.

Write a program or function that takes in a positive base ten integer and prints or returns a truthy value if the binary-parentheses version of the number has all matching parentheses. If it doesn't, print or return a falsy value.

The shortest code in bytes wins.

Related OEIS sequence.

Truthy examples below 100:

2, 10, 12, 42, 44, 50, 52, 56
Falsy examples below 100:

1, 3, 4, 5, 6, 7, 8, 9, 11, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 43, 45, 46, 47, 48, 49, 51, 53, 54, 55, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99

*/

package main

import "fmt"

func main() {
	truthy := []uint{2, 10, 12, 42, 44, 50, 52, 56}
	falsy := []uint{1, 3, 4, 5, 6, 7, 8, 9, 11, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 43, 45, 46, 47, 48, 49, 51, 53, 54, 55, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99}

	for _, v := range truthy {
		assert(parenb(v) == true)
	}
	for _, v := range falsy {
		assert(parenb(v) == false)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A014486
func parenb(n uint) bool {
	s := fmt.Sprintf("%b", n)
	p := 0
	for i := 0; i < len(s); i++ {
		switch {
		case s[i] == '1':
			p++
		case p > 0:
			p--
		default:
			return false
		}
	}
	return p == 0
}
