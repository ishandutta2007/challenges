/*

Chef owns an icecream shop in Chefland named scoORZ. There are only three types of coins in Chefland: Rs. 5, Rs. 10 and Rs. 15. An icecream costs Rs. 5.

There are N people (numbered 1 through N) standing in a queue to buy icecream from scoORZ.
Each person wants to buy exactly one icecream. For each valid i, the i-th person has one coin with value ai.
It is only possible for someone to buy an icecream when Chef can give them back their change exactly ― for example, if someone pays with a Rs.
10 coin, Chef needs to have a Rs. 5 coin that he gives to this person as change.

Initially, Chef has no money. He wants to know if he can sell icecream to everyone in the queue, in the given order. Since he is busy eating his own icecream, can you tell him if he can serve all these people?

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers a1,a2,…,aN.

Output

For each test case, print a single line containing the string "YES" if all people can be served or "NO" otherwise (without quotes).

Constraints
1≤T≤100
1≤N≤10^3
ai∈{5,10,15} for each valid i

*/

package main

func main() {
	assert(serve([]int{5, 10}) == true)
	assert(serve([]int{10, 5}) == false)
	assert(serve([]int{5, 15}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func serve(a []int) bool {
	var c5, c10, c15 int
	for _, v := range a {
		switch v {
		case 5:
			c5 = c5 + 1

		case 10:
			if c5 > 0 {
				c5, c10 = c5-1, c10+1
			} else {
				return false
			}

		case 15:
			if c10 > 0 {
				c10, c15 = c10-1, c15+1
			} else if c5 >= 2 {
				c5, c15 = c5-2, c15+1
			} else {
				return false
			}

		default:
			return false
		}
	}
	return true
}
