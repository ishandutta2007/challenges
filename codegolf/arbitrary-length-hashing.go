/*

Consider you have a hash function H which takes strings of length 2n and returns strings of length n and has the nice property that it is collision resistant, i.e. it is hard to find two different strings s≠s′ with the same hash H(s)=H(s′).

You would now like to build a new hash function H′ which takes strings of arbitrary length and maps them to strings of length n, while still being collision resistant.

Lucky for you, already in 1979 a method now known as the Merkle–Damgård construction was published which achieves exactly this.

The task of this challenge will be to implement this algorithm, so we'll first have a look at a formal description of the Merkle–Damgård construction,
before going through a step-by-step example which should show that the approach is simpler than it might appear at first.

Given some integer n>0, a hash function H as described above and an input string s of arbitrary length, the new hash function H′ does the following:

Set l=|s|, the length of s, and split s in chunks of length n, filling up the last chunk with trailing zeros if necessary. This yields m=⌈ln⌉ many chunks which are labeled c1,c2,…,cm.
Add a leading and a trailing chunk c0 and c[m+1], where c0 is a string consisting of n zeros and c[m+1] is n in binary, padded with leading zeros to length n.
Now iteratively apply H to the current chunk ci appended to the previous result r[i-1]: r[i]=H(r[i-1]c[i]), where r0=c0. (This step might be more clear after looking at the example below.)
The output of H′ is the final result r[m+1].

The Task
Write a program or function which takes as input a positive integer n, a hash function H as black box and a non-empty string s and returns the same result as H′ on the same inputs.

This is code-golf, so the shortest answer in each language wins.

Example
Let's say n=5, so our given hash function H takes strings of length 10 and returns strings of length 5.

Given an input of s="Programming Puzzles", we get the following chunks: s1="Progr", s2="ammin", s3="g Puz" and s4="zles0". Note that s4 needed to be padded to length 5 with one trailing zero.
c0="00000" is just a string of five zeros and c5="00101" is five in binary (101), padded with two leading zeros.
Now the chunks are combined with H:
r0=c0="00000"
r1=H(r0c1)=H("00000Progr")
r2=H(r1c2)=H(H("00000Progr")"ammin")
r3=H(r2c3)=H(H(H("00000Progr")"ammin")"g Puz")
r4=H(r3c4)=H(H(H(H("00000Progr")"ammin")"g Puz")"zles0")
r5=H(r4c5)=H(H(H(H(H("00000Progr")"ammin")"g Puz")"zles0")"00101")
r5 is our output.
Let's have a look how this output would look depending on some choices1 for H:

If H("0123456789")="13579", i.e. H just returns every second character, we get:
r1=H("00000Progr")="00Por"
r2=H("00Porammin")="0oamn"
r3=H("0oamng Puz")="omgPz"
r4=H("omgPzzles0")="mPze0"
r5=H("mPze000101")="Pe011"
So "Pe011" needs to be the output if such a H is given as black box function.
If H simply returns the first 5 chars of its input, the output of H′ is "00000". Similarly if H returns the last 5 chars, the output is "00101".
If H multiplies the character codes of its input and returns the first five digits of this number, e.g. H("PPCG123456")="56613", then H′("Programming Puzzles")="91579".
1 For simplicity, those H are actually not collision resistant, though this does not matter for testing your submission.

*/

package main

import (
	"bytes"
	"fmt"
	"math/big"
	"strings"
)

func main() {
	assert(md(hash1, "Programming Puzzles", 5) == "Pe011")
	assert(md(hash2, "Programming Puzzles", 5) == "00000")
	assert(md(hash3, "Programming Puzzles", 5) == "00101")
	assert(md(hash4, "Programming Puzzles", 5) == "91579")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func md(h Hash, s string, n int) string {
	l := roundup(len(s), n)
	r := chunk(s, 0, n)
	for i := 1; i <= l+1; i++ {
		r = h(r + chunk(s, i, n))
		if len(r) != n {
			panic("length of current hash is not valid")
		}
	}
	return r
}

func roundup(x, n int) int {
	r := x % n
	if r != 0 {
		r = 1
	}
	return x/n + r
}

func chunk(s string, i, n int) string {
	if i == 0 || i >= n {
		return fmt.Sprintf("%0*b", n, i)
	}

	l := len(s)
	a := (i - 1) * n
	b := a + n
	if a >= l {
		return strings.Repeat("0", n)
	}
	if b > l {
		b = l
	}

	r := s[a:b]
	m := len(r)
	if m < n {
		r += strings.Repeat("0", n-m)
	}
	return r
}

func hash1(s string) string {
	w := new(bytes.Buffer)
	for i := 1; i < len(s); i += 2 {
		w.WriteByte(s[i])
	}
	return w.String()
}

func hash2(s string) string {
	n := len(s)
	if n > 5 {
		n = 5
	}
	return s[:n]
}

func hash3(s string) string {
	l := len(s)
	n := 5
	if n > l {
		n = l
	}
	return s[l-n:]
}

func hash4(s string) string {
	x := big.NewInt(1)
	for i := 0; i < len(s); i++ {
		x.Mul(x, big.NewInt(int64(s[i])))
	}
	r := x.String()
	if len(r) > 5 {
		r = r[:5]
	}
	return r
}

type Hash func(string) string
