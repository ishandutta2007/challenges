/*


Input

There are several test cases. Each test case begins with a line containing two integers n, t, where 1≤n≤10^18, and 0≤t≤100.

Then follow t operations to perform, each of the form x op y. Here, 0≤x,y<n are integers, and op is one of ’+’, ’−’, ’∗’, ’/’, indicating an operation to perform.
Division, x/y is defined to be xy^-1.

Input is terminated by a case where n=0 and t=0, which should not be processed.

Output

For each operation in each test case, output the result of performing the indicated operation modulo n.
If the operations is not possible (e.g. because of division by zero), output −1.

*/

package main

import (
	"math/big"
)

func main() {
	assert(eval(1, '/', 999, 1000) == 999)
	assert(eval(1, '/', 998, 1000) == -1)
	assert(eval(578, '*', 178, 1000) == 884)
	assert(eval(7, '/', 9, 13) == 8)
	assert(eval(9, '*', 3, 13) == 1)
	assert(eval(0, '-', 9, 13) == 4)
	assert(eval(10, '+', 10, 13) == 7)
	assert(eval(8, '/', 4, 5) == 2)
	assert(eval(8, '/', 3, 5) == 1)
	assert(eval(11, '/', 4, 5) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eval(x int, op rune, y, m int) int {
	switch op {
	case '+':
		return (x + y) % m
	case '-':
		return (x - y + m) % m
	case '*':
		return (x * y) % m
	case '/':
		yi := modinv(y, m)
		if yi == 0 {
			return -1
		}
		return (x * yi) % m
	}
	return 0
}

func modinv(x, m int) int {
	a := big.NewInt(int64(x))
	b := big.NewInt(int64(m))
	r := new(big.Int)
	r.ModInverse(a, b)
	return int(r.Int64())
}
