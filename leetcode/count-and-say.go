/*

The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

To generate the nth term, just count and say the n-1th term.

*/

package main

import "fmt"

func main() {
	for i := 1; i <= 10; i++ {
		fmt.Println(i, countandsay(i))
	}
}

func countandsay(n int) string {
	if n <= 0 {
		return ""
	}

	s := "1"
	for i := 1; i < n; i++ {
		s += "$"
		t := ""
		c := 1
		for j := 1; j < len(s); j++ {
			if s[j] != s[j-1] {
				t += fmt.Sprintf("%d%c", c, s[j-1])
				c = 1
			} else {
				c++
			}
		}
		s = t
	}
	return s
}
