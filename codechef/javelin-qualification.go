/*

There are N players with IDs from 1 to N, who are participating in the Javelin throw competition which has two rounds.
The first is the qualification round, followed by the final round. The qualification round has gotten over, and you are given the longest distance that each of the N players has thrown as A1,A2,…,AN.
Now, the selection process for the final round happens in the following two steps:

1) If the longest throw of a player in the qualification round is greater than or equal to the qualification mark of M cm, they qualify for the final round.

2) If after step 1, less than X players have qualified for the finals, the remaining spots are filled by players who have thrown the maximum distance among the players who have not qualified yet.

You are given the best throws of the N players in the qualification round A1,A2,…,AN and the integers M and X. Print the list of the players who will qualify for the finals in increasing order of their IDs.

Input Format

The first line of input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N,M,X.
The second line of each test case contains N space-separated integers A1,A2,…,AN.

Output Format

For each test case, print a single line containing K+1 space-separated integers, where K is the number of players qualified.
First, print the integer K, then followed by a space, print K space-separated integers ID1,ID2,…,IDK where IDi denotes the players' ID who qualified for the finals.
You have to print the IDs of the qualified players in increasing order.

Constraints
1≤T≤1000
2≤X≤N≤30
5000≤Ai≤8000
7000≤M≤8000
All Ai-s are distinct

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]int{5000, 5001, 5002}, 8000, 2, []int{2, 3})
	test([]int{7999, 7998, 8000}, 5000, 2, []int{1, 2, 3})
	test([]int{5999, 5998, 6000, 6001}, 6000, 3, []int{1, 3, 4})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, m, x int, r []int) {
	p := players(a, m, x)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func players(a []int, m, x int) []int {
	p := make([][2]int, len(a))
	for i := range a {
		p[i][0] = a[i]
		p[i][1] = i + 1
	}

	sort.SliceStable(p, func(i, j int) bool {
		return p[i][0] > p[j][0]
	})

	var r []int
	for _, v := range p {
		if v[0] >= m || len(r) < x {
			r = append(r, v[1])
		}
	}
	sort.Ints(r)

	return r
}
