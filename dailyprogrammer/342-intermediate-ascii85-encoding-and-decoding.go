/*

Description

The basic need for a binary-to-text encoding comes from a need to communicate arbitrary binary data over preexisting communications protocols that were designed to carry only English language human-readable text.
This is why we have things like Base64 encoded email and Usenet attachments - those media were designed only for text.

Multiple competing proposals appeared during the net's explosive growth days, before many standards emerged either by consensus or committee.
Unlike the well known Base64 algorithm, ASCII85 inflates the size of the original data by only 25%, as opposed to the 33% that Base64 does.

When encoding, each group of 4 bytes is taken as a 32-bit binary number, most significant byte first (Ascii85 uses a big-endian convention).
This is converted, by repeatedly dividing by 85 and taking the remainder, into 5 radix-85 digits.
Then each digit (again, most significant first) is encoded as an ASCII printable character by adding 33 to it, giving the ASCII characters 33 ("!") through 117 ("u").

Take the following example word "sure". Encoding using the above method looks like this:

Text	s	u	r	e
ASCII value	115	117	114	101
Binary value	01110011	01110101	01110010	01100101
Concatenate	01110011011101010111001001100101
32 bit value	1,937,076,837
Decomposed by 85	37x854	9x853	17x852	44x851	22
Add 33	70	42	50	77	55
ASCII character	F	*	2	M	7
So in ASCII85 "sure" becomes "F*2M7". To decode, you reverse this process. Null bytes are used in standard ASCII85 to pad it to a multiple of four characters as input if needed.

Your challenge today is to implement your own routines (not using built-in libraries, for example Python 3 has a85encode and a85decode) to encode and decode ASCII85.

(Edited after posting, a column had been dropped in the above table going from four bytes of input to five bytes of output. Fixed.)

Challenge Input

You'll be given an input string per line. The first character of the line tells your to encode (e) or decode (d) the inputs.

e Attack at dawn
d 87cURD_*#TDfTZ)+T
d 06/^V@;0P'E,ol0Ea`g%AT@
d 7W3Ei+EM%2Eb-A%DIal2AThX&+F.O,EcW@3B5\\nF/hR
e Mom, send dollars!
d 6#:?H$@-Q4EX`@b@<5ud@V'@oDJ'8tD[CQ-+T

Challenge Output
6$.3W@r!2qF<G+&GA[
Hello, world!
/r/dailyprogrammer
Four score and seven years ago ...
9lFl"+EM+3A0>E$Ci!O#F!1
All\r\nyour\r\nbase\tbelong\tto\tus!
(That last one has embedded control characters for newlines, returns, and tabs - normally nonprintable. Those are not literal backslashes.)

Credit

Thank you to user /u/JakDrako who suggested this in a recent discussion. If you have a challenge idea, please share it at r/dailyprogrammer_ideas and there's a chance we'll use it.

*/

package main

import (
	"encoding/ascii85"
	"fmt"
)

func main() {
	test('e', "Attack at dawn", "6$.3W@r!2qF<G+&GA[")
	test('d', "87cURD_*#TDfTZ)+T", "Hello, world!")
	test('d', "06/^V@;0P'E,ol0Ea`g%AT@", "/r/dailyprogrammer")
	test('d', "7W3Ei+EM%2Eb-A%DIal2AThX&+F.O,EcW@3B5\\nF/hR", "Four score and seven years ago ...")
	test('e', "Mom, send dollars!", "9lFl\"+EM+3A0>E$Ci!O#F!1")
	test('d', "6#:?H$@-Q4EX`@b@<5ud@V'@oDJ'8tD[CQ-+T", "All\r\nyour\r\nbase\tbelong\tto\tus!")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(op rune, s, r string) {
	p, err := encdec(op, s)
	fmt.Println(p)
	assert(err == nil)
	assert(p == r)
}

func encdec(op rune, s string) (string, error) {
	var err error
	n := ascii85.MaxEncodedLen(len(s))
	b := make([]byte, n)
	switch op {
	case 'e':
		n = ascii85.Encode(b, []byte(s))
	case 'd':
		n, _, err = ascii85.Decode(b, []byte(s), true)
	}
	return string(b[:n]), err
}
