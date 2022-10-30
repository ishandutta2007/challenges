/*

Check out the resources on the page's right side to learn more about recursion and memoization. The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book Cracking the Coding Interview.

Davis has a number of staircases in his house and he likes to climb each staircase 1, 2, or 3 steps at a time.
Being a very precocious child, he wonders how many ways there are to reach the top of the staircase.

Given the respective heights for each of the s staircases in his house,
find and print the number of ways he can climb each staircase, module 10^9 + 7 on a new line.

For example, there is s=1 staircase in the house that is n=5 steps high. Davis can step on the following sequences of steps:

1 1 1 1 1
1 1 1 2
1 1 2 1
1 2 1 1
2 1 1 1
1 2 2
2 2 1
2 1 2
1 1 3
1 3 1
3 1 1
2 3
3 2

There are 13 possible ways he can take these steps. 13%10000000007=13

*/
package main

import "fmt"

func main() {
	fmt.Println(ways(5))
	fmt.Println(ways(1))
	fmt.Println(ways(3))
	fmt.Println(ways(7))
}

func ways(h int) int {
	m := 10000000007
	a, b, c, r := 0, 0, 1, 0
	for i := 0; i < h; i++ {
		r = ((a % m) + (b % m) + (c % m)) % m
		a = b
		b = c
		c = r
	}
	return r
}
