/*

Bhallaladeva was an evil king who ruled the kingdom of Maahishmati.
He wanted to erect a 100ft golden statue of himself and he looted gold from several places for this.
He even looted his own people, by using the following unfair strategy:

There are N houses in Maahishmati, and the ith house has Ai gold plates. Each gold plate costs exactly 1 Nimbda, which is the unit of currency in the kingdom of Maahishmati.
Bhallaladeva would choose an integer K, and loots all the houses in several steps. In each step:

He would choose a house i which hasn't been looted yet, pay the owner exactly Ai Nimbdas, and take away all the gold plates in that house (Hence, he also ends up looting this house).
He would now choose atmost K houses which haven't been looted yet and take away all the gold plates from these houses without paying a single Nimbda (Yes, he takes all of them for free).
He repeats the above steps until all the N houses have been looted. Your task is to devise a strategy for Bhallaladeva to loot the houses in some order, so that the number of nimbdas he has to pay is minimium.
You'll also be given multiple values of K (Q of them to be precise), and you need to find the minimum number of nimbdas for each of these values.

Input

The first line of input consists of a single integer N denoting the number of houses in Maahishmati.
The second line of input consists of N space separated integers denoting A1, A2, ..., AN, where Ai denotes the number of gold plates in the ith house.
The third line of input consists of a single integer Q denoting the number of values of K to follow. Each of the following Q lines consist of a single integer, where the value on the ith line denotes the value of K for the ith query.

Output

Output exactly Q integers on separate lines, where the output on the ith line denotes the answer for the ith value of K.

Constraints
1 ≤ N ≤ 10^5
1 ≤ Q ≤ 10^5
0 ≤ K ≤ N-1
1 ≤ Ai ≤ 10^4

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]int{3, 2, 1, 4}, []int{0, 2}, []int{10, 3})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, k, r []int) {
	p := nimbdas(a, k)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func nimbdas(a, k []int) []int {
	n := len(a)
	p := append([]int{}, a...)

	sort.Ints(p)

	for i := 1; i < n; i++ {
		p[i] += p[i-1]
	}

	r := make([]int, len(k))
	for i := range k {
		r[i] = p[(n+k[i])/(k[i]+1)-1]
	}
	return r
}
