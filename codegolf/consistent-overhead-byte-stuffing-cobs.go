/*

I'm surprised this hasn't been posted before!

The Consistent Overhead Byte Stuffing (COBS) algorithm is used to delimit byte streams.

We choose a frame marker (we'll use 0x00) and wherever 0x00 occurs in the stream it is replaced with the number of bytes until the next 0x00 occurs (we'll call this a milestone). This reduces the range of values from 0..255 to 1..255, enabling 0x00 to unambiguously delimit frames in the stream.
At a milestone, if the next 255B does not contain 0x00 this exceeds the maximum milestone length - the algorithm must 'stall' at 255B and put another milestone. This is the 'consistent overhead'.
The first byte will be the first milestone, the final milestone will be the number of bytes until the frame marker.

Some examples from Wikipedia (best to read the article where they are coloured):

0x00 as frame marker

Unencoded data (hex)    Encoded with COBS (hex)
00                      01 01 00
00 00                   01 01 01 00
11 22 00 33             03 11 22 02 33 00
11 22 33 44             05 11 22 33 44 00
11 00 00 00             02 11 01 01 01 00
01 02 03 ... FD FE      FF 01 02 03 ... FD FE 00
00 01 02 ... FC FD FE   01 FF 01 02 ... FC FD FE 00
01 02 03 ... FD FE FF   FF 01 02 03 ... FD FE 02 FF 00
02 03 04 ... FE FF 00   FF 02 03 04 ... FE FF 01 01 00
03 04 05 ... FF 00 01   FE 03 04 05 ... FF 02 01 00

Challenge: to implement this in the shortest program.

    Input is an unencoded byte stream/array, output is an encoded byte stream/array
    Use any sort of binary standard input/output
    The final frame marker is not necessary
    The program can return an oversized array
    A stream ending with 254 non-zero bytes does not require the trailing 0x00

Notes

    The worst-case return length is numBytes + (numBytes / 254) + 1

Example

We have the byte array

[0] 0x01
[1] 0x02
[2] 0x00
[3] 0x03
[4] 0x04
[5] 0x05
[6] 0x00
[7] 0x06

For each 0x00 we need to state (in a milestone) where the next 0x00 would have been.

[0] 0x03   #Milestone. Refers to the original [2] - "The next 0x00 is in 3B"
[1] 0x01   #Original [0]
[2] 0x02   #Original [1]
[3] 0x04   #Milestone. Refers to the original [6] - "The next 0x00 is in 4B"
[4] 0x03   #
[5] 0x04   #
[6] 0x05   # Originals [3..5]
[7] 0x02   #Milestone. Refers to the end frame marker
[8] 0x06   #Original [7]
[9] 0x00   #Optional. End frame marker.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(
		[]byte{0x01, 0x02, 0x00, 0x03, 0x04, 0x05, 0x00, 0x06},
		[]byte{0x03, 0x01, 0x02, 0x04, 0x03, 0x04, 0x05, 0x02, 0x06, 0x00},
	)

	test(
		[]byte{0x00},
		[]byte{0x01, 0x01, 0x00},
	)

	test(
		[]byte{0x00, 0x00},
		[]byte{0x01, 0x01, 0x01, 0x00},
	)

	test(
		[]byte{0x11, 0x22, 0x00, 0x33},
		[]byte{0x03, 0x11, 0x22, 0x02, 0x33, 0x00},
	)

	test(
		[]byte{0x11, 0x00, 0x00, 0x00},
		[]byte{0x02, 0x11, 0x01, 0x01, 0x01, 0x00},
	)

	test(
		[]byte{},
		[]byte{0x01, 0x00},
	)

	in := make([]byte, 0xfe)
	out := make([]byte, len(in)+2)
	for i := range in {
		in[i] = byte(i) + 1
		out[i+1] = byte(i) + 1
	}
	out[0] = 0xff
	test(in, out)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(src, res []byte) {
	dst := make([]byte, 2*len(src)+2)
	dec := make([]byte, len(dst))
	dst = cobsenc(src, dst)
	dec = cobsdec(dst, dec)

	fmt.Println(src)
	fmt.Println(dst)
	fmt.Println(dec)
	fmt.Println()
	assert(reflect.DeepEqual(res, dst))
	assert(reflect.DeepEqual(src, dec))
}

func cobsenc(src, dst []byte) []byte {
	p := 0
	j := 1
	c := uint8(1)
	for i := 0; i < len(src); i++ {
		if src[i] != 0 {
			dst[j], j = src[i], j+1
			c++
		}

		if src[i] == 0 || c == 0xff {
			dst[p], c, p = c, 1, j
			if src[i] == 0 || i+1 < len(src) {
				j++
			}
		}
	}
	dst[p], dst[j], j = c, 0, j+1
	return dst[:j]
}

func cobsdec(src, dst []byte) []byte {
	c := uint8(0xff)
	b := uint8(0x00)
	j := 0
	for i := 0; i < len(src); b-- {
		if b != 0 {
			dst[j], j, i = src[i], j+1, i+1
		} else {
			if c != 0xff {
				dst[j], j = 0, j+1
			}

			b, c, i = src[i], src[i], i+1
			if c == 0 {
				break
			}
		}
	}
	if j > 0 && dst[j-1] == 0 {
		j--
	}
	return dst[:j]
}
