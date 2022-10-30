/*

Create a function that takes in a positive integer n and returns the simplified square root of n as [_a_, _b_], where a⋅sqrt(b) = sqrt(n) and b is as small as possible.

Examples

simplifySqrt(72) ➞ [6, 2]

simplifySqrt(160) ➞ [4, 10]

simplifySqrt(36) ➞ [6, 1]

simplifySqrt(35) ➞ [1, 35]

A common way to simplify square roots is to repeatedly factor out perfect squares from the number underneath the square root.
For example, if you need to simply sqrt(72), you can factor out perfect squares from 72 according to the following process:

sqrt(72)

72 is divisible by 4, so factor 4 out of 72:

sqrt(4⋅18)

The perfect square 4 can now be square rooted and pulled out of the square root:

2⋅sqrt(18)

Now repeat the process until no further perfect squares can be factored out. 18 is divisible by 9, so factor it out:

2⋅sqrt(9⋅2)

Pull the 9 out, square root it, and simplify:

2⋅3⋅sqrt(2)

= 6⋅sqrt(2)

2 does not have any perfect square factors other than 1, so 6⋅sqrt(2) is the simplest form of sqrt(72). The function would therefore return [6, 2].

This is only one approach to solving this problem; there are probably other ways that are simpler/faster than this method. Feel free to use any method you want.
Notes

    If n is a perfect square, b should be 1.
    If n has no perfect square factors (other than 1), a should be 1.

*/

package main

func main() {
	assert(smsqrt(72) == [2]uint64{6, 2})
	assert(smsqrt(160) == [2]uint64{4, 10})
	assert(smsqrt(36) == [2]uint64{6, 1})
	assert(smsqrt(35) == [2]uint64{1, 35})
	assert(smsqrt(81) == [2]uint64{9, 1})
	assert(smsqrt(144) == [2]uint64{12, 1})
	assert(smsqrt(17) == [2]uint64{1, 17})
	assert(smsqrt(210) == [2]uint64{1, 210})
	assert(smsqrt(8) == [2]uint64{2, 2})
	assert(smsqrt(420) == [2]uint64{2, 105})
	assert(smsqrt(126) == [2]uint64{3, 14})
	assert(smsqrt(192) == [2]uint64{8, 3})
	assert(smsqrt(6300) == [2]uint64{30, 7})
	assert(smsqrt(100000) == [2]uint64{100, 10})
	assert(smsqrt(1) == [2]uint64{1, 1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func smsqrt(n uint64) (v [2]uint64) {
	v[0], v[1] = 1, 1
	p := factor(n)
	for i := 0; i < len(p); {
		j := i + 1
		for ; j < len(p); j++ {
			if p[i] != p[j] {
				break
			}
		}

		c := uint64(j - i)
		a := c >> 1
		b := c & 1
		for k := uint64(0); k < a; k++ {
			v[0] *= p[i]
		}
		if b != 0 {
			v[1] *= p[i]
		}

		i = j
	}
	return
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
