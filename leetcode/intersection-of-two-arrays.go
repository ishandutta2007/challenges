/*

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]

Note:
    Each element in the result must be unique.
    The result can be in any order.
*/

package main

import "fmt"

func main() {
	fmt.Println(intersect([]int{1, 2, 2, 1}, []int{2, 2}))
	fmt.Println(intersect([]int{4, 9, 5}, []int{9, 4, 9, 8, 4}))
}

func intersect(x, y []int) []int {
	m := make(map[int]uint8)
	for _, v := range x {
		m[v] = 1
	}

	var z []int
	for _, v := range y {
		if f := m[v]; f == 1 {
			z = append(z, v)
			m[v] = 2
		}
	}
	return z
}
