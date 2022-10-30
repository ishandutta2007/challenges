/*

Related: What's my telephone number? which asks to calculate the terms of A000085, the number of possible ordinal transforms of length n.

Background

Ordinal transform is a transformation on an integer sequence. For a sequence a=(a0,a1,a2,⋯), the n-th term of the ordinal transform ord(a)n is defined as the occurrence count of an in a0,a1,⋯,an.
Informally, ord(a) can be described as "the value an appears the ord(a)n-th time in the sequence a".

For example, the sequence [1, 2, 1, 1, 3, 2, 2, 3, 1] transforms into [1, 1, 2, 3, 1, 2, 3, 2, 4].

1, 2, 1, 1, 3, 2, 2, 3, 1
1, 1, 2, 3, 1, 2, 3, 2, 4
^     ^  ^              ^
|     |  |              4th occurrence of 1
|     |  3rd occurrence of 1
|     2nd occurrence of 1
1st occurrence of 1

The number of possible ordinal transforms is A000085. A hint to tackle this problem can be found on the page (search for "ballot sequences").

Challenge

Given a non-empty finite integer sequence, test if it can be the result of ordinal transform of some integer sequence.

You can assume the input entirely consists of positive integers.

For output, you can choose to

    output truthy/falsy using your language's convention (swapping is allowed), or
    use two distinct, fixed values to represent true (affirmative) or false (negative) respectively.

Standard code-golf rules apply. The shortest code in bytes wins.

Test cases

Truthy

[1]
[1, 1]
[1, 2, 3, 1]
[1, 1, 2, 2]
[1, 2, 1, 2, 1, 2, 1]
[1, 2, 3, 4, 5, 6, 7]
[1, 1, 2, 3, 1, 2, 3, 2, 4]
[1, 1, 2, 3, 4, 2, 1, 3, 2, 1]

Falsy

[2]
[6]
[1, 3]
[2, 1, 1]
[1, 2, 2, 1]
[1, 2, 3, 2]
[1, 2, 3, 4, 4]
[1, 2, 3, 2, 1]

*/

package main

import (
	"math/rand"
	"time"
)

func main() {
	assert(isord([]int{1}) == true)
	assert(isord([]int{1, 1}) == true)
	assert(isord([]int{1, 2, 3, 1}) == true)
	assert(isord([]int{1, 1, 2, 2}) == true)
	assert(isord([]int{1, 2, 1, 2, 1, 2, 1}) == true)
	assert(isord([]int{1, 2, 3, 4, 5, 6, 7}) == true)
	assert(isord([]int{1, 1, 2, 3, 1, 2, 3, 2, 4}) == true)
	assert(isord([]int{1, 1, 2, 3, 4, 2, 1, 3, 2, 1}) == true)

	assert(isord([]int{2}) == false)
	assert(isord([]int{6}) == false)
	assert(isord([]int{1, 3}) == false)
	assert(isord([]int{2, 1, 1}) == false)
	assert(isord([]int{1, 2, 2, 1}) == false)
	assert(isord([]int{1, 2, 3, 2}) == false)
	assert(isord([]int{1, 2, 3, 4, 4}) == false)
	assert(isord([]int{1, 2, 3, 2, 1}) == false)

	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 100; i++ {
		a := rand.Perm(1000)
		p := ord(a)
		assert(isord(p) == true)
		assert(isord(a) == false)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func ord(a []int) []int {
	m := make(map[int]int)
	p := make([]int, len(a))
	for i, v := range a {
		m[v]++
		p[i] = m[v]
	}
	return p
}

func isord(a []int) bool {
	m := make(map[int]int)
	for _, v := range a {
		m[v]++
		if v-1 > 0 {
			if m[v-1]--; m[v-1] < 0 {
				return false
			}
		}
	}
	return true
}
