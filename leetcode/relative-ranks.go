/*

Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Note:

    N is a positive integer and won't exceed 10,000.
    All the scores of athletes are guaranteed to be unique.


*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(ranks([]int{5, 4, 3, 2, 1}))
	fmt.Println(ranks([]int{5, 4, 3, 2, 1, 342, 21, 7, 8, 100}))
}

func ranks(a []int) []string {
	p := make([][2]int, len(a))
	for i := range a {
		p[i][0] = a[i]
		p[i][1] = i
	}
	sort.SliceStable(p, func(i, j int) bool {
		return p[i][0] > p[j][0]
	})

	r := make([]string, len(a))
	for i := range p {
		switch i {
		case 0:
			r[p[i][1]] = `"Gold Medal"`
		case 1:
			r[p[i][1]] = `"Silver Medal"`
		case 2:
			r[p[i][1]] = `"Bronze Medal"`
		default:
			r[p[i][1]] = fmt.Sprintf("\"%v\"", i+1)
		}
	}
	return r
}
