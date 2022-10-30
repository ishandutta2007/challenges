/*

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.


*/

package main

import (
	"fmt"
	"image"
)

func main() {
	fmt.Println(count([]int{1, 2, 2, 3, 1}))
	fmt.Println(count([]int{1, 2, 2, 3, 1, 4, 2}))
	fmt.Println(count([]int{1, 5, 2, 3, 5, 4, 5, 6}))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func count(a []int) int {
	f := make(map[int]int)
	p := make(map[int]image.Point)
	l := 0
	for i, v := range a {
		f[v]++
		l = max(l, f[v])
		if f[v] == 1 {
			p[v] = image.Pt(i, i)
		} else {
			p[v] = image.Pt(p[v].X, i)
		}
	}

	d := len(a)
	for k, v := range f {
		if l == v {
			d = min(d, p[k].Y-p[k].X+1)
		}
	}
	return d
}
