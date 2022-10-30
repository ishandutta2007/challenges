/*

Given a sequence of integers a, a triplet (a[i],a[j],a[k]) is beautiful if
 1. i < j < k
 2. a[j] - a[i] = a[k] - a[j] = d

Given an increasing sequence of integers and the value of d, count the number of beautiful triplets in the sequence.

Constraints
arr[i] > arr[i-1]
d > 0

*/
package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

func main() {
	a := []int{2, 2, 3, 4, 5}
	fmt.Println(countSlow(a, 1), count(a, 1))

	b := []int{1, 2, 4, 5, 7, 8, 10}
	fmt.Println(countSlow(b, 3), count(b, 3))

	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 1000; i++ {
		p := randv(1000)
		d := 1+rand.Intn(100)
		a := countSlow(p, d)
		b := count(p, d)
		if a != b {
			fmt.Println(p, d, a, b)
		}
	}
}

func randv(n int) []int {
	p := make([]int, n)
	for i := range p {
		p[i] = rand.Intn(1000)
	}
	sort.Ints(p)
	return p
}

func countSlow(a []int, d int) int {
	c := 0
	for i := 0; i < len(a); i++ {
		for j := i + 1; j < len(a); j++ {
			if a[j]-a[i] == d {
				for k := j + 1; k < len(a); k++ {
					if a[k]-a[j] == d {
						c++
					}
				}
			}
		}
	}
	return c
}

func count(a []int, d int) int {
	m := make(map[int]int)
	c := 0
	for _, n := range a {
		if m[n-d] > 0 && m[n-2*d] > 0 {
			c += m[n-d] * m[n-2*d]
		}
		m[n]++
	}
	return c
}
