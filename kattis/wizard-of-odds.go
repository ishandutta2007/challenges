/*

You have just completed a brave journey to see The Wizard of Odds, who agrees to grant you any wish, so long as you can complete the following puzzle:

The Wizard starts by telling you two integers: N and K. He then secretly selects a number from 1 to N (inclusive), and does not tell you this number.

Your goal is to correctly guess the secret number. Before guessing, you are allowed to ask K “true/false” questions about the number, for example,
“Is the number even?” or “Is the number between 7 and 10?”, or “Is the number 17 or 22?”, or “Is the number prime?”. And the Wizard will answer with “true” or “false” to each question.
The Wizard will always answer honestly. After answering the K

questions, you must guess the number. If you win (guess the number correctly), you will be granted your wish; but if the Wizard wins (you guess incorrectly), you will be turned into a flying monkey.

(Formally, you can think of a “question” as a function from 1,2,…,N to true, false, and the Wizard will answer by telling you whether the value of the function is true or false for his secret number.)

Assuming that you have been told N and K, can you always exactly determine the Wizard’s secret number (and guarantee that you win) using only K questions?

Input

The input consists of a single line containing two integers N and K (2≤N≤10101, 0≤K≤N), separated by a single space.

Note: These inputs might NOT fit into a 64-bit integer.

Output

Output “Your wish is granted!” (without the quotes) if it is possible for you to guarantee that you win the game (regardless of the number the Wizard picks).
Otherwise, print “You will become a flying monkey!” (without the quotes) if it is not possible.

*/

package main

import (
	"math/big"
)

func main() {
	assert(odds("8", "3") == "Your wish is granted!")
	assert(odds("1234567890987654321", "2") == "You will become a flying monkey!")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func odds(s, t string) string {
	x := xint(s)
	y := xint(t)
	p := ilog2(x)
	if p.Cmp(y) <= 0 {
		return "Your wish is granted!"
	}
	return "You will become a flying monkey!"
}

func xint(s string) *big.Int {
	x := new(big.Int)
	x.SetString(s, 0)
	return x
}

func ilog2(x *big.Int) *big.Int {
	var (
		one = big.NewInt(1)
		two = big.NewInt(2)
	)
	r := big.NewInt(0)
	for p := big.NewInt(1); p.Cmp(x) < 0; p.Mul(p, two) {
		r.Add(r, one)
	}
	return r
}
