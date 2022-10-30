/*

You will receive an array and must return the number of integers that occur more than once.

[234, 2, 12, 234, 5, 10, 1000, 2, 99, 234]
This will return 2, since each of 234 and 2 appear more than once.

[234, 2, 12, 234]
[2, 12, 234, 5, 10, 1000, 2]
The list will never be more than 100k integers long, and the integers inside the list will always be in between -100k and 100k.

Integers should be counted if they occur more than once, so if an integer occurs 3 times then it will still only count as one repeated integer.

Test cases

[1, 10, 16, 4, 8, 10, 9, 19, 2, 15, 18, 19, 10, 9, 17, 15, 19, 5, 13, 20]  = 4
[11, 8, 6, 15, 9, 19, 2, 2, 4, 19, 14, 19, 13, 12, 16, 13, 0, 5, 0, 8]     = 5
[9, 7, 8, 16, 3, 9, 20, 19, 15, 6, 8, 4, 18, 14, 19, 12, 12, 16, 11, 19]   = 5
[10, 17, 17, 7, 2, 18, 7, 13, 3, 10, 1, 5, 15, 4, 6, 0, 19, 4, 17, 0]      = 5
[12, 7, 17, 13, 5, 3, 4, 15, 20, 15, 5, 18, 18, 18, 4, 8, 15, 13, 11, 13]  = 5
[0, 3, 6, 1, 5, 2, 16, 1, 6, 3, 12, 1, 16, 5, 4, 5, 6, 17, 4, 8]           = 6
[11, 19, 2, 3, 11, 15, 19, 8, 2, 12, 12, 20, 13, 18, 1, 11, 19, 7, 11, 2]  = 4
[6, 4, 11, 14, 17, 3, 17, 11, 2, 16, 14, 1, 2, 1, 15, 15, 12, 10, 11, 13]  = 6
[0, 19, 2, 0, 10, 10, 16, 9, 19, 9, 15, 0, 10, 18, 0, 17, 18, 18, 0, 9]    = 5
[1, 19, 17, 17, 0, 2, 14, 10, 10, 12, 5, 14, 16, 7, 15, 15, 18, 11, 17, 7] = 5

*/

package main

func main() {
	assert(repetitions([]int{234, 2, 12, 234, 5, 10, 1000, 2, 99, 234}) == 2)
	assert(repetitions([]int{2, 12, 234, 5, 10, 1000, 2}) == 1)
	assert(repetitions([]int{1, 10, 16, 4, 8, 10, 9, 19, 2, 15, 18, 19, 10, 9, 17, 15, 19, 5, 13, 20}) == 4)
	assert(repetitions([]int{11, 8, 6, 15, 9, 19, 2, 2, 4, 19, 14, 19, 13, 12, 16, 13, 0, 5, 0, 8}) == 5)
	assert(repetitions([]int{9, 7, 8, 16, 3, 9, 20, 19, 15, 6, 8, 4, 18, 14, 19, 12, 12, 16, 11, 19}) == 5)
	assert(repetitions([]int{10, 17, 17, 7, 2, 18, 7, 13, 3, 10, 1, 5, 15, 4, 6, 0, 19, 4, 17, 0}) == 5)
	assert(repetitions([]int{12, 7, 17, 13, 5, 3, 4, 15, 20, 15, 5, 18, 18, 18, 4, 8, 15, 13, 11, 13}) == 5)
	assert(repetitions([]int{0, 3, 6, 1, 5, 2, 16, 1, 6, 3, 12, 1, 16, 5, 4, 5, 6, 17, 4, 8}) == 6)
	assert(repetitions([]int{11, 19, 2, 3, 11, 15, 19, 8, 2, 12, 12, 20, 13, 18, 1, 11, 19, 7, 11, 2}) == 4)
	assert(repetitions([]int{6, 4, 11, 14, 17, 3, 17, 11, 2, 16, 14, 1, 2, 1, 15, 15, 12, 10, 11, 13}) == 6)
	assert(repetitions([]int{0, 19, 2, 0, 10, 10, 16, 9, 19, 9, 15, 0, 10, 18, 0, 17, 18, 18, 0, 9}) == 5)
	assert(repetitions([]int{1, 19, 17, 17, 0, 2, 14, 10, 10, 12, 5, 14, 16, 7, 15, 15, 18, 11, 17, 7}) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func repetitions(a []int) int {
	m := make(map[int]int)
	r := 0
	for _, v := range a {
		if m[v]++; m[v] == 2 {
			r++
		}
	}
	return r
}
