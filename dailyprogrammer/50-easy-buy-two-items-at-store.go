/*

Hello everyone! As of today, we have finished our 50th challenge and it has been a pleasure giving out these challenges to you all. You have all been amazing with the solutions and seeing you all i hope i become a good programmer like you all one day :D

If i did any mistakes in challenges please forgive me and as you may have noticed we post once in two days or so to give you time to complete these.
Really sorry if you wanted everyday posts .. but due to our busy lives, maybe sometime in future or maybe when i leave this subreddit, you may have that in the new management :)
Thank You one and all ... As for now I have given today's two challenges are from Google Code Jam Qualification Round Africa 2010

Store Credit:

You receive a credit C at a local store and would like to buy two items. You first walk through the store and create a list L of all available items.
From this list you would like to buy two items that add up to the entire value of the credit. The solution you provide will consist of the two integers indicating the positions of the items in your list (smaller number first).

For instance, with C=100 and L={5,75,25} the solution is 2,3; with C=200 and L={150,24,79,50,88,345,3} the solution is 1,4; and with C=8 and L={2,1,9,4,4,56,90,3} the solution is 4,5.

PROBLEM A IN THE LINK. PLEASE USE IT TO CLARIFY YOUR DOUBTS

P.S: Special Thanks to the other moderators too for helping out :)

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(100, []int{5, 75, 25}, []int{2, 3})
	test(200, []int{150, 24, 79, 50, 88, 345, 3}, []int{1, 4})
	test(8, []int{2, 1, 9, 4, 4, 56, 90, 3}, []int{4, 5})
}

func test(c int, a, r []int) {
	p := buy(c, a)
	fmt.Println(p)
	if p == nil {
		assert(r == nil)
	} else {
		assert(reflect.DeepEqual(p, r))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func buy(c int, a []int) []int {
	m := make(map[int]int)
	for i, v := range a {
		m[v] = i
	}
	for i, v := range a {
		j, f := m[c-v]
		if f && i != j {
			return []int{i + 1, j + 1}
		}
	}
	return nil
}
