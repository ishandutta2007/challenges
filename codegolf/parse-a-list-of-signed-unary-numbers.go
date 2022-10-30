/*

Unary numbers typically only represent nonnegative integers, but we can extend them to represent all integers as follows:

A positive integer N is represented as N 1's: 5 -> 11111
A negative integer -N is represented as a 0 followed by N 1's: -5 -> 011111
Zero is represented as 0
We can then represent a list of these numbers unambiguously if we use 0 as the separator:

3,-2,0,1
111,011,0,1
111 0 011 0 0 0 1
11100110001
Your task: take a string representing such a list of signed unary numbers, and translate it into a list of decimal numbers.

Details
You may assume that the input is a complete list of signed unary numbers. In particular, your program will not have to handle 1) empty input or 2) input that ends with a separator.

You may assume that the magnitude of each number will not exceed 127.
For languages with maximum sizes of strings or lists, you may assume that the input and output will fit in your language's data structures, but your algorithm should theoretically work for a list of any size.

Your program or function may perform I/O in any of the standard ways. Input may be a string or a list of characters, single-character strings, integers, or booleans.
You may use any two characters to represent 1 and 0; if you don't use 1 and 0, please specify which characters you're using.

Output must be decimal numbers in any reasonable list format (in particular, there must be some kind of a separator between numbers).
Negative numbers should be indicated with a minus sign, although if your language has a different format for negative integers I will also accept that.
Zero may be represented in the output as 0 or -0.

Test cases
1 -> 1
0 -> 0 (or -0, and similarly for the other test cases)
011 -> -2
1101 -> 2,1
1100 -> 2,0
11001 -> 2,-1
110001 -> 2,0,1
11100110001 -> 3,-2,0,1
00000001 -> 0,0,0,-1
01111011111111001111111111111110111111111111111100111111111111111111111110111111111111111111111111111111111111111111 -> -4,8,-15,16,-23,42
01111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111 -> -127

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test("1", []int{1})
	test("0", []int{0})
	test("011", []int{-2})
	test("1101", []int{2, 1})
	test("1100", []int{2, 0})
	test("11001", []int{2, -1})
	test("110001", []int{2, 0, 1})
	test("11100110001", []int{3, -2, 0, 1})
	test("00000001", []int{0, 0, 0, -1})
	test("01111011111111001111111111111110111111111111111100111111111111111111111110111111111111111111111111111111111111111111", []int{-4, 8, -15, 16, -23, 42})
	test("01111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111", []int{-127})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []int) {
	p := unaries(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func unaries(s string) []int {
	r := []int{}
	n := len(s)
	for i := 0; i < n; i++ {
		g, x := 1, 0
		if s[i] == '0' {
			g, i = -1, i+1
		}
		for ; i < n && s[i] == '1'; i++ {
			x++
		}
		r = append(r, g*x)
	}
	return r
}
