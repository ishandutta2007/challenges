/*

Out of all of mathematics, there will always be a few theorems that go beyond all common sense. One of these is the fact that there are different sizes of infinity.
Another interesting fact is the idea that many infinities which seem to be of different size are actually of the same size. There are just as many even numbers as integers, as there are rational numbers.

The general concept of this question is to confront the bizarre reality of infinity. In this challenge, your program will output a list which will:

    At any specific moment of time, always have a whole number of entries
    Eventually contain (if left to run long enough) any specific (non-zero) rational number precisely once on the entire list
    Contain an unbounded number of empty slots (entries on the list that are needlessly set to 0)
    Have a proportion of empty slots that approaches a limit of 100%
    For every positive integer N, have an infinite number of places with N consecutive empty slots

The Challenge

Your challenge is to write that shortest possible program that will output a special list with the following rules:

    All entries with an index that is not a square number should be set to zero. So, the first entry will be nonzero, the second and third will be zero, the fourth will nonzero, etc.
    All rational numbers will be in the form of an improper fraction (such as 4/5 or 144/13) that has been simplified. The exception is zeroes, which will be simply 0.
    All (positive and negative) rational numbers should eventually appear on the list if your program runs for long enough and with enough memory. For any particular rational number, the time required may be an arbitrarily large, but always finite, amount of time.
    If run for an infinite amount of time, no non-zero rational number should ever appear twice.

Rule 3 does allow for some variation, as in there is an infinite number of different possible legal outputs.

Output will be a stream of lines. Each line will be of the general form of 5: 2/3 where the first number is the entry number, then followed by the rational number. Note that 1: 0 will always be the first line of output.
Example snippet of output:

1: 1/1
2: 0
3: 0
4: 2/1
5: 0
6: 0
7: 0
8: 0
9: -2/1
10: 0
etc...

Rules, Regulations, and Notes

This is code golf. Standard code golf rules apply. Also, due to the variation allowed in the output, you need to at least show why you believe that your list will contain all possible rational numbers exactly once, and that your solution is correct.

EDIT: Since the primes numbers did distract from the challenge, I am changing it to square numbers. This accomplishes the same purpose, and also shortens the solutions.


*/

package main

import "fmt"

func main() {
	rationals(10000)
}

func rationals(n int) {
	sd := new(SD)
	sd.Init()
	sd.Next()

	a := sd.Next()
	b := sd.Next()
	for i := 1; i <= n; i++ {
		if i&1 == 1 {
			fmt.Printf("%v: %v/%v\n", i*i, a, b)
		} else {
			fmt.Printf("%v: -%v/%v\n", i*i, a, b)
			a, b = b, sd.Next()
		}
	}
}

// https://en.wikipedia.org/wiki/Calkin%E2%80%93Wilf_tree
// https://www.geeksforgeeks.org/find-n-th-element-from-sterns-diatomic-series/
// https://oeis.org/A002487
type SD struct {
	vals  []int
	index int
}

func (c *SD) Init() {
	c.vals = []int{0, 1}
	c.index = 0
}

func (c *SD) Next() int {
	if c.index >= len(c.vals) {
		c.vals = append(c.vals, make([]int, 10000)...)
		for i := c.index; i < len(c.vals); i++ {
			if i%2 == 0 {
				c.vals[i] = c.vals[i/2]
			} else {
				c.vals[i] = c.vals[(i-1)/2] + c.vals[(i+1)/2]
			}
		}
	}

	v := c.vals[c.index]
	c.index++
	return v
}
