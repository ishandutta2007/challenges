/*

Wikipedia: Zeno's Dichotomy Paradox

    An infinite number of mathematicians walk into a bar. The first one orders a beer. The second one orders half a beer. The third one orders a fourth of a beer. The bartender stops them, pours two beers and says, "You're all a bunch of idiots."

    Reddit

Print the following series for as long as the program runs, with the denominator of each item being multiplied by two each time:

1 + 1/2 + 1/4 + 1/8 + 1/16 + 1/32 + ...

As n approaches infinity, the sum of this sequence approaches 2.
Rules

No, you may not print 2.

You may not print 1/1 as the first item.

You may remove spaces 1+1/2+... or add spaces 1 + 1 / 2 + ... as you need.

You may use newlines instead of spaces as a delimiter due to popular demand.

You may append a . plus a constant number of 0s to the denominator if need be.

"Infinitely" means no unnecessary delays, and for as long as possible limited by the current (variable) system's specs, but not limited by your current language.

Standard loopholes apply.

This is code-golf, so shortest answer in bytes wins.

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	zeno()
}

func zeno() {
	x := big.NewRat(1, 2)
	h := big.NewRat(1, 2)

	fmt.Println("1 +")
	for {
		fmt.Printf("%v +\n", x)
		x.Mul(x, h)
	}
}
