/*

Given a binary number (of N bits) X. Find the highest power of 2 that divides this number.

Note: If the binary number is "100" then the highest power of 2 that divides it is 2 (as 22 = 4)

Input:

The first line contains N the number of bits in the number
The next line contains a binary number of N bits

Output:

The first and only line contains the max power of 2 that divides the given number

Constraints:
1≤N≤10^5
1≤X

*/

package main

import "fmt"

func main() {
	assert(maxpow2("100") == 2)
	assert(maxpow2("10100") == 2)
	assert(maxpow2("100000") == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxpow2(s string) int {
	var n, p int
	_, err := fmt.Sscanf(s, "%b", &n)
	if err != nil {
		return -1
	}

	for ; n&1 == 0; n >>= 1 {
		p++
	}
	return p
}
