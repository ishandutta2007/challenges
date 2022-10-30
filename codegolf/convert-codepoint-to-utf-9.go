/*

UTF-9 was an April Fool's Day RFC joke specifications for encoding Unicode suitable for 9-bit nonet platforms.

Challenge

Your task is to implement a program or a function or a subroutine that takes one integer, who represents the codepoint of a character, to return a sequence of integers that represents its corresponding UTF-9 value.
Definition of UTF-9

In this problem, the definition of the UTF-9 shall be as follows:

From section 3 of RFC 4042:

    A UTF-9 stream represents [ISO-10646] codepoints using 9 bit nonets. The low order 8-bits of a nonet is an octet, and the high order bit indicates continuation.

    UTF-9 does not use surrogates; consequently a UTF-16 value must be transformed into the UCS-4 equivalent, and U+D800 - U+DBFF are never transmitted in UTF-9.

    Octets of the [UNICODE] codepoint value are then copied into successive UTF-9 nonets, starting with the most-significant non-zero octet. All but the least significant octet have the continuation bit set in the associated nonet.

Constraints

Input is nonnegative integers that is defined on Unicode: which is 0 to 0x7FFFFFFF (inclusive)
Rules

    Standard loopholes apply.
    Standard I/O rules apply.
    Shortest code wins.

Test cases

Leftmost column: Input in hexadecimal.

Right items: output as a sequence of octed integers.

0000     000
0041     101
00c0     300
0391     403 221
611b     541 033
10330    401 403 060
e0041    416 400 101
10fffd   420 777 375
345ecf1b 464 536 717 033

Hint Notes

Section 5.2 of RFC4042 has an example of the impmenentation.

Here is a non-competing Python function that represents the algorithm:

def ucs4utf9(x:int)->[int]:
 l=[]
 if x>0x100:
  if x>0x10000:
   if x>0x1000000:
    l.append(0x100|(x>>24)&0xff)
   l.append(0x100|(x>>16)&0xff)
  l.append(0x100|(x>>8)&0xff)
 l.append(x&0xff)
 return l

Test it online!

Those two programs were incorrect, as they convert codepoints 0x100, 0x10000, and 0x1000000 incorrectly; they should be converted to 257,0, 257,256,0, 257,256,256,0 respectively.

*/

package main

import (
	"reflect"
)

func main() {
	test(0x0, []uint16{000})
	test(0x41, []uint16{0101})
	test(0xc0, []uint16{0300})
	test(0x391, []uint16{0403, 0221})
	test(0x611b, []uint16{0541, 033})
	test(0x10330, []uint16{0401, 0403, 060})
	test(0xe0041, []uint16{0416, 0400, 0101})
	test(0x10fffd, []uint16{0420, 0777, 0375})
	test(0x345ecf1b, []uint16{0464, 0536, 0717, 033})
	test(0x100, []uint16{257, 0})
	test(0x10000, []uint16{257, 256, 0})
	test(0x1000000, []uint16{257, 256, 256, 0})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(r rune, p []uint16) {
	var b [4]uint16
	n := rune2utf9(r, b[:])
	assert(n == len(p) && reflect.DeepEqual(p, b[:n]))
}

func rune2utf9(r rune, b []uint16) int {
	i := 0
	switch {
	case r >= 0x1000000:
		b[i], i = 0x100|uint16((r>>24)&0xff), i+1
		fallthrough
	case r >= 0x10000:
		b[i], i = 0x100|uint16((r>>16)&0xff), i+1
		fallthrough
	case r >= 0x100:
		b[i], i = 0x100|uint16((r>>8)&0xff), i+1
		fallthrough
	default:
		b[i], i = uint16(r&0xff), i+1
	}
	return i
}
