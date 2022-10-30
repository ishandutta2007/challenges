/*

Do you know what attracts almost any college student to participate in an event?
Yes, free food. It doesn’t matter whether the event involves a long (sometimes boring) seminar.
As long as free food is served for the event, then students will surely come.

Suppose there are N events to be held this year.

The ith event is scheduled from day si to day ti, and free food is served for that event every day from day si to day ti (inclusive).
Your task in this problem is to find out how many days there are in which free food is served by at least one event.

For example, let there be N=3 events. The first event is held from day 10 to 14, the second event is held from day 13 to 17, and the third event is held from day 25 to 26.
The days in which free food is served by at least one event are 10,11,12,13,14,15,16,17,25,26, for a total of 10 days. Note that both events serve free food on days 13 and 14.

Input

The first line contains an integer N (1≤N≤100) denoting the number of events.
Each of the next N lines contains two integers si and ti (1≤si≤ti≤365) denoting that the ith event will be held from si to ti (inclusive), and free food is served for all of those days.

Output

The output contains an integer denoting the number of days in which free food is served by at least one event.

*/

package main

func main() {
	assert(foods([][2]int{
		{10, 14},
		{13, 17},
		{25, 26},
	}) == 10)

	assert(foods([][2]int{
		{1, 365},
		{20, 28},
	}) == 365)

	assert(foods([][2]int{
		{29, 29},
		{48, 48},
		{102, 102},
		{94, 94},
	}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func foods(a [][2]int) int {
	m := make(map[int]bool)
	c := 0
	for _, v := range a {
		for i := v[0] - 1; i < v[1]; i++ {
			if !m[i] {
				m[i], c = true, c+1
			}
		}
	}
	return c
}
