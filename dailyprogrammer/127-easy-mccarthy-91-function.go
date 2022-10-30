/*

(Easy): McCarthy 91 Function

 The McCarthy 91 Function is a recursive function which, given an integer N, returns the integer 91 if N is equal to or smaller than 100, or simply N-10 if N is greater than 100.
 Sounds simple, but look at the function definition in the linked Wikipedia article! How could such a function work to always return a constant (for N <= 100) that isn't in the function body?
 Well, that's your task: write out each step that McCarthy's function does for a given integer N.

 Author: nint22
 Formal Inputs & Outputs
 Input Description

 You will be given a single integer N on standard console input. This integer will range between 0 and 2,147,483,647 (without commas).
 Output Description

 You must output what the function does on each recursion: first you must print the function the expression that is being computed, and then print which condition it took.
 Simply put, you must print each recursion event in the following string format: "<Expression being executed> since <is greater than | is equal to or less than> 100".
 Note that for the first line you do not need to print the "since" string (see example below).
 You should also print the final expression, which is the result (which should always be 91).

 Sample Inputs & Outputs

 Sample Input

 Note: Take from Wikipedia for the sake of keeping things as simple and clear as possible.

 99

 Sample Output

 M(99)
 M(M(110)) since 99 is equal to or less than 100
 M(100) since 110 is greater than 100
 M(M(111)) since 100 is equal to or less than 100
 M(101) since 111 is greater than 100
 91 since 101 is greater than 100
 91

*/
package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	for {
		fmt.Printf("Enter a number: ")
		_, err := fmt.Scan(&n)
		if err != nil {
			break
		}
		if n < 0 || n > math.MaxInt32 {
			fmt.Printf("Invalid number! Try again!\n\n")
			continue
		}
		break
	}
	c := mc91{}
	c.trace(n)
}

type mc91 struct {
	depth int
	prev  int
}

func (c *mc91) trace(n int) {
	c.depth = 0
	c.prev = -1
	v := c.m(n)
	fmt.Printf("%d", v)
	c.pn()
	fmt.Println(v)
}

func (c *mc91) pn() {
	if c.prev >= 0 {
		if c.prev <= 100 {
			fmt.Printf(" since %d is equal to or less than 100", c.prev)
		} else {
			fmt.Printf(" since %d is greater than 100", c.prev)
		}
	}
	fmt.Printf("\n")
}

func (c *mc91) p(d, v int) {
	if d < 0 {
		d = 0
	}
	for i := 0; i <= d; i++ {
		fmt.Printf("M(")
	}
	fmt.Printf("%d", v)
	for i := 0; i <= d; i++ {
		fmt.Printf(")")
	}
	c.pn()
}

func (c *mc91) m(n int) int {
	c.p(c.depth, n)
	c.prev = n
	if n > 100 {
		c.depth--
		return n - 10
	} else {
		c.depth++
		n = c.m(c.m(n + 11))
		c.depth--
		return n
	}
}
