/*

Implement the MT19937 Mersenne Twister RNG

You can get the psuedocode for this from Wikipedia.

If you're writing in Python, Ruby, or (gah) PHP, your language is probably already giving you MT19937 as "rand()"; don't use rand(). Write the RNG yourself.

*/

package main

import "fmt"

func main() {
	const times = 1000

	mt := NewMT19937()
	mt.Seed(19937)
	fmt.Printf("%d outputs of uint32()\n", times)
	for i := 0; i < times; i++ {
		fmt.Printf("%10d ", mt.Uint32())
		if i%5 == 4 {
			fmt.Println()
		}
	}
}

// ported from http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/MT2002/CODES/mt19937ar.c
const (
	N          = 624
	M          = 397
	MATRIX_A   = 0x9908b0df
	UPPER_MASK = 0x80000000
	LOWER_MASK = 0x7fffffff
)

type MT19937 struct {
	mt  []uint64
	mti int
}

func NewMT19937() *MT19937 {
	return &MT19937{
		mt:  make([]uint64, N),
		mti: N + 1,
	}
}

func (c *MT19937) Seed(s uint64) {
	c.mt[0] = s & 0xffffffff
	c.mti = N
	for i := uint64(1); i < uint64(len(c.mt)); i++ {
		c.mt[i] = (1812433253*(c.mt[i-1]^(c.mt[i-1]>>30)) + i)
		c.mt[i] &= 0xffffffff
	}
}

func (c *MT19937) Uint32() uint32 {
	y := uint64(0)
	mag01 := [2]uint64{0, MATRIX_A}
	if c.mti >= N {
		if c.mti == N+1 {
			c.Seed(5489)
		}

		kk := 0
		for kk = 0; kk < N-M; kk++ {
			y = (c.mt[kk] & UPPER_MASK) | (c.mt[kk+1] & LOWER_MASK)
			c.mt[kk] = c.mt[kk+M] ^ (y >> 1) ^ mag01[y&0x1]
		}

		for ; kk < N-1; kk++ {
			y = (c.mt[kk] & UPPER_MASK) | (c.mt[kk+1] & LOWER_MASK)
			c.mt[kk] = c.mt[kk+(M-N)] ^ (y >> 1) ^ mag01[y&0x1]
		}

		y = (c.mt[N-1] & UPPER_MASK) | (c.mt[0] & LOWER_MASK)
		c.mt[N-1] = c.mt[M-1] ^ (y >> 1) ^ mag01[y&0x1]

		c.mti = 0
	}

	y = c.mt[c.mti]
	c.mti++

	y ^= (y >> 11)
	y ^= (y << 7) & 0x9d2c5680
	y ^= (y << 15) & 0xefc60000
	y ^= (y >> 18)

	return uint32(y)
}
