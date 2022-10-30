/*

Quentin Tarantino is a famous Hollywood filmmaker and actor. His films have a unique characteristic of connecting with youth by using popular culture references.
They are usually divided into various sub-parts denoted by chapters. His plot of stories is never linear, he always make sure that the chapters should never be shown in the order of Chapter 1, Chapter 2, Chapter 3, ,.. Chapter n linearly.
He believes doing this an insult to the intelligence of viewers. For example, Chapter 1, Chapter 2, Chapter 3 can never be a chapter sequence in Tarantino's movies.. He can have a sequence of Chapter 2, Chapter 3, Chapter 1 instead.

Recently Santa gifted Tom a movie which consists of n chapters. This movie can possibly be directed by your favorite Tarantino or by someone else.
Directors in hollywood can sometimes be very sloppy, they sometimes drop some chapters too and stupid they are that they will leave numbering of the chapters as it is and one can easily identify the chapters that were dropped.
For example, if you find the sequence of chapters as - chapter 1, chapter 5, chapter 3, don't be surprised, they did not even take burden of renumbering the chapters to chapter 1, chapter 3, chapter 2.
They can sometimes repeat the chapter numbers too. Remember that Tarantino is not a sloppy director, so he never makes this kind of stupid mistakes.

Tom happened to find the sequence of chapters in the movie, this sequence contains n chapters, i-th of which is denoted by chapteri.
Tom is a big fan of movies of Tarantino. So, Tom would like to check whether the movie could possibly be directed by Tarantino or not? Please help Tom, he really needs it.

Input

The first line contains an integer T denoting the number of test cases. T test cases follow.

The first line of each test case contains an integer n denoting number of chapters of the movie.

The second line of each test case contains n space separated integers chapteri, denoting numbering of ith chapter.

Output

For each test case, output "yes" or "no" in a separate line.

Constraints
1 ≤ T ≤ 100
2 ≤ N ≤ 100
1 ≤ chapteri ≤ 500

*/

package main

import (
	"sort"
)

func main() {
	assert(directed([]int{2, 3, 1}) == true)
	assert(directed([]int{1, 5, 3}) == false)
	assert(directed([]int{1, 2, 3}) == false)
	assert(directed([]int{1, 1}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func directed(a []int) bool {
	m := make(map[int]int)
	for _, v := range a {
		m[v]++
	}

	n := len(a)
	for i := 1; i <= n; i++ {
		if m[i] != 1 {
			return false
		}
	}

	c := append([]int{}, a...)
	sort.Ints(c)
	for i := 0; i < n; i++ {
		if c[i] == a[i] {
			return false
		}
	}

	return true
}
