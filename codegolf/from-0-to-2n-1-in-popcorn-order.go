/*

... Ah sorry, no popcorn here, just POPCNT.

Write the shortest program or function which takes in a number n and output all integers from 0 to 2n - 1, in ascending order of number of 1 bits in the binary representation of the numbers (popcount). No duplicates allowed.

The order of numbers with the same popcount is implementation-defined.

For example, for n = 3, all these output are valid:

0, 1, 2, 4, 3, 5, 6, 7
[0, 4, 1, 2, 5, 3, 6, 7]
0 4 2 1 6 5 3 7
The input and output format are implementation-defined to allow the use of language features to further golf the code. There are a few restrictions on the output:

The numbers must be output in decimal format.
The output must contain a reasonable separator between the numbers (trailing separator allowed, but not leading).

Line feed (\n), tab (\t), space, ,, ., ;, |, -, _, / are quite reasonable separator. I don't mind additional spaces for pretty printing, but don't use letter or digits as separators.

The numbers and separators can be surrounded by [ ], { } or any array or list notation.
Don't print anything else not stated above.
Bonus
Multiply your score by 0.5 if your solution can generate the number on the fly.
The spirit of this bonus is that if you were to directly convert your printing solution to a generator, the generator only uses at most O(n) memory where n is the number of bits as defined above.
(You don't have to actually convert your solution to generator). Note that while I impose n <= 28, the memory needed to store all numbers still grows exponentially, and a naive sorting solution would hog up at least 4 GB of memory at n = 28.

Please add some simple explanation of how your solution works before claiming this bonus.

*/

package main

import (
	"fmt"
	"math/bits"
	"sort"
)

func main() {
	fmt.Println(gen(3))
}

func gen(n int) []int {
	l := 1 << n
	r := make([]int, l)
	p := make([][2]int, l)

	for i := 0; i < l; i++ {
		p[i][0] = i
		p[i][1] = bits.OnesCount(uint(i))
	}
	sort.SliceStable(p, func(i, j int) bool {
		return p[i][1] > p[j][1]
	})

	for i := range r {
		r[i] = p[l-i-1][0]
	}
	return r
}
