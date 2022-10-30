/*

In almost every row nowadays, the people tends to order themselves as militaries would do.
Challenge

Suppose 4 people where:

    person 1 has priority against person 2, 3 and 4,
    person 2 has priority against person 3 and 4,
    person 3 has priority against person 4,
    person 4 has the lowest priority.

Then, when ordering those 1...4 people in a row, the possibilities are:

1
2
3
4
1 2
1 3
1 4
2 3
2 4
3 4
1 2 3
1 2 4
1 3 4
2 3 4
1 2 3 4

Your mission is:

Given as input the number N of people. Output all the possibilities for 1...N people in the military order.

Since this is code-golf, then the shotest answer in bytes wins!

Input can be integer or string, followed by optional newline/whitespace, or an argument to your function. You can assume 1<=N<=10.

The output should be every sequence in a row, in any order. For each row, output a list/array or any other valid way for the numbers in military order.

*/

package main

import (
	"fmt"
	"math/bits"
)

func main() {
	fmt.Println(milord(4))
}

func milord(n uint) [][]uint {
	var r [][]uint
	for i := uint(1); i < 1<<n; i++ {
		var p []uint
		for b := i; b != 0; b &= (b - 1) {
			v := 1 + uint(bits.TrailingZeros(b))
			p = append(p, v)
		}
		r = append(r, p)
	}
	return r
}
