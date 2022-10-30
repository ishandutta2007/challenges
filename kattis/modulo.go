/*

Given two integers A and B, A modulo B is the remainder when dividing A by B. For example, the numbers 7, 14, 27 and 38 become 1, 2, 0 and 2, modulo 3.
Write a program that accepts 10 numbers as input and outputs the number of distinct numbers in the input, if the numbers are considered modulo 42.

Input

The input will contain 10 non-negative integers, each smaller than 1000, one per line.

Output

Output the number of distinct values when considered modulo 42 on a single line.

Explanation of Sample Inputs

In sample input 1, the numbers modulo 42 are 1,2,3,4,5,6,7,8,9 and 10.

In sample input 2, all numbers modulo 42 are 0.

In sample input 3, the numbers modulo 42 are 39,40,41,0,1,2,40,41,0 and 1. There are 6 distinct numbers.

*/

package main

func main() {
	assert(modulo([]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) == 10)
	assert(modulo([]int{42, 84, 252, 420, 840, 126, 42, 84, 420, 126}) == 1)
	assert(modulo([]int{39, 40, 41, 42, 43, 44, 82, 83, 84, 85}) == 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func modulo(a []int) int {
	m := make(map[int]bool)
	for _, v := range a {
		m[v%42] = true
	}
	return len(m)
}
