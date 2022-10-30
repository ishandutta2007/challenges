/*

The pigeonhole principle states that

    If N items are put into M boxes, with N > M, then at least one box must contain more than one item.

For many, this principle has a special status compared to other mathematical enouncements. As E.W. Dijkstra wrote,

    It is surrounded by some mystique. Proofs using it are often regarded as something special, something particularly ingenious.

The challenge

The purpose of this challenge is to illustrate the pigeonhole principle using ASCII art representations. Specifically:

    Take as input N (number of items) and M (number of boxes), with N non-negative and M positive. N may be smaller than M (even if the principle does not apply in that case).
    Randomly select one of the possible assignments of items to boxes. Each assignment should have a non-zero probability of being picked.

    Produce an ASCII art representation of the assignment as follows:
        There are M lines, each corresponding to a box.
        Each line starts with a non-whitespace character, such as |.
        Following that character is another non-whitespace character, such as #, repeated as many times as there are items in that box.

Consider for example N = 8, M = 5. If the selected assigment of items to boxes is 4, 1, 0, 3, 0, the representation is

|####
|#
|
|###
|

A different run (resulting in a different assignment) of the same program could give

|#
|##
|#
|#
|###

There is some flexibility regarding the representation; see below.
Specific rules

The code should theoretically run for any values of N and M. In practice it may be restricted by memory size or data type limitations.

Since observing the output is not sufficient to determine if all assignments have non-zero probability, each submission should explain how the code achieves that, if not obvious.

The following representation variations are allowed:

    Any pair of different, non-whitespace characters can be chosen. They must be consistent across program executions.
    90-degree rotations of the representation are acceptable. Again, the choice must be consistent.
    Trailing or leading whitespace is allowed.

As an example with a different representation format, for N = 15, M = 6 the results of two executions of the program could be

VVVVVV
@@@@@@
@@ @@@
 @  @@
    @

or

VVVVV
@@@ @
@@@ @
@ @ @
@ @ @
@

Likewise, N = 5, M = 7 could give, using another variation of the representation,

  *
* * * *
UUUUUUU

or

 *** **
UUUUUUU

or

   *
*  *
*  *
UUUUUUU

Note how the principle is not applicable in this case, because N <M.
General rules

Programs or functions are allowed, in any programming language. Standard loopholes are forbidden.

Input can be taken by any reasonable means; and with any format, such as an array of two numbers or two different strings.

Output means and format are also flexible. For example, the output can be a list of strings or a string with newlines; returned as function output argument or displayed in STDOUT. In the latter case it is not necessary to worry about line wrapping caused by limited display width.

Shortest code in bytes wins.

*/

package main

import (
	"fmt"
	"math/rand"
	"strings"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	pigeonhole(8, 5)
}

func pigeonhole(n, m int) {
	b := make([]int, m)
	for i := 0; i < n; i++ {
		j := rand.Intn(m)
		b[j]++
	}

	for i := 0; i < m; i++ {
		fmt.Printf("|%s\n", strings.Repeat("#", b[i]))
	}
	fmt.Printf("\n")
}
