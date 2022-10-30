/*

Crack an MT19937 seed

Make sure your MT19937 accepts an integer seed value. Test it (verify that you're getting the same sequence of outputs given a seed).

Write a routine that performs the following operation:

    Wait a random number of seconds between, I don't know, 40 and 1000.
    Seeds the RNG with the current Unix timestamp
    Waits a random number of seconds again.
    Returns the first 32 bit output of the RNG.

You get the idea. Go get coffee while it runs. Or just simulate the passage of time, although you're missing some of the fun of this exercise if you do that.

From the 32 bit RNG output, discover the seed.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())

	t := time.Now().Unix()
	t += randr(40, 1000)
	seed := t
	mt := NewMT19937()
	mt.Seed(uint64(seed))
	t += randr(40, 1000)
	x := mt.Uint32()

	// the idea here is that in real life some service
	// will generate a random number at some time "t" using the time as a seed
	// but since this is a deterministic PRNG, we just walk backwards
	// in time since an attacker would probably know the time of the machine
	// and then discover the seed
	xm := NewMT19937()
	for i := int64(0); i < 2048; i++ {
		xseed := uint64(t - i)
		xm.Seed(xseed)
		y := xm.Uint32()
		if x == y {
			fmt.Println(t-i, seed)
			break
		}
	}
}

func randr(min, max int64) int64 {
	return min + int64(rand.Intn(int(max-min+1)))
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

func (c *MT19937) SeedArray(a []uint64) {
	copy(c.mt[:], a)
	c.mti = N
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
