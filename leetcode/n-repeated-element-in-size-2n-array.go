/*

In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.

*/

package main

import "fmt"

func main() {
	fmt.Println(repeated([]int{1, 2, 3, 3}))
	fmt.Println(repeated([]int{2, 1, 2, 5, 3, 2}))
	fmt.Println(repeated([]int{5, 1, 5, 2, 5, 3, 5, 4}))
}

func repeated(a []int) int {
	m := make(map[int]int)
	for _, v := range a {
		if m[v]++; m[v] == len(a)/2 {
			return v
		}
	}
	return 0
}
