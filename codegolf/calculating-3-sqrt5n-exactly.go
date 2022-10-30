/*

Today your goal is to find integers a and b given non-negative integer n such that:

(3 + sqrt(5))^n = a + b * sqrt(5)

You should write a program or a function that takes parameter n and outputs a and b in a format of your choice.

Standard loopholes apply. Additionally, it's intended that you implement the above problem using basic arithmetic yourself.
So you may not use built-in exact algebra functionality, rationals, or functions implementing non-trivial mathematical constructs (for example the Lucas sequence).

Shortest code in bytes wins.

Example input/output:

0 → 1, 0
1 → 3, 1
2 → 14, 6
3 → 72, 32
4 → 376, 168
5 → 1968, 880
6 → 10304, 4608
7 → 53952, 24128
8 → 282496, 126336
9 → 1479168, 661504

*/

package main

func main() {
	tab := [][3]int{
		{0, 1, 0},
		{1, 3, 1},
		{2, 14, 6},
		{3, 72, 32},
		{4, 376, 168},
		{5, 1968, 880},
		{6, 10304, 4608},
		{7, 53952, 24128},
		{8, 282496, 126336},
		{9, 1479168, 661504},
	}

	for _, v := range tab {
		assert(A(v[0]) == v[1])
		assert(B(v[0]) == v[2])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

https://oeis.org/A098648
https://oeis.org/A084326
https://oeis.org/A000032

*/

func A(n int) int {
	if n < 0 {
		return 0
	}
	if n == 0 {
		return 1
	}
	return 1 << (n - 1) * lucas(2*n)
}

func B(n int) int {
	if n < 0 {
		return 0
	}

	a, b := 0, 1
	for i := 0; i < n; i++ {
		a, b = b, 6*b-4*a
	}
	return a
}

func lucas(n int) int {
	if n < 0 {
		return 0
	}

	a, b := 2, 1
	for i := 0; i < n; i++ {
		a, b = b, a+b
	}
	return a
}
