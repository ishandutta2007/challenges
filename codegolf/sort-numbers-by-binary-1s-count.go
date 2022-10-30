/*

Goal

Write a function or program sort an array of integers in descending order by the number of 1's present in their binary representation. No secondary sort condition is necessary.
Example sorted list

(using 16-bit integers)

  Dec                Bin        1's
16375   0011111111110111        13
15342   0011101111101110        11
32425   0111111010101001        10
11746   0010110111100010         8
28436   0000110111110100         8
19944   0100110111101000         8
28943   0000011100011111         8
 3944   0000011111101000         7
15752   0011110110001000         7
  825   0000000011111001         6
21826   0101010101000010         6

Input

An array of 32-bit integers.
Output

An array of the same integers sorted as described.
Scoring

This is code golf for the least number of bytes to be selected in one week's time.

*/

package main

import (
	"fmt"
	"math/bits"
	"sort"
)

func main() {
	fmt.Println(onesort([]uint32{21826, 825, 15752, 3944, 28943, 19944, 28436, 11746, 32425, 15342, 16375}))
}

func onesort(a []uint32) []uint32 {
	sort.SliceStable(a, func(i, j int) bool {
		return bits.OnesCount32(a[i]) >= bits.OnesCount32(a[j])
	})
	return a
}
