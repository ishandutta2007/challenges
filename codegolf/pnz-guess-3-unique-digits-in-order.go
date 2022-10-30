/*

From a challenge in a programming book long ago, PNZ is a game where the user must guess three unique digits in the correct order.

Rules:

A random 3 digit number with no repeating digits is generated. (This is what the user is trying to guess)
The user inputs a guess of 3 digits, which is to be evaluated by the program.
Output a "P" for every correct digit in a correct place.
Output a "N" for every correct digit in an incorrect place.
Output a "Z" only if no digits are correct.
Continue accepting inputs until all digits are correct and in the correct place, then output "PPP" followed by the number of guesses it took on a new line.

Note:

A "Correct digit" means that one of the digits in the guess is also one of the digits in the random 3 digit number.

A "Correct place" means it is a "Correct digit" AND is in the same place as the 3 digit random number.

The order of outputting should be all "P"'s first, then "N"'s, or only "Z" if nothing is correct.

If an input contains repeating digits, "P" takes priority over "N" (Example: Number: 123 Input: 111 Output: P)

(OPTIONAL) Inputs that are not exactly 3 digits in length should not be evaluated, nor count towards the running total of guesses

Example if the generated digits were 123

> 147
P
> 152
PN
> 126
PP
> 123
PPP
4
Example if the generated digits were 047

> 123
Z
> 456
N
> 478
NN
> 947
PP
> 047
PPP
5

This is CodeGolf, so the shortest program wins!

*/

package main

import (
	"fmt"
	"math/rand"
	"strings"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	play()
}

func play() {
	x := gen()
	g := 0
	for {
		var s string
		fmt.Printf("> ")
		_, err := fmt.Scanln(&s)
		if err != nil {
			fmt.Println()
			fmt.Println("The answer was", x)
			return
		}

		y, ok := digits(s)
		if len(x) != len(y) || !ok {
			fmt.Println("Invalid input!")
			continue
		}

		p, n, z := cmp(x, y)
		fmt.Print(strings.Repeat("P", p))
		fmt.Print(strings.Repeat("N", n))
		fmt.Print(strings.Repeat("Z", z))
		fmt.Println()
		if g++; p == len(x) {
			break
		}
	}
	fmt.Println(g)
}

func gen() []int {
	p := rand.Perm(10)
	return p[:3]
}

func digits(s string) ([]int, bool) {
	var r []int
	for i := 0; i < len(s); i++ {
		if !('0' <= s[i] && s[i] <= '9') {
			return nil, false
		}
		r = append(r, int(s[i]-'0'))
	}
	return r, true
}

func cmp(x, y []int) (p, n, z int) {
	f := make([]int, len(x))
	for i := range x {
		for j := range y {
			if i == j && x[i] == y[j] {
				f[i], p = 1, p+1
			} else if i != j && x[i] == y[j] && f[i] == 0 {
				f[i], n = 2, n+1
			}
		}
	}

	if p == 0 && n == 0 {
		z = 1
	}

	return
}
