/*

In a letter to Lord Bowden in 1837, Charles Babbage asked, "What is the smallest positive integer whose square ends in 269,696?". He thought the answer was 99,736 whose square is 9,947,269,696. Was he right?

Write a function that takes a positive integer n and returns the smallest number whose square ends with n.
One small twist, if n == 269696 return "Babbage was correct!" if the smallest number whose square ends with 269,696 is 99,736, otherwise return "Babbage was incorrect!".

Examples

babbage(25) ➞ 5

babbage(161) ➞ 119
// 119 * 119 == 14,161
// Ends with 161

babbage(269696) ➞ "Babbage was {?}!"
// Replace {?} with the word "correct" or "incorrect".

Notes

	n will always be a positive integer n > 0.
	Make sure your solution is efficient enough to pass the tests within a 12 second time limit.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	assert(babbage(25) == 5)
	assert(babbage(161) == 119)
	assert(babbage(481) == 59)
	assert(babbage(7009) == 497)
	assert(babbage(990025) == 995)
	assert(babbage(327369) == 57213)
	assert(babbage(269696) == "Babbage was incorrect!")
	assert(babbage(33765625) == 28875)
	assert(babbage(314062500) == 36250)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func babbage(n int) interface{} {
	s := fmt.Sprint(n)
	for i := 0; i < n; i++ {
		t := fmt.Sprint(i * i)
		if !strings.HasSuffix(t, s) {
			continue
		}

		if n == 269696 {
			if i == 99736 {
				return "Babbage was correct!"
			}
			return "Babbage was incorrect!"
		}
		return i
	}

	return n
}
