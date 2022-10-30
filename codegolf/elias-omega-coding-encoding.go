/*

Background

Elias omega coding is a universal code which can encode positive integers of any size into a stream of bits.

Given a positive integer N, the encoding algorithm is as follows:

Start with a single zero in the output.
If N=1, stop.
Prepend the binary digits of N to the current output.
Let N be the number of digits just prepended, minus one. Go back to step 2.
In Python-like pseudocode:

n = input()
s = "0"
while n > 1:
    # bin(n) is assumed to give a plain string of bits, without "0b" prefix
    s = bin(n) + s
    n = len(bin(n)) - 1
output(s)

Illustration

The number 1 gets encoded into a single 0.

The number 21 gets encoded into 10100101010, or 10 100 10101 0 in chunks, where each chunk is added to the output stream in the following order: first "0" by default, then the binary of 21, then 4 (the bit length of 21 minus 1), then 2, then stop.

Task

Given a positive integer N, output its Elias omega code.

You can take the input number N in any convenient format, including its representation in binary.

The output must be a valid representation of a flat stream of bits, which includes:

a plain string or array of zeros and ones, or
a single integer whose binary representation corresponds to the stream of bits.
Outputting the bits in reverse or outputting a nested structure of bits (e.g. ["10", "100", "10101", "0"] for 21) is not allowed.

Shortest code in bytes wins.

Test cases
N     => Omega(N)
1        0
2        100
3        110
4        101000
5        101010
6        101100
7        101110
8        1110000
12       1111000
16       10100100000
21       10100101010
100      1011011001000
345      1110001010110010
1000     11100111111010000
6789     11110011010100001010
10000    111101100111000100000
1000000  1010010011111101000010010000000

This is OEIS A281193.

*/

package main

import "fmt"

func main() {
	assert(encode(1) == "0")
	assert(encode(2) == "100")
	assert(encode(3) == "110")
	assert(encode(4) == "101000")
	assert(encode(5) == "101010")
	assert(encode(6) == "101100")
	assert(encode(7) == "101110")
	assert(encode(8) == "1110000")
	assert(encode(12) == "1111000")
	assert(encode(16) == "10100100000")
	assert(encode(21) == "10100101010")
	assert(encode(100) == "1011011001000")
	assert(encode(345) == "1110001010110010")
	assert(encode(1000) == "11100111111010000")
	assert(encode(6789) == "11110011010100001010")
	assert(encode(10000) == "111101100111000100000")
	assert(encode(1000000) == "1010010011111101000010010000000")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func encode(n uint) string {
	s := "0"
	for n > 1 {
		b := fmt.Sprintf("%b", n)
		s = b + s
		n = uint(len(b) - 1)
	}
	return s
}
