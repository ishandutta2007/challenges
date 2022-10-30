/*

Description

In mathematics, the Baum–Sweet sequence is an infinite automatic sequence of 0s and 1s defined by the rule:

    b_n = 1 if the binary representation of n contains no block of consecutive 0s of odd length;
    b_n = 0 otherwise;

for n >= 0.

For example, b_4 = 1 because the binary representation of 4 is 100, which only contains one block of consecutive 0s of length 2;
whereas b_5 = 0 because the binary representation of 5 is 101, which contains a block of consecutive 0s of length 1.
When n is 19611206, b_n is 0 because:

19611206 = 1001010110011111001000110 base 2
            00 0 0  00     00 000  0 runs of 0s
               ^ ^            ^^^    odd length sequences

Because we find an odd length sequence of 0s, b_n is 0.
Challenge Description

Your challenge today is to write a program that generates the Baum-Sweet sequence from 0 to some number n. For example, given "20" your program would emit:

1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0

*/

package main

import "fmt"

func main() {
	tab := []int{
		1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0,
	}

	for i := range tab {
		assert(baumsweet(i) == tab[i])
	}
	assert(baumsweet(19611206) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func baumsweet(n int) int {
	if n == 0 {
		return 1
	}

	b := fmt.Sprintf("%b", n)
	for i := 0; i < len(b); {
		if b[i] != '0' {
			i++
			continue
		}

		c := 0
		for ; i < len(b) && b[i] == '0'; i++ {
			c++
		}
		if c&1 != 0 {
			return 0
		}
	}

	return 1
}
