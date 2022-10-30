/*

Submit a well-formed program or function with usual I/O rules which satisfy the input, output, and algorithm conditions below. Shortest submission (in bytes) wins. As always, standard loopholes are forbidden.

In short: Two distinct 8-bit integer inputs must produce two 8-bit integer outputs so that all four numbers are distinct, i.e., not equal.
Input Conditions

Two distinct 8-bit integers, a and b, both of which are in 8-bit signed (or unsigned at your discretion) format.
Output Conditions

Two 8-bit integers, c and d, which are in the same format as the input (signed or unsigned), such that a, b, c, and d are distinct, i.e., no two of them are equal to each other.
Algorithm Conditions

    The algorithm must halt for all possible valid inputs.
        Valid inputs are those where a and b are distinct. When a and b are equal, the behaviour of the algorithm is unspecified.
    The algorithm must be deterministic.
        Running the algorithm with the same input must produce the same output.
    The algorithm must satisfy the output conditions for all valid inputs.

Verification

There are two ways to verify your algorithm.

    Brute force: explicitly check the program for all valid input combinations.
    Prove/show, by analysis, that a clash is impossible (preferred).

FAQ

    What if my programming language doesn't provide 8-bit integers?

    What if my programming language doesn't support fixed-width integers?
        Only the range of the outputs matter; internal computations may be in any precision. If the outputs can be rounded/scaled to the required integral range, then the programming language is good to go.

*/

package main

func main() {
	for a := 0; a < 256; a++ {
		for b := 0; b < 256; b++ {
			if a != b {
				c, d := distinct(uint8(a), uint8(b))
				assert(valid(uint8(a), uint8(b), c, d))
			}
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func valid(a, b, c, d uint8) bool {
	p := [4]uint8{a, b, c, d}
	for i := range p {
		for j := range p {
			if i != j && p[i] == p[j] {
				return false
			}
		}
	}
	return true
}

func distinct(a, b uint8) (c, d uint8) {
	for c == a || c == b {
		c++
	}
	for d == a || d == b || d == c {
		d++
	}
	return
}
