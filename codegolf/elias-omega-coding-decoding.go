/*

Background

Elias omega coding is a universal code which can encode positive integers of any size into a stream of bits.

Given a stream of bits S, the decoding algorithm is as follows:

If S is empty, stop. Otherwise, let N=1.
Read the next bit b of S.
If b=0, output N and return to step 1.
Otherwise, b=1. Read N more bits from S, append to b, and convert it from binary to integer. This is the new value of N. Go back to step 2.
In Python-like pseudocode:

s = input()
while s.has_next():
    n = 1
    while (b = s.next()) == 1:
        loop n times:
            b = b * 2 + s.next()
        n = b
    output(n)

Illustration

If the given bit stream is 101001010100:

Initially N=1.
Since the first bit is 1, we read 1 more bit (2 bits in total) to get the new value of N=102=2. Now the stream is 1001010100.
Proceed as the same. Read a bit (1) and N=2 more bits to get N=1002=4. Stream: 1010100
Read a bit (1) and N=4 more bits to get N=101012=21. Stream: 00
Read a bit (0). Since it is 0, output the current N=21. The stream has more bits to be consumed, so we reset to N=1 and continue. Stream: 0
Read a bit (0). Output the current N=1. The stream is empty, and decoding is complete.
The output for the input stream 101001010100 is [21, 1].

Task
Given a stream of bits which consists of zero or more Elias omega coded integers, decode into the original list of integers. You can assume the input is valid (the input stream won't be exhausted in the middle of decoding a number).

Shortest code in bytes wins.

Test cases
Input => Output
(empty) => []
0       => [1]
00      => [1,1]
00100   => [1,1,2]
101001010100 => [21,1]
1110000111100001110000 => [8,12,1,8]
1111000111000101011001011110011010100001010 => [12,345,6789]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test("", []uint{})
	test("0", []uint{1})
	test("00", []uint{1, 1})
	test("00100", []uint{1, 1, 2})
	test("101001010100", []uint{21, 1})
	test("1110000111100001110000", []uint{8, 12, 1, 8})
	test("1111000111000101011001011110011010100001010", []uint{12, 345, 6789})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []uint) {
	p := decode(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func decode(s string) (p []uint) {
	defer func() {
		recover()
	}()

	p = []uint{}
	for len(s) > 0 {
		n := uint(1)
		for {
			var (
				c byte
				l = n
			)

			c, s = s[0], s[1:]
			if c != '1' {
				break
			}

			n = 1
			for i := uint(0); i < l; i++ {
				n = (n << 1) | uint(s[0]-'0')
				s = s[1:]
			}
		}
		p = append(p, n)
	}
	return
}
