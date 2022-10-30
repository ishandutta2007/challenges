/*

Unlolify a lolified message!

I had to ask a coworker if they wanted to have lunch with me, but we're both hackers so it could not be in a lame way. The message asking that was roughly this:

    please respond with 011110010110010101110011 if you'd like to join lunch today

The colleague being a hacker, just responded with 0x796573, to which I responded back:

    0x636f6f6c2c206e696365

To save my colleague the trouble of unlolifying it, I wrote a Ruby function to unlolify and sent it along with the message. But the function itself was way more lengthier than the lolified message itself. I'd like to have a better alternative in the future and be able to send a much shorter unlolify function.

Can someone help me? :-)
The challenge

A lolified message (valid examples above) is just an integer number. Unlolify it by first getting the binary string representation of the number, then left-padding it with the character 0 (zero) as many times as necessary so that the string length is a multiple of 8. Then take each sequence of 8 digits (from left to right) and convert each one of them to its corresponding ASCII character (the digits form a binary representation of an integer). Finally, put together all the resulting characters so that they represent a text string.

The challenge is to write the code of the function unlolify, which takes a positive integer number as input and outputs the unlolified string.

For example, the lolified hexadecimal number 636f6f6c2c206e696365 will output the string cool, nice.

Rules:

    Output strings will always contain only ASCII characters. Thus, each character is exactly one byte long
    The number of bits of the input can be arbitrarily high
    The input must be a positive integer number (input > 0)

Standard code-golf rules apply.


*/

package main

import (
	"bytes"
	"fmt"
	"math/big"
	"strconv"
	"strings"
)

func main() {
	test("796573", "yes")
	test("636f6f6c2c206e696365", "cool, nice")
}

func test(s, r string) {
	p := unlolify(xint(s))
	fmt.Println(p)
	assert(p == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func unlolify(n *big.Int) string {
	s := fmt.Sprintf("%b", n)
	p := ((len(s) + 7) & ^7) - len(s)
	s = strings.Repeat("0", p) + s

	w := new(bytes.Buffer)
	for i := 0; i < len(s); i += 8 {
		v, _ := strconv.ParseInt(s[i:i+8], 2, 64)
		w.WriteByte(byte(v))
	}
	return w.String()
}

func xint(s string) *big.Int {
	x := new(big.Int)
	x.SetString(s, 16)
	return x
}
