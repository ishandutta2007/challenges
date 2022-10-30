/*

Write a function which takes a single positive integer n and returns the period of the decimal representation of 1/n.

Test cases:

1 -> 1               # 1/1 = 1.0000...... = 1._0
2 -> 1               # 1/2 = 0.5000...... = 0.5_0
3 -> 1               # 1/3 = 0.3333...... = 0._3
7 -> 6               # 1/7 = 0.14285714.. = 0._142857
13 -> 6
14 -> 6
123 -> 5
345 -> 22
654 -> 108
12345 -> 822
67890 -> 120

This is code-golf. Built-ins or libraries which return the period directly are not permitted. Numbers up to at least 100000 should work within reasonable time (at most several minutes).

*/

package main

import (
	"math/big"
)

func main() {
	assert(period(1) == 1)
	assert(period(2) == 1)
	assert(period(3) == 1)
	assert(period(7) == 6)
	assert(period(13) == 6)
	assert(period(14) == 6)
	assert(period(123) == 5)
	assert(period(345) == 22)
	assert(period(654) == 108)
	assert(period(12345) == 822)
	assert(period(67890) == 120)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

https://math.stackexchange.com/questions/377683/length-of-period-of-decimal-expansion-of-a-fraction

Need to find the number d > 0 that satisfy:
10^d % n = 0 or
10^d % n = 1

d will be the period before the digits repeats.

If the number n has factors 2 or 5 in it; then we need to remove those factors before finding the period or else the procedure above will not work.
The max of the number of factors of 2 and 5 gives the number of non-repeating digits before the the repeating digits.

2^i * 5^j * p = n
max(i, j) gives the number of non-repeating digits before the repeating digits.

*/

func period(n int64) int64 {
	if n <= 0 {
		return -1
	}

	var (
		one = big.NewInt(1)
		ten = big.NewInt(10)
	)
	n, _ = rmf(n, 2)
	n, _ = rmf(n, 5)

	p := big.NewInt(1)
	r := new(big.Int)
	m := big.NewInt(n)
	for {
		r.Exp(ten, p, m)
		if r.Cmp(one) <= 0 {
			break
		}
		p.Add(p, one)
	}
	return p.Int64()
}

func rmf(n, m int64) (int64, int64) {
	c := int64(0)
	for n%m == 0 {
		n /= m
		c += 1
	}
	return n, c
}
