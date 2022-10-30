/*

 You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.

Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.

Note:

    All elements in nums1 and nums2 are unique.
    The length of both nums1 and nums2 would not exceed 1000.

*/

package main

import "fmt"

func main() {
	fmt.Println(nextgreater([]int{4, 1, 2}, []int{1, 3, 4, 2}))
	fmt.Println(nextgreater([]int{2, 4}, []int{1, 2, 3, 4}))
}

func nextgreater(n1, n2 []int) []int {
	m := make(map[int]int)
	s := make([]int, 0, len(n2))
	for _, n := range n2 {
		for len(s) > 0 && s[len(s)-1] < n {
			m[s[len(s)-1]] = n
			s = s[:len(s)-1]
		}
		s = append(s, n)
	}

	r := make([]int, len(n1))
	for i := range r {
		r[i] = -1
		if n, ok := m[n1[i]]; ok {
			r[i] = n
		}
	}
	return r
}
