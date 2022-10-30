/*

Chef lives in a huge apartment building with N floors, numbered 0 (ground floor) through N (terrace). Unfortunately, it has only one lift. We say that when the lift travels from a floor a to a floor b, it travels |b−a| floors.

Initially, the lift is on the ground floor. Then, it receives Q requests (numbered 1 through Q).
For each valid i, the i-th request is for the lift to move from its current floor to a source floor fi, where some people enter the lift, and then move to a destination floor di, where they exit the lift.
The lift should not stop anywhere in between moving to the floor fi or from the floor fi to the floor di. The lift must serve the requests sequentially, i.e. completely fulfill request 1, then request 2 and so on.
The lift does not move anywhere after serving the final request.

Find the total number of floors the lift needs to travel to fulfill all the requests.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and Q.
The following Q lines describe requests. For each valid i, the i-th of these lines contains two space-separated integers fi and di.

Output

For each test case, print a single line containing one integer ― the total number of floors travelled by the lift.

Constraints
1≤T≤250
1≤N≤10^6
1≤Q≤10^5
0≤fi,di≤N for each valid i
fi≠di for each valid i
the sum of Q over all test cases does not exceed 10^5

*/

package main

func main() {
	assert(floors(2, [][2]int{
		{1, 2},
		{0, 1},
		{1, 0},
	}) == 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func floors(_ int, a [][2]int) int {
	r := 0
	c := 0
	for _, v := range a {
		r += abs(c-v[0]) + abs(v[0]-v[1])
		c = v[1]
	}
	return r
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
