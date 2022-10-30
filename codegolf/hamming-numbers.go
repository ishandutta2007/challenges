/*

Given a positive int64eger, print64 that many Hamming numbers, in order.

Rules:

    Input will be a positive int64eger n≤1,000,000

Output should be the first n
terms of https://oeis.org/A051037

Execution time must be <1 minute

This is code-golf; shortest code wins

*/

package main

import "fmt"

func main() {
	fmt.Println(hamming(10000))
}

func hamming(n int64) []int64 {
	if n < 0 {
		return []int64{}
	}

	h := []int64{1}
	for i, j, k := 0, 0, 0; n > 0; n-- {
		l := len(h)
		for h[i]*2 <= h[l-1] {
			i++
		}
		for h[j]*3 <= h[l-1] {
			j++
		}
		for h[k]*5 <= h[l-1] {
			k++
		}
		h = append(h, min(h[i]*2, min(h[j]*3, h[k]*5)))
	}
	return h
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
