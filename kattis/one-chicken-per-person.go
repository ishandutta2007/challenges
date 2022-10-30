/*

Dr. Chaz is hosting a programming contest wrap up dinner.
Dr. Chaz has severe OCD and is very strict on rules during dinner, specifically, he needs to be sure that everyone take exactly 1 piece of chicken at his buffet, even if that will result in an enormous amount of leftovers.
This is why every year before the dinner, Dr. Chaz would give a powerful speech: “Everyone, one chicken per person!”

However, Dr. Chaz does not always have an idea how many pieces of chicken he needs, he believes if there are N people at the buffet and everyone takes exactly 1 piece of chicken, providing M pieces of chicken will be perfect,
i.e., is enough and will have no leftovers. Help Dr. Chaz find out whether his decision is good or not!

Input

The first line contain integers 0≤N≤1000, 0≤M≤1000, N≠M, the number of people at the buffet and the number of pieces of chicken Dr. Chaz is providing.

Output

Output a single line of the form “Dr. Chaz will have P piece[s] of chicken left over!”, if Dr. Chaz has enough chicken and P pieces of chicken will be left over, or “Dr. Chaz needs Q more piece[s] of chicken!”
if Dr. Chaz does not have enough pieces of chicken and needs Q more.

*/

package main

import "fmt"

func main() {
	assert(chicken(20, 100) == "Dr. Chaz will have 80 pieces of chicken left over!")
	assert(chicken(2, 3) == "Dr. Chaz will have 1 piece of chicken left over!")
	assert(chicken(10, 1) == "Dr. Chaz needs 9 more pieces of chicken!")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func chicken(n, m int) string {
	switch m -= n; {
	case m == 1:
		return fmt.Sprintf("Dr. Chaz will have 1 piece of chicken left over!")
	case m == -1:
		return fmt.Sprintf("Dr. Chaz needs 1 more piece of chicken!")
	case m < 0:
		return fmt.Sprintf("Dr. Chaz needs %d more pieces of chicken!", -m)
	}
	return fmt.Sprintf("Dr. Chaz will have %d pieces of chicken left over!", m)
}
