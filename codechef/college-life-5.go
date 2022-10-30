/*

There is only 1 TV in the common room, and as luck would have it, both the El Clasico football match and the India-Pakistan cricket match are happening simultaneously.

There is one football fan who is looking at the live commentary online and will scream whenever an 'important' event takes place in the El Clasico.
Similarly, there is a cricket fan who will do so for every important event in the cricket match.

You are given two arrays - F1,F2,…,Fn, which denote the times when an important event happens in the football match.
And similarly C1,C2,…,Cm for cricket. You sadly have the remote in hand. You start out by watching the El Clasico.
But whenever an Important event happens in the sport which isn't on the TV right now, you will be forced to switch to that sport's channel, and this continues, i.e., you switch channels if and only if when an important event in the other sport happens.
Find the total number of times you will have to switch between the channels.

Input:

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of 3 lines of input.
First line contain 2 space separated integers N and M, number of important events in football and cricket match respectively.
Second line contain N space separated integers Fi, where the ith index represents ith important event in the football match.
Third line contain M space separated integers Ci, where the ith index represents ith important event in the cricket match.

Output:

For each testcase, output in a single line answer to the problem.

Constraints
1≤N,M≤2.5∗10^4
1≤Fi,Ci≤10^9
Fi>Fi−1 ∀i>0
Ci>Ci−1 ∀i>0
Fi != Cj ∀i,j
Sum of N over all tests is atmost 2∗10^5
Sum of M over all tests is atmost 2∗10^5

*/

package main

import (
	"sort"
)

func main() {
	assert(chanswitch([]int{1, 3}, []int{2, 4}) == 3)
	assert(chanswitch([]int{100, 200, 300}, []int{1}) == 2)
	assert(chanswitch([]int{1}, []int{100, 200}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func chanswitch(f, c []int) int {
	var p [][2]int
	for _, v := range f {
		p = append(p, [2]int{v, 0})
	}
	for _, v := range c {
		p = append(p, [2]int{v, 1})
	}

	sort.Slice(p, func(i, j int) bool {
		if p[i][0] == p[j][0] {
			return p[i][1] < p[j][1]
		}
		return p[i][0] < p[j][0]
	})

	r, u := 0, 0
	for _, v := range p {
		if v[1] != u {
			r, u = r+1, 1-u
		}
	}
	return r
}
