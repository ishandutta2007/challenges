/*

Write a function to check if an array contains a particular number.
Examples

check([1, 2, 3, 4, 5], 3) ➞ true

check([1, 1, 2, 1, 1], 3) ➞ false

check([5, 5, 5, 6], 5) ➞ true

check([], 5) ➞ false

Notes

    Don't forget to return the result.
    If you get stuck on a challenge, find help in the Resources tab.
    If you're really stuck, unlock solutions in the Solutions tab.

*/

package main

func main() {
	assert(check([]int{1, 2, 3, 4, 5}, 3) == true)
	assert(check([]int{1, 1, 2, 1, 1}, 3) == false)
	assert(check([]int{1, 1, 2, 1, 5, 4, 7}, 7) == true)
	assert(check([]int{1, 1, 2, 1, 5, 4, 7}, 8) == false)
	assert(check([]int{5, 5, 5, 6}, 5) == true)
	assert(check([]int{}, 5) == false)
}

func check(a []int, v int) bool {
	for i := range a {
		if a[i] == v {
			return true
		}
	}
	return false
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
