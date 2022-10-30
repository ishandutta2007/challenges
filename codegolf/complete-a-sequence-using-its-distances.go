/*

Given A=(a1,…,ak) k≥2

a sequence of positive integers, in which all elements are different.

Starting from i=2, while ai∈A:

(until the last element)

    If d=|ai−ai−1|

is not already in A, append d to A
Increase i

Output the completed sequence.

This is code-golf
Example

In:  16 21 11 2

     16 21 11 2 5
      --^
     16 21 11 2 5 10
         --^
     16 21 11 2 5 10 9
            --^
     16 21 11 2 5 10 9 3
              --^
     16 21 11 2 5 10 9 3
                --^
     16 21 11 2 5 10 9 3 1
                   --^
     16 21 11 2 5 10 9 3 1 6
                     --^
     16 21 11 2 5 10 9 3 1 6
                       --^
     16 21 11 2 5 10 9 3 1 6
                         --^
Out: 16 21 11 2 5 10 9 3 1 6

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{16, 21, 11, 2}, []int{16, 21, 11, 2, 5, 10, 9, 3, 1, 6})
}

func test(a, r []int) {
	p := seq(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func seq(a []int) []int {
	m := make(map[int]bool)
	for _, v := range a {
		m[v] = true
	}

	r := append([]int{}, a...)
	for i := 1; i < len(r); i++ {
		if d := abs(r[i] - r[i-1]); !m[d] {
			r, m[d] = append(r, d), true
		}
	}
	return r
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
