// https://www.cs.princeton.edu/courses/archive/spring03/cs126/assignments/mariner.html
package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())

	testprop()

	// total correction all the time
	testcor(1, 0, 10)
	testcor(1, 0, 11)
	testcor(1, 23, 24)
	testcor(1, 27, 29)
	testcor(1, 12, 18)

	// starts to fail at if more bits are flipped
	// or the location if the flipped is bad
	testcor(1, 18, 29)
	testcor(1, 20, 31)
	testcor(.5, 0, 20)
	testcor(1, 0, 13)

	testcor(.1, 0, 32)
	testcor(.3, 0, 32)
	testcor(.4, 0, 32)
	testcor(.5, 0, 32)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// test properties of a hadamard matrix
func testprop() {
	// each row of a hadamard matrix will differ from another
	// by n/2 entries where n is the size of the matrix
	// this allows us alot of redundancy for error correcting
	for n := 1; n <= 1024; n <<= 1 {
		H := hadamard(n)
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if i != j {
					assert(hamming(H[i], H[j]) == n/2)
				}
			}
		}
	}
}

// test if we can error correct in the presence of error
func testcor(epr float64, lobits, hibits int) {
	dx, dy := 640, 640

	// the original image is a 5 bit grayscale
	g := newgray(dx, dy)

	// when we transmit the image, encode it as indices of the hadamard matrix
	r := encode(g)

	// on transmission, we can encounter some errors and some bits can be flipped
	p := perturb(r, epr, lobits, hibits)

	// try to recover it now
	h := decode(p)
	m := 0
	for i := range g {
		for j := range g {
			if g[i][j] != h[i][j] {
				m++
			}
		}
	}
	fmt.Printf("epr: %f bits: (%d,%d) total mismatch %f\n", epr, lobits, hibits, float64(m)/float64(dx*dy))
}

// perturb the values based on some probability
func perturb(r [][]uint32, x float64, lo, hi int) [][]uint32 {
	p := make([][]uint32, len(r))
	for i := range p {
		p[i] = append(p[i], r[i]...)
	}

	for i := range p {
		for j := range p[i] {
			for b := lo; b < hi; b++ {
				if rand.Float64() <= x {
					p[i][j] ^= (1 << b)
				}
			}
		}
	}
	return p
}

func hamming(x, y []uint8) int {
	n := 0
	for i := range x {
		if x[i] != y[i] {
			n++
		}
	}
	return n
}

// 5 bit grayscale
func newgray(w, h int) [][]uint8 {
	g := make([][]uint8, h)
	for i := range g {
		g[i] = make([]uint8, w)
	}

	for i := range g {
		for j := range g[i] {
			g[i][j] = uint8(rand.Intn(32))
		}
	}
	return g
}

// use a 32x32 hadamard matrix with the 5 bit grayscale values
// as indices for the encoding
func encode(p [][]uint8) [][]uint32 {
	H := hadamard(32)
	m := make([][]uint32, len(p))
	for i := range m {
		m[i] = make([]uint32, len(p[i]))
	}

	for i := range m {
		for j := range m[i] {
			m[i][j] = comb(H[p[i][j]])
		}
	}
	return m
}

// to decode use the hadamard matrix on the values receieved
// and pick the index that most closely matches the value
// that index will be the decoded value
func decode(p [][]uint32) [][]uint8 {
	H := hadamard(32)
	g := make([][]uint8, len(p))
	for i := range g {
		g[i] = make([]uint8, len(p[i]))
	}

	for i := range p {
		for j := range p {
			v := split(p[i][j])
			d := math.MaxInt32
			for k := range H {
				dn := hamming(v, H[k])
				if dn < d {
					g[i][j] = uint8(k)
					d = dn
				}
			}
		}
	}
	return g
}

func comb(p []uint8) uint32 {
	v := uint32(0)
	for i := range p {
		v |= uint32(p[i]) << i
	}
	return v
}

func split(v uint32) []uint8 {
	p := make([]uint8, 32)
	for i := range p {
		if v&(1<<i) != 0 {
			p[i] = 1
		}
	}
	return p
}

// https://en.wikipedia.org/wiki/Hadamard_matrix
// sylvester's construction (only works for orders H_2^k)
func hadamard(n int) [][]uint8 {
	if n <= 0 || n&(n-1) != 0 {
		return nil
	}

	p := [][]uint8{{1}}
	for i := 2; i <= n; i <<= 1 {
		q := make([][]uint8, i)
		for j := range q {
			q[j] = make([]uint8, i)
		}

		l := len(p)
		for j := range p {
			for k := range p {
				q[j][k] = p[j][k]
				q[j][l+k] = p[j][k]
				q[l+j][k] = p[j][k]
				q[l+j][l+k] = p[j][k] ^ 1
			}
		}

		p = q
	}
	return p
}

func dump(m [][]uint8) {
	for i := range m {
		for j := range m[i] {
			fmt.Printf("%v", m[i][j])
		}
		fmt.Println()
	}
}
