/*

This challenge is really simple (and a precursor to a more difficult one!).

Given an array of resource accesses (simply denoted by nonnegative integers) and a parameter n, return the number of cache misses it would have assuming our cache has capacity n and uses a first-in-first-out (FIFO) ejection scheme when it is full.

Example:

4, [0, 1, 2, 3, 0, 1, 2, 3, 4, 0, 0, 1, 2, 3]
0 = not in cache (miss), insert, cache is now [0]
1 = not in cache (miss), insert, cache is now [0, 1]
2 = not in cache (miss), insert, cache is now [0, 1, 2]
3 = not in cache (miss), insert, cache is now [0, 1, 2, 3]
0 = in cache (hit), cache unchanged
1 = in cache (hit), cache unchanged
2 = in cache (hit), cache unchanged
3 = in cache (hit), cache unchanged
4 = not in cache (miss), insert and eject oldest, cache is now [1, 2, 3, 4]
0 = not in cache (miss), insert and eject oldest, cache is now [2, 3, 4, 0]
0 = in cache (hit), cache unchanged
1 = not in cache (miss), insert and eject oldest, cache is now [3, 4, 0, 1]
2 = not in cache (miss), insert and eject oldest, cache is now [4, 0, 1, 2]
3 = not in cache (miss), insert and eject oldest, cache is now [0, 1, 2, 3]
So in this example there were 9 misses. Maybe a code example helps explain it better. In Python:

def num_misses(n, arr):
    misses = 0
    cache = []
    for access in arr:
        if access not in cache:
            misses += 1
            cache.append(access)
            if len(cache) > n:
                cache.pop(0)
    return misses
Some further testcases (which contains a hint towards the next challenge - notice anything curious?):

0, [] -> 0
0, [1, 2, 3, 4, 1, 2, 3, 4] -> 8
2, [0, 0, 0, 0, 0, 0, 0] -> 1
3, [3, 2, 1, 0, 3, 2, 4, 3, 2, 1, 0, 4] -> 9
4, [3, 2, 1, 0, 3, 2, 4, 3, 2, 1, 0, 4] -> 10
Shortest code in bytes wins.

*/

package main

func main() {
	assert(misses(4, []int{0, 1, 2, 3, 0, 1, 2, 3, 4, 0, 0, 1, 2, 3}) == 9)
	assert(misses(0, []int{}) == 0)
	assert(misses(2, []int{0, 0, 0, 0, 0, 0, 0}) == 1)
	assert(misses(3, []int{3, 2, 1, 0, 3, 2, 4, 3, 2, 1, 0, 4}) == 9)
	assert(misses(4, []int{3, 2, 1, 0, 3, 2, 4, 3, 2, 1, 0, 4}) == 10)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func misses(n int, a []int) int {
	r := 0
	c := []int{}
	m := make(map[int]int)
	for _, v := range a {
		if m[v] > 0 {
			continue
		}

		r, c, m[v] = r+1, append(c, v), m[v]+1
		if u := c[0]; len(c) > n {
			m[u], c = m[u]-1, c[1:]
		}
	}
	return r
}
