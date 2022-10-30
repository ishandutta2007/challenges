/*

A ship has to transport cargo from one place to another, while picking up cargo along the way.
Given the total amount of cargo and the types of cargo holds in the ship as arrays, create a function that returns true if each weight of cargo can fit in one hold, and false if it can't.

    "S" means 50 cargo space.
    "M" means 100 cargo space.
    "L" means 200 cargo space.

Examples

willFit(["M", "L", "L", "M"], [56, 62, 84, 90]) ➞ true

willFit(["S", "S", "S", "S", "L"], [40, 50, 60, 70 , 80, 90, 200]) ➞ false

willFit(["L", "L", "M"], [56, 62, 84, 90]) ➞ true

Notes

N/A

*/

package main

import "sort"

func main() {
	assert(fit([]string{"M", "L", "L", "M"}, []int{56, 62, 84, 90}) == true)
	assert(fit([]string{"L", "L", "M"}, []int{56, 62, 84, 90}) == true)
	assert(fit([]string{"S", "S", "S", "S", "L"}, []int{40, 50, 60, 70, 80, 90, 200}) == false)
	assert(fit([]string{"S", "L"}, []int{73, 87, 95, 229}) == false)
	assert(fit([]string{"L", "L", "L", "L"}, []int{54, 54, 200, 200, 200}) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func fit(s []string, c []int) bool {
	var p []int
	for i := range s {
		switch s[i] {
		case "S":
			p = append(p, 50)
		case "M":
			p = append(p, 100)
		case "L":
			p = append(p, 200)
		}
	}
	q := append([]int{}, c...)

	sort.Ints(p)
	sort.Ints(q)

	j := 0
	for i := range q {
		for j < len(p) && p[j] < q[i] {
			j++
		}
		if j >= len(p) {
			return false
		}
		p[j] -= q[i]
	}
	return true
}
