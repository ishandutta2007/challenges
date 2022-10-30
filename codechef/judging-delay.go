/*

You have been recently hired as a developer in CodeChef.
Your first mission is to implement a feature that will determine the number of submissions that were judged late in a contest.

There are N submissions, numbered 1 through N. For each valid i, the i-th submission was submitted at time Si and judged at time Ji (in minutes).
Submitting and judging both take zero time. Please determine how many submissions received their verdicts after a delay of more than 5 minutes.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of the input contains a single integer N.
N lines follow. For each valid i, the i-th of these lines contains two space-separated integers Si and Ji.

Output

For each test case, print a single line containing one integer — the number of submissions for which the judging was delayed by more than 5 minutes.

Constraints

1≤T≤100
1≤N≤100
1≤Si≤Ji≤300 for each valid i

*/

package main

func main() {
	assert(delayed([][2]int{
		{1, 3},
		{4, 4},
		{4, 10},
		{1, 11},
		{2, 7},
	}) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func delayed(a [][2]int) int {
	r := 0
	for _, v := range a {
		if v[1]-v[0] > 5 {
			r++
		}
	}
	return r
}
