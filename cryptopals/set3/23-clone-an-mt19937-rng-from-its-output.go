/*

Clone an MT19937 RNG from its output

The internal state of MT19937 consists of 624 32 bit integers.

For each batch of 624 outputs, MT permutes that internal state. By permuting state regularly, MT19937 achieves a period of 2**19937, which is Big.

Each time MT19937 is tapped, an element of its internal state is subjected to a tempering function that diffuses bits through the result.

The tempering function is invertible; you can write an "untemper" function that takes an MT19937 output and transforms it back into the corresponding element of the MT19937 state array.

To invert the temper transform, apply the inverse of each of the operations in the temper transform in reverse order. There are two kinds of operations in the temper transform each applied twice; one is an XOR against a right-shifted value, and the other is an XOR against a left-shifted value AND'd with a magic number. So you'll need code to invert the "right" and the "left" operation.

Once you have "untemper" working, create a new MT19937 generator, tap it for 624 outputs, untemper each of them to recreate the state of the generator, and splice that state into a new instance of the MT19937 generator.

The new "spliced" generator should predict the values of the original.
Stop and think for a second.
How would you modify MT19937 to make this attack hard? What would happen if you subjected each tempered output to a cryptographic hash?


*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	seed := rand.Uint32()
	mt := NewMT19937()
	mt.Seed(uint64(seed))

	var state [N]uint64
	for i := 0; i < len(state); i++ {
		state[i] = uint64(untemper(mt.Uint32()))
	}
	for i := 0; i < len(state); i++ {
		if state[i] != mt.mt[i] {
			fmt.Printf("state mismatch at %d: %#x %#x\n", i, state[i], mt.mt[i])
		}
	}

	// the mersenne generator ported from the authors starts outputting number one cycle
	// than the initial seed vector, so it is too hard to get the integer seed since we have
	// to undo the complex transformation every N cycles forward, so what we do is cheat and
	// and just seed the whole state, this way even though we don't know the integer seed,
	// we can duplicate the value, other solutions online just don't have it start one cycle
	// later so they can just get the seed by looking at the first entry of the table built
	xm := NewMT19937()
	xm.SeedArray(state[:])
	for i := 0; i < 1024; i++ {
		fmt.Println(i, mt.Uint32(), xm.Uint32())
	}
}

// https://jazzy.id.au/2010/09/22/cracking_random_number_generators_part_3.html
// describes the idea on how to break it, since mersenne twister generate
// numbers from a lut and then applying a series of xor/rsh/lsh on them
// before returning the value, we can just undo the xor/rsh/lsh operations
// to get the table values
func untemper(value uint32) uint32 {
	value = unrshxor(value, 18)
	value = unlshxor(value, 15, 0xefc60000)
	value = unlshxor(value, 7, 0x9d2c5680)
	value = unrshxor(value, 11)
	return value
}

func unrshxor(value uint32, shift uint) uint32 {
	i := uint(0)
	result := uint32(0)
	for ; i*shift < 32; i++ {
		mask := (^uint32(0) << (32 - shift)) >> (shift * i)
		part := value & mask
		value ^= part >> shift
		result |= part
	}
	return result
}

func unlshxor(value uint32, shift uint, mask uint32) uint32 {
	i := uint(0)
	result := uint32(0)
	shiftmask := uint32((1 << shift) - 1)
	for ; i*shift < 32; i++ {
		partmask := shiftmask << (shift * i)
		part := value & partmask
		value ^= (part << shift) & mask
		result |= part
	}
	return result
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
