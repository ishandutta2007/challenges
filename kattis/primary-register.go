/*

We’re working on a new super-computer, built to unleash the hidden computing powers of all eight dimensions of reality.
The secret to utilizing more dimensions turns out to be to use counting registers of different sizes.
In particular, we have eight registers, counting cyclically modulo the different primes 2, 3, 5, 7, 11, 13, 17, 19.
A size p register stores a value between 0 and p−1 (inclusive).

The only operation available is an “increment” operation. When it is performed, the size 2 register is increased by 1.
If this increment causes overflow (i.e., if the old value was 1) the value is reset to 0, and the size 3 is incremented.
If this causes overflow the size 3 register is reset to 0 and the size 5 register is incremented, and so on.
If this goes all the way to the last register and the size 19 register overflows, the computer blows up.

In order not to destroy the computer in testing, we need to build a program to check the safety of doing increment operations before we perform them.
Given the current state of the registers, you need to compute how many more operations can safely be performed before the computer blows up.

Input

The input consists of a single line containing eight integers v2, v3, v5, v7, v11, v13, v17, v19 indicating the current values of the registers.
The value of the size p register is always between 0 and p−1 (inclusive).

Output

Ouput a single line containing an integer N, the number of additional operations that can be performed without the computer blowing up.

*/

package main

func main() {
	assert(operations([8]uint{0, 0, 4, 6, 10, 12, 16, 18}) == 5)
	assert(operations([8]uint{1, 2, 4, 6, 10, 12, 16, 18}) == 0)
	assert(operations([8]uint{0, 0, 0, 0, 0, 0, 0, 0}) == 9699689)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func operations(v [8]uint) uint {
	mod := []uint{2, 3, 5, 7, 11, 13, 17, 19}
	ln := []uint{1, 2, 1, 1, 1, 1, 1, 1}
	for i := 2; i < 8; i++ {
		for j := 0; j < i; j++ {
			ln[i] *= mod[j]
		}
	}

	r := uint(0)
	for i := range v {
		r += (mod[i] - 1 - v[i]) * ln[i]
	}
	return r
}
