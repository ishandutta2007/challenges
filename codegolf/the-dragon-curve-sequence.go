/*

The dragon curve sequence (or the regular paper folding sequence) is a binary sequence. a(n) is given by negation of the bit left of the least significant 1 of n. For example to calculate a(2136) we first convert to binary:

100001011000
We find our least significant bit

100001011000
        ^
Take the bit to its left

100001011000
       ^
And return its negation

0

Task
Given a positive integer as input, output a(n). (You may output by integer or by boolean). You should aim to make your code as small as possible as measured by bytes.

Test Cases
Here are the first 100 entries in order

1 1 0 1 1 0 0 1 1 1 0 0 1 0 0 1 1 1 0 1 1 0 0 0 1 1 0 0 1 0 0 1 1 1 0 1 1 0 0 1 1 1 0 0 1 0 0 0 1 1 0 1 1 0 0 0 1 1 0 0 1 0 0 1 1 1 0 1 1 0 0 1 1 1 0 0 1 0 0 1 1 1 0 1 1 0 0 0 1 1 0 0 1 0 0 0 1 1 0 1

*/

package main

func main() {
	tab := []uint{
		1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0,
		0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0,
		1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1,
		0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0,
		1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0,
		0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1,
		1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1,
		0, 1,
	}
	for i, v := range tab {
		assert(dragon(uint(i+1)) == v)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// http://oeis.org/A014577
func dragon(n uint) uint {
	n &= lowestone(n) << 1
	if n == 0 {
		return 1
	}
	return 0
}

func lowestone(n uint) uint {
	return n & -n
}
