/*

Every number can be expressed as the sum between unique powers of two.
For example, the number 21 can be expressed as 1 + 4 + 16, which can also be written as 2^0 + 2^2 + 2^4.

Create a function that returns a sorted list of powers of two, which add together to make n.

Examples

sumsPowersTwo(21) ➞ [1, 4, 16]

sumsPowersTwo(8) ➞ [8]

sumsPowersTwo(63) ➞ [1, 2, 4, 8, 16, 32]

Notes

Tests will only include positive whole numbers.

*/

package main

import (
	"math/bits"
	"reflect"
)

func main() {
	test(1, []uint{1})
	test(5, []uint{1, 4})
	test(7, []uint{1, 2, 4})
	test(8, []uint{8})
	test(10, []uint{2, 8})
	test(21, []uint{1, 4, 16})
	test(53, []uint{1, 4, 16, 32})
	test(63, []uint{1, 2, 4, 8, 16, 32})
	test(99, []uint{1, 2, 32, 64})
	test(100, []uint{4, 32, 64})
	test(556846320, []uint{16, 32, 64, 128, 1024, 2048, 16384, 32768, 1048576, 2097152, 16777216, 536870912})
	test(509104470, []uint{2, 4, 16, 64, 256, 4096, 16384, 524288, 1048576, 4194304, 33554432, 67108864, 134217728, 268435456})
	test(929640411, []uint{1, 2, 8, 16, 64, 128, 256, 512, 1024, 2048, 8192, 65536, 524288, 2097152, 4194304, 16777216, 33554432, 67108864, 268435456, 536870912})
	test(341971175, []uint{1, 2, 4, 32, 64, 128, 4096, 131072, 2097152, 4194304, 67108864, 268435456})
	test(329418410, []uint{2, 8, 32, 128, 512, 1024, 32768, 131072, 2097152, 8388608, 16777216, 33554432, 268435456})
}

func test(n uint, r []uint) {
	p := spot(n)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func spot(n uint) []uint {
	var p []uint
	for n != 0 {
		p = append(p, 1<<bits.TrailingZeros(n))
		n &= n - 1
	}
	return p
}
