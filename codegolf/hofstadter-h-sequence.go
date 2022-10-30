/*

Definition

a(0)=0
a(n)=n-a(a(a(n−1))) for integer n>0

Task

Given non-negative integer n, output a(n).

Testcases
n     a(n)
0     0
1     1
2     1
3     2
4     3
5     4
6     4
7     5
8     5
9     6
10    7
11    7
12    8
13    9
14    10
15    10
16    11
17    12
18    13
19    13
20    14
10000 6823

References

WolframMathWorld
OEIS A005374

*/

package main

func main() {
	assert(a(0) == 0)
	assert(a(1) == 1)
	assert(a(2) == 1)
	assert(a(3) == 2)
	assert(a(4) == 3)
	assert(a(5) == 4)
	assert(a(6) == 4)
	assert(a(7) == 5)
	assert(a(8) == 5)
	assert(a(9) == 6)
	assert(a(10) == 7)
	assert(a(11) == 7)
	assert(a(12) == 8)
	assert(a(13) == 9)
	assert(a(14) == 10)
	assert(a(15) == 10)
	assert(a(16) == 11)
	assert(a(17) == 12)
	assert(a(18) == 13)
	assert(a(19) == 13)
	assert(a(20) == 14)
	assert(a(10000) == 6823)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var cache = map[int]int{
	0: 0,
}

func a(n int) int {
	if v, ok := cache[n]; ok {
		return v
	}

	v := n - a(a(a(n-1)))
	cache[n] = v
	return v
}
