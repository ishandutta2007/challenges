/*

Here is a farm. Here is a farmer that counts how many animal live in his farm: a camels, b sheep, c green cockroaches. Occurs that a^n + b^n = c^n. n is given. You are to find all the rest.

Input

n (0 ≤ n ≤ 100)

Output

Three different integers (a, b and c) such that a^n + b^n = c^n, 1 ≤ a, b, c ≤ 100.
If there are several solutions you should output the one where a is minimal.
If there are several solutions with the minimal a you should output the one with minimal b, and so on. Output −1 if there is no solution.

*/

package main

func main() {
	test(0, -1, -1, -1)
	test(1, 1, 2, 3)
	test(2, 3, 4, 5)
	test(3, -1, -1, -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, a, b, c int) {
	x, y, z := solution(n)
	assert(x == a)
	assert(y == b)
	assert(z == c)
}

func solution(n int) (a, b, c int) {
	if n == 1 {
		return 1, 2, 3
	}
	if n == 2 {
		return 3, 4, 5
	}
	return -1, -1, -1
}
