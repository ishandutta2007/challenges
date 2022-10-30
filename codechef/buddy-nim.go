/*

Alice, Bob and Charlie are playing a new game called Buddy NIM.
The game is played at two tables; on the first table, there are N heaps containing A1,A2,…,AN stones and on the second table, there are M heaps containing B1,B2,…,BM stones respectively.

Initially, Alice is playing at the first table and Bob is playing at the second table. The players take their turns in this order: Charlie, Alice, Bob, Charlie, etc.

Alice and Bob follow the rules for classical NIM - on Alice's turn, Alice must remove a positive number of stones from one of the piles at her current table and on Bob's turn,
Bob must remove a positive number of stones from one of the piles at his current table. Whoever cannot remove any stone from a pile loses.

Charlie does not play at any table. Instead, on his turn, he decides if Alice and Bob should keep playing at their respective tables or swap places.

Alice and Charlie are buddies and they cooperate, playing in the optimal way that results in Alice's victory (if possible).

It is clear that either Alice or Bob wins the game eventually. You must find out who the winner will be.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each testcase contains two space-separated integers N and M.
The second line contains N space-separated integers A1,A2,…,AN.
The third line contains M space-separated integers B1,B2,…,BM.

Output

Print a single line containing the string "Alice" if Alice wins or "Bob" if Bob wins.

Constraints
1≤T≤10^2
1≤N,M≤10^2
0≤Ai≤10^9 for each valid i
0≤Bi≤10^9 for each valid i

*/

package main

import "reflect"

func main() {
	assert(winner([]int{1, 1, 1}, []int{3}) == "Alice")
	assert(winner([]int{1, 2, 3}, []int{7}) == "Alice")
	assert(winner([]int{1}, []int{1}) == "Bob")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func winner(a, b []int) string {
	m := make(map[int]int)
	n := make(map[int]int)
	for _, v := range a {
		if v != 0 {
			m[v]++
		}
	}
	for _, v := range b {
		if v != 0 {
			n[v]++
		}
	}

	if reflect.DeepEqual(m, n) {
		return "Bob"
	}
	return "Alice"
}
