/*

You're given a non-empty list of positive integers, e.g.

[6 2 9 7 2 6 5 3 3 4]

You should rank these numbers by their value, but as is usual in leaderboards, if there is a tie then all the tied numbers get the same rank, and an appropriate number of ranks is skipped. The expected output for the above list would therefore be

[3 9 1 2 9 3 5 7 7 6]

For example, the highest value in the input was 9, so this becomes a 1 (first rank). The third highest value is 6, so both 6s become 3, and the rank 4 is skipped entirely.

Rules
You can use any convenient, unambiguous, flat list format for input and output. The first/smallest rank in the output should always be 1.

You may write a program or a function and use any of the our standard methods of receiving input and providing output.

You may use any programming language, but note that these loopholes are forbidden by default.

This is code-golf, so the shortest valid answer – measured in bytes – wins.

Test Cases
[8] -> [1]
[1 15] -> [2 1]
[18 14 11] -> [1 2 3]
[11 16 14 8] -> [3 1 2 4]
[15 15 15 15 15] -> [1 1 1 1 1]
[10 2 5 4 15 5] -> [2 6 3 5 1 3]
[5 5 10 10 5 11 18] -> [5 5 3 3 5 2 1]
[2 4 9 4 17 9 17 16] -> [8 6 4 6 1 4 1 3]
[11 17 19 17 10 10 15 3 18] -> [6 3 1 3 7 7 5 9 2]
[2 11 4 8 3 3 12 20 4 18] -> [10 4 6 5 8 8 3 1 6 2]
[12 6 10 2 19 19 6 19 8 6 18] -> [5 8 6 11 1 1 8 1 7 8 4]
[5 6 14 19 13 5 19 9 19 9 9 19] -> [11 10 5 1 6 11 1 7 1 7 7 1]
[9 2 12 3 7 11 15 11 6 8 11 17 11] -> [8 13 3 12 10 4 2 4 11 9 4 1 4]
[3 5 15 7 18 5 3 9 11 2 18 1 10 19] -> [11 9 4 8 2 9 11 7 5 13 2 14 6 1]
[6 11 4 19 14 7 13 16 10 12 7 9 7 10 10] -> [14 6 15 1 3 11 4 2 7 5 11 10 11 7 7]
[11 20 11 1 20 16 11 11 4 8 9 7 11 14 10 14] -> [6 1 6 16 1 3 6 6 15 13 12 14 6 4 11 4]
[4 7 15 2 3 2 3 1 14 2 10 4 7 6 11 2 18] -> [9 6 2 13 11 13 11 17 3 13 5 9 6 8 4 13 1]
[5 1 17 7 1 9 3 6 9 7 6 3 2 18 14 4 18 16] -> [12 17 3 8 17 6 14 10 6 8 10 14 16 1 5 13 1 4]
[5 6 8 10 18 13 20 10 7 1 8 19 20 10 10 18 7 2 1] -> [16 15 11 7 4 6 1 7 13 18 11 3 1 7 7 4 13 17 18]
[12 17 8 2 9 7 15 6 19 5 13 16 14 20 10 11 18 4 3 1] -> [9 4 13 19 12 14 6 15 2 16 8 5 7 1 11 10 3 17 18 20]

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]int{6, 2, 9, 7, 2, 6, 5, 3, 3, 4}, []int{3, 9, 1, 2, 9, 3, 5, 7, 7, 6})
	test([]int{8}, []int{1})
	test([]int{1, 15}, []int{2, 1})
	test([]int{18, 14, 11}, []int{1, 2, 3})
	test([]int{15, 15, 15, 15, 15}, []int{1, 1, 1, 1, 1})
	test([]int{10, 2, 5, 4, 15, 5}, []int{2, 6, 3, 5, 1, 3})
	test([]int{5, 5, 10, 10, 5, 11, 18}, []int{5, 5, 3, 3, 5, 2, 1})
	test([]int{2, 4, 9, 4, 17, 9, 17, 16}, []int{8, 6, 4, 6, 1, 4, 1, 3})
	test([]int{11, 17, 19, 17, 10, 10, 15, 3, 18}, []int{6, 3, 1, 3, 7, 7, 5, 9, 2})
	test([]int{2, 11, 4, 8, 3, 3, 12, 20, 4, 18}, []int{10, 4, 6, 5, 8, 8, 3, 1, 6, 2})
	test([]int{12, 6, 10, 2, 19, 19, 6, 19, 8, 6, 18}, []int{5, 8, 6, 11, 1, 1, 8, 1, 7, 8, 4})
	test([]int{5, 6, 14, 19, 13, 5, 19, 9, 19, 9, 9, 19}, []int{11, 10, 5, 1, 6, 11, 1, 7, 1, 7, 7, 1})
	test([]int{9, 2, 12, 3, 7, 11, 15, 11, 6, 8, 11, 17, 11}, []int{8, 13, 3, 12, 10, 4, 2, 4, 11, 9, 4, 1, 4})
	test([]int{3, 5, 15, 7, 18, 5, 3, 9, 11, 2, 18, 1, 10, 19}, []int{11, 9, 4, 8, 2, 9, 11, 7, 5, 13, 2, 14, 6, 1})
	test([]int{6, 11, 4, 19, 14, 7, 13, 16, 10, 12, 7, 9, 7, 10, 10}, []int{14, 6, 15, 1, 3, 11, 4, 2, 7, 5, 11, 10, 11, 7, 7})
	test([]int{11, 20, 11, 1, 20, 16, 11, 11, 4, 8, 9, 7, 11, 14, 10, 14}, []int{6, 1, 6, 16, 1, 3, 6, 6, 15, 13, 12, 14, 6, 4, 11, 4})
	test([]int{4, 7, 15, 2, 3, 2, 3, 1, 14, 2, 10, 4, 7, 6, 11, 2, 18}, []int{9, 6, 2, 13, 11, 13, 11, 17, 3, 13, 5, 9, 6, 8, 4, 13, 1})
	test([]int{5, 1, 17, 7, 1, 9, 3, 6, 9, 7, 6, 3, 2, 18, 14, 4, 18, 16}, []int{12, 17, 3, 8, 17, 6, 14, 10, 6, 8, 10, 14, 16, 1, 5, 13, 1, 4})
	test([]int{5, 6, 8, 10, 18, 13, 20, 10, 7, 1, 8, 19, 20, 10, 10, 18, 7, 2, 1}, []int{16, 15, 11, 7, 4, 6, 1, 7, 13, 18, 11, 3, 1, 7, 7, 4, 13, 17, 18})
	test([]int{12, 17, 8, 2, 9, 7, 15, 6, 19, 5, 13, 16, 14, 20, 10, 11, 18, 4, 3, 1}, []int{9, 4, 13, 19, 12, 14, 6, 15, 2, 16, 8, 5, 7, 1, 11, 10, 3, 17, 18, 20})
}

func test(a, r []int) {
	p := rank(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func rank(a []int) []int {
	p := append([]int{}, a...)
	sort.Slice(p, func(i, j int) bool {
		return p[i] > p[j]
	})

	m := make(map[int]int)
	n := len(p)
	c := 1
	for i := 0; i < n; {
		j := i
		for j < n && p[i] == p[j] {
			m[p[i]], j = c, j+1
		}
		c, i = c+j-i, j
	}

	for i, v := range a {
		p[i] = m[v]
	}

	return p
}
