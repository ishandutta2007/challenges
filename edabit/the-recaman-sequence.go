/*

The Recamán Sequence is a numeric sequence that starts always with 0. The position of a positive integer in the sequence, or Recamán Index, can be established with the following algorithm:

    For every number to find, two variables are considered: the value of the last element of the sequence (last element from now on), and the actual sequence length (length from now on).
    If the subtraction of the length from the last element returns a number greater than 0 and not already present in the sequence, it is added to the sequence.
    When the conditions of the above statement are not met, will be added always the sum of the last element plus the length (even if it is a number already present in the sequence).
    Repeat until the number of interest is found.

Look at example below for the steps to do for to establish the Recamán Index of number 2:

Sequence = [0]

Last - Length = 0 - 1 = -1 (lower than zero)
Last + Length = 0 + 1 = 1

Sequence = [0, 1]

Last - Length = 1 - 2 = -1 (lower than 0)
Last + Length = 1 + 2 = 3

Sequence = [0, 1, 3]

Last - Length = 3 - 3 = 0 (already present in sequence)
Last + Length = 3 + 3 = 6

Sequence = [0, 1, 3, 6]

Last - Length = 6 - 4 = 2 (greater than 0 and not already in sequence)

Sequence = [0, 1, 3, 6, 2]

// The Recaman Index of 2 is: 4

Given a positive integer n, implement a function that returns its Recamán Index.
Examples

recamanIndex(2) ➞ 4

recamanIndex(3) ➞ 2

recamanIndex(7) ➞ 5

Notes

    The sequence starts always with 0.
    The step with the subtraction Last Element - Sequence Length (verifying that is not already present in the sequence) has the precedence over the second step.
    Remember: if the number to add is the result of a subtraction it can't be already in the sequence (first step), if it is the result of an addition it can be already present (second step).
    Curiosity: the first number to repeat in the sequence is 42...
    Curiosity: the first number with a BIG delay in the sequence is 19.

*/

package main

import (
	"math"
)

func main() {
	assert(recamanindex(2) == 4)
	assert(recamanindex(3) == 2)
	assert(recamanindex(7) == 5)
	assert(recamanindex(20) == 7)
	assert(recamanindex(56) == 204)
	assert(recamanindex(100) == 387)
	assert(recamanindex(666) == 2292)
	assert(recamanindex(1000) == 4419)
	assert(recamanindex(10000) == 7215)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var (
	terms = map[uint]uint{0: 0}
	vals  = map[uint]uint{0: 0}
	inds  = map[uint]int{}
)

func recaman(n uint) uint {
	if r, f := terms[n]; f {
		return r
	}

	v := recaman(n - 1)
	r := v + n
	if v > n {
		if _, f := vals[v-n]; !f {
			r = v - n
		}
	}

	terms[n] = r
	vals[r] = n
	return r
}

func recamanindex(n uint) int {
	if i, f := inds[n]; f {
		return i
	}

	for i := 0; i < math.MaxInt32; i++ {
		inds[recaman(uint(i))] = i
		if _, f := inds[n]; f {
			return i
		}
	}
	return -1
}
