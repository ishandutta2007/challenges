/*

A number n is apocalyptic if 2^n contains a string of 3 consecutive 6s (666 being the presumptive "number of the beast").

Create a function that takes a number n as input. If the number is apocalyptic, find the index of 666 in 2^n, and return "Repent! X days until the Apocalypse!" (X being the index).
If not, return "Crisis averted. Resume sinning.".

Examples

apocalyptic(109) ➞ "Crisis averted. Resume sinning."

apocalyptic(157) ➞ "Repent! 9 days until the Apocalypse!"
// 2^157 -> 182687704666362864775460604089535377456991567872
// 666 at 10th position (index 9)

apocalyptic(175) ➞ "Crisis averted. Resume sinning."

apocalyptic(220) ➞ "Repent! 6 days until the Apocalypse!"

Notes

N/A

*/

package main

import (
	"fmt"
	"math/big"
	"strings"
)

func main() {
	assert(apocalyptic(109) == "Crisis averted. Resume sinning.")
	assert(apocalyptic(157) == "Repent! 9 days until the Apocalypse!")
	assert(apocalyptic(175) == "Crisis averted. Resume sinning.")
	assert(apocalyptic(220) == "Repent! 6 days until the Apocalypse!")
	assert(apocalyptic(333) == "Crisis averted. Resume sinning.")
	assert(apocalyptic(499) == "Repent! 138 days until the Apocalypse!")
	assert(apocalyptic(666) == "Repent! 49 days until the Apocalypse!")
	assert(apocalyptic(1003) == "Crisis averted. Resume sinning.")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func apocalyptic(n uint) string {
	p := big.NewInt(1)
	p.Lsh(p, n)
	s := p.String()
	i := strings.Index(s, "666")
	if i >= 0 {
		return fmt.Sprintf("Repent! %d days until the Apocalypse!", i)
	}
	return "Crisis averted. Resume sinning."
}
