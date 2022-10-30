/*

Fox Mithra has finally learned the numbers and he is now familiar with the concept
of ‘one’, ’two’, ‘three’ and also even ‘zero’, ‘minus one’, ‘minus two’ and so on.
Really, an achievement for such a small fox.
He took the textbook and copied the integers from the book one by one from the smallest to the biggest on the wall of his enclosure in the ZOO.

“Look, there is something wrong with your sequence on the wall”, said the owl who just landed on the branch above Mithra’s head.
“You should put 30 between 20 and 22, there.”

“Why?”

“Because the importance of a number is judged by the sum of its digits. 30 is therefore less important than 22 and it is more important than 20.
And obviously, 30 should be equally close to 20 and 22 because its sum of digits differs only by one from both 20 and 22.”

“I see,” replied Mithra, “you are really clever. Can you help me please to rearrange the sequence correctly?
Each time I tell you a number N you will tell me the closest smaller number with sum of digits less by one than the sum of digits of N.”

“With pleasure,” nodded the owl majestically.

Your task is to imitate the owl’s task. Given an integer N you have to find the biggest integer which is
smaller than N with sum of digits less by one than the sum of digits of N.

Input

The first line of input contains the number of test cases T
(1≤T≤100000). The descriptions of the test cases follow:

Each case consists of a line containing a single integer N
(1≤N≤100000).

Output

For each test case print on a separate line the number demanded by fox Mithra.

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	assert(number(30) == 20)
	assert(number(199) == 198)
	assert(number(1000) == 0)
	assert(number(1520) == 1510)
	assert(number(0) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func number(n int) int {
	b := []byte(fmt.Sprint(n))
	i := len(b) - 1
	for i >= 0 && b[i] == '0' {
		i--
	}
	if i >= 0 {
		b[i]--
	}

	r, _ := strconv.Atoi(string(b))
	return r
}
