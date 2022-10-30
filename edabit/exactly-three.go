/*

You are given a number n. Determine whether n has exactly 3 divisors or not.

Examples

isExactlyThree(4) ➞ true
// 4 has only 3 divisors: 1, 2 and 4

isExactlyThree(12) ➞ false
// 12 has 6 divisors: 1, 2, 3, 4, 6, 12

isExactlyThree(25) ➞ true
// 25 has only 3 divisors: 1, 5, 25

Notes

1 ≤ n ≤ 10^12

*/

package main

func main() {
	assert(three(0) == false)
	assert(three(4) == true)
	assert(three(12) == false)
	assert(three(25) == true)
	assert(three(121) == true)
	assert(three(48) == false)
	assert(three(1) == false)
	assert(three(81) == false)
	assert(three(1521) == false)
	assert(three(225) == false)
	assert(three(27550356289) == true)
	assert(three(25235235235) == false)
	assert(three(10) == false)
	assert(three(64) == false)
	assert(three(9) == true)
	assert(three(144) == false)
	assert(three(3) == false)
	assert(three(2) == false)
	assert(three(42351351) == false)
	assert(three(999966000289) == true)
	assert(three(20152357681) == true)
	assert(three(531625249) == true)
	assert(three(264306808866) == false)
	assert(three(975179493674) == false)
	assert(three(49) == true)
	assert(three(165983) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func three(n uint64) bool {
	return divisors(n) == 3
}

// https://www2.math.upenn.edu/~deturck/m170/wk2/numdivisors.html
// To calculate how many divisors a number has, take all the exponents in the prime factorization,
// add 1 to each, and then multiply these "exponents + 1"s together.
func divisors(n uint64) uint64 {
	p := factor(n)
	v := 1
	for i := 0; i < len(p); {
		j := i + 1
		for ; j < len(p); j++ {
			if p[i] != p[j] {
				break
			}
		}
		v *= (j - i + 1)
		i = j
	}
	return uint64(v)
}

func factor(n uint64) (f []uint64) {
	if n == 1 {
		return []uint64{1}
	}
	for i := uint64(2); i <= n; i++ {
		for n%i == 0 {
			n /= i
			f = append(f, i)
		}
	}
	return
}
