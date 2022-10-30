/*

Your task is pretty simple. Given two floats, bitwise xor the binary representation of them, and output that as a float.

For example,

Normal: 16.7472 ^ 123.61 = 7.13402e-37
Binary: 01000001100001011111101001000100 ^ 01000010111101110011100001010010 = 00000011011100101100001000010110

Normal: 2.2 ^ 4.4 = 1.17549e-38
Binary: 01000000000011001100110011001101 ^ 01000000100011001100110011001101 = 00000000100000000000000000000000

Normal: 7.898 ^ 3.4444 = 1.47705e-38
Binary: 01000000111111001011110001101010 ^ 01000000010111000110101001111111 = 00000000101000001101011000010101

Restrictions/clarifications:

    Input/output can be given by any convenient method.
    The program can be a full program or just a function; either is fine.
    The float type can be any size, but the minimum size is 2 bytes.
    Standard loopholes are forbidden.
    Shortest code wins.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(floatxor(16.7472, 123.61))
	fmt.Println(floatxor(2.2, 4.4))
	fmt.Println(floatxor(7.898, 3.4444))
}

func floatxor(x, y float32) float32 {
	a := math.Float32bits(x)
	b := math.Float32bits(y)
	return math.Float32frombits(a ^ b)
}
