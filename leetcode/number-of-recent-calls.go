/*

Write a class RecentCounter to count recent requests.

It has only one method: ping(int t), where t represents some time in milliseconds.

Return the number of pings that have been made from 3000 milliseconds ago until now.

Any ping with time in [t - 3000, t] will count, including the current ping.

It is guaranteed that every call to ping uses a strictly larger value of t than before.

Note:

Each test case will have at most 10000 calls to ping.
Each test case will call ping with strictly increasing values of t.
Each call to ping will have 1 <= t <= 10^9.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

type RecentCounter struct {
	queue    []int
	interval int
}

func NewRecentCounter() *RecentCounter {
	return &RecentCounter{
		interval: 3000,
	}
}

func (r *RecentCounter) Ping(t int) int {
	r.queue = append(r.queue, t)
	for r.queue[0] < t-r.interval {
		r.queue = r.queue[1:]
	}
	return len(r.queue)
}

func test(t []int) {
	var s []int
	r := NewRecentCounter()
	for _, t := range t {
		s = append(s, r.Ping(t))
	}
	fmt.Println(s)
}

func main() {
	rand.Seed(time.Now().UnixNano())
	test([]int{1, 100, 3001, 3002})
	test(randiv(1e6))
}

func randiv(n int) []int {
	p := make([]int, n)
	for i := range p {
		p[i] = rand.Int()
	}
	return p
}
