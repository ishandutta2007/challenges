/*

Like all other good drivers, you like to curse, swear and honk your horn at your fellow automobile drivers.
Today you’re at the rear of a long line, brooding over the others’ inability to keep proper distance to the car in front.
But are you really keeping your own distance?

You have calculated that in order to never have to use your breaks, you must keep a distance to any car x in front of you at least p(n+1) where n is the number of cars between you and x,
and p is an integer constant determined by which of your cars you are currently driving.

Given the value of p and the current distances (in random order) to each of the cars ahead of you, calculate the minimum distance you should be keeping to the car directly in front, in order to not have to use your breaks.

Input

First a line with 1≤n≤100000

– the number of cars ahead of you – and 1≤p≤20

– the deceleration constant.

Then a single line with n unique integers denoting the current distance to each of the cars ahead of you. Each of these integers are in the interval [1,107]


Output

The minimum distance you must keep to the car directly in front, in order to not have to use your breaks.

*/

package main

import (
	"sort"
)

func main() {
	assert(carlink(1, []int{1, 2, 4}) == 1)
	assert(carlink(3, []int{2, 3, 4, 5, 6, 1}) == 13)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func carlink(p int, a []int) int {
	sort.Ints(a)

	r := 0
	for i := range a {
		r = max(r, p*(i+1)-a[i])
	}
	if len(a) > 0 {
		r += a[0]
	}
	return r
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
