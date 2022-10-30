/*

Pretty simple challenge today:

Write a program or function that takes in a positive integer N and prints or returns a sorted list of the unique numbers that appear in the multiplication table whose row and column multiplicands both range from 1 to N inclusive.

The list may be sorted in ascending order (smallest to largest) or descending order (largest to smallest), and may be output in any reasonable format.

The shortest code in bytes wins!

Example

When N = 4, the multiplication table looks like:

   1  2  3  4
  -----------
1| 1  2  3  4
 |
2| 2  4  6  8
 |
3| 3  6  9 12
 |
4| 4  8 12 16
The unique numbers in the table are 1, 2, 3, 4, 6, 8, 9, 12, 16. These are already sorted, so

1, 2, 3, 4, 6, 8, 9, 12, 16
might be your exact output for N = 4. But since the sorting can be reversed and there's some leeway in the formatting, these would also be valid outputs:

[16,12,9,8,6,4,3,2,1]
1
2
3
4
6
8
9
12
16
16 12 9 8 4 3 2 1
Test Cases
N=1 -> [1]
N=2 -> [1, 2, 4]
N=3 -> [1, 2, 3, 4, 6, 9]
N=4 -> [1, 2, 3, 4, 6, 8, 9, 12, 16]
N=5 -> [1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 20, 25]
N=6 -> [1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24, 25, 30, 36]
N=7 -> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 28, 30, 35, 36, 42, 49]
N=8 -> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 28, 30, 32, 35, 36, 40, 42, 48, 49, 56, 64]
N=9 -> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27, 28, 30, 32, 35, 36, 40, 42, 45, 48, 49, 54, 56, 63, 64, 72, 81]
N=10 -> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27, 28, 30, 32, 35, 36, 40, 42, 45, 48, 49, 50, 54, 56, 60, 63, 64, 70, 72, 80, 81, 90, 100]
N=11 -> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 18, 20, 21, 22, 24, 25, 27, 28, 30, 32, 33, 35, 36, 40, 42, 44, 45, 48, 49, 50, 54, 55, 56, 60, 63, 64, 66, 70, 72, 77, 80, 81, 88, 90, 99, 100, 110, 121]
N=12 -> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 18, 20, 21, 22, 24, 25, 27, 28, 30, 32, 33, 35, 36, 40, 42, 44, 45, 48, 49, 50, 54, 55, 56, 60, 63, 64, 66, 70, 72, 77, 80, 81, 84, 88, 90, 96, 99, 100, 108, 110, 120, 121, 132, 144]

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test(1, []int{1})
	test(2, []int{1, 2, 4})
	test(3, []int{1, 2, 3, 4, 6, 9})
	test(4, []int{1, 2, 3, 4, 6, 8, 9, 12, 16})
	test(5, []int{1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 20, 25})
	test(6, []int{1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24, 25, 30, 36})
	test(7, []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 28, 30, 35, 36, 42, 49})
	test(8, []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 28, 30, 32, 35, 36, 40, 42, 48, 49, 56, 64})
	test(9, []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27, 28, 30, 32, 35, 36, 40, 42, 45, 48, 49, 54, 56, 63, 64, 72, 81})
	test(10, []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27, 28, 30, 32, 35, 36, 40, 42, 45, 48, 49, 50, 54, 56, 60, 63, 64, 70, 72, 80, 81, 90, 100})
	test(11, []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 18, 20, 21, 22, 24, 25, 27, 28, 30, 32, 33, 35, 36, 40, 42, 44, 45, 48, 49, 50, 54, 55, 56, 60, 63, 64, 66, 70, 72, 77, 80, 81, 88, 90, 99, 100, 110, 121})
	test(12, []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 18, 20, 21, 22, 24, 25, 27, 28, 30, 32, 33, 35, 36, 40, 42, 44, 45, 48, 49, 50, 54, 55, 56, 60, 63, 64, 66, 70, 72, 77, 80, 81, 84, 88, 90, 96, 99, 100, 108, 110, 120, 121, 132, 144})
}

func test(n int, r []int) {
	p := gen(n)
	fmt.Println(n, p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen(n int) []int {
	p := make([]int, 0, n*n)
	m := make(map[int]bool)
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			if v := i * j; !m[v] {
				p = append(p, v)
				m[v] = true
			}
		}
	}
	sort.Ints(p)
	return p
}
