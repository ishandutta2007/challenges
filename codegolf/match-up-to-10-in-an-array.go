/*

Challenge

Given an array of single digit number, work out if any 2 of them add up to 10 and print them out
Example

Input

    (1,2,3,4,5,5,6,7)

This returns ((4,6),(5,5),(3,7))

Input

    (1,2,3,4,5)

This returns (). as there is only one 5

Input

    (5,5,5,5,5)

This returns ((5,5),(5,5)) as there is odd number of 5s and each 5 can be used only once
Rules

Here are the rules!

    Assume input will only be an unsorted array of positive single digit integers
    Each number will be pair up only once, which means if there are three 5s it only form 1 pair (5,5). If there are (3,3,7) it will only form 1 pair (3,7)
    For the input: You can use any type of parentheses(or lack of) as long as readers can tell that the input is a single array of numbers.
    For the output: It must look like an array of pairs. Where the array is the same form as your input.(If you did not use any parenheses in your input, you have to use some kind of symbols so that any readers can tell they are pairs in an array)

Test Cases

(1,2,3,4,5,5,6,7) =((4,6),(5,5),(3,7))
(1,2,3,4,5) = ()
(5,5,5,5,5) = ((5,5),(5,5))
(1,2,3,3,4,5,6,7)=((3,7),(4,6))
(9,8,7,6,4,4,3,1)=((9,1),(7,3),(6,4))

Good luck!

The shorter an answer is, the better!

Edit 1: update the rules and Testcases from comments

Edit 2: update rules to define format of input.

Edit 3: update rules to define format of output. trying to be as accommodating as possible.

*/

package main

import "fmt"

func main() {
	fmt.Println(matchup([]int{1, 2, 3, 4, 5, 6, 7}))
	fmt.Println(matchup([]int{1, 2, 3, 4, 5}))
	fmt.Println(matchup([]int{5, 5, 5, 5, 5}))
	fmt.Println(matchup([]int{1, 2, 3, 3, 4, 5, 6, 7}))
	fmt.Println(matchup([]int{9, 8, 7, 6, 4, 4, 3, 1}))
}

func matchup(a []int) [][2]int {
	var h [10]int
	for i := range a {
		h[a[i]]++
	}

	var r [][2]int
loop:
	for i := range h {
		for h[i] > 0 {
			j := 10 - i
			if (j == i && h[j]-1 == 0) || h[j] == 0 {
				continue loop
			}
			h[i]--
			h[j]--

			r = append(r, [2]int{i, j})
		}
	}
	return r
}
