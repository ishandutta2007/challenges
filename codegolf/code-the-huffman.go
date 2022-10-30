/*

Or else he will huff and puff and blow your house down!

That was completely irrelevant. This challenge is actually about Huffman coding. The gist of it is the frequency of characters in a given text is utilized to make its representation shorter.
In other words, let's say that our alphabet is a through z and space. That's 27 characters. Each of them can be uniquely encoded in just 5 bits because 5 bits have enough room for 32 characters.
However, in many situations (like English, or languages in general), some characters are more frequent than others.
We can use fewer bits for the more frequent characters and (perhaps) more bits for the less frequent characters.
Done right, there is an overall savings in the number of bits and the original text can still be uniquely reconstructed.

Let's take "this question is about huffman coding" as an example. This text is 37 characters long, which would be 37*8 = 296 bits normally, though only 37*5 = 185 bits if we only use 5 bits for each character. Keep that in mind.

Here is a (sorta) table of each character and their frequencies in the text, sorted from most to least frequent (where _ stands in for a space):

_ 5
i 4
n 3
o 3
s 3
t 3
u 3
a 2
f 2
h 2
b 1
c 1
d 1
e 1
g 1
m 1
q 1

An associated optimal coding could be:

_ 101
i 011
n 1100
o 1101
s 1110
t 1111
u 001
a 10011
f 0001
h 0101
b 00000
c 00001
d 01000
e 01001
g 10000
m 10001
q 10010

It should be immediately clear that this will be a better encoding than just using 5 bits for every character. Let's find out just how much better, though!

145 bits, compared with 185! That's a savings of 40 bits, or just over 20%! (This is, of course, assuming that information about the structure is available for decoding.) This coding is optimal because no more bits can be dropped by changing any character's representation.
The task

    Write a program or function with one parameter that...
    Takes input from STDIN (or equivalent) or as a single argument.
    Output an optimal Huffman coding as above with the characters sorted by frequency (order within a frequency class doesn't matter).
    You may assume that the characters in the input are restricted to the ASCII range 32..126 plus a newline.
    You may assume the input is no longer than 10,000 characters (ideally, in theory, input should be unbounded).
    Your code should finish reasonably fast. The given example above should take no more than a minute or so at worst. (This is intended to rule out brute force.)
    Scoring is in bytes.

Examples

x
---
x 0

xxxxxxxxx
---
x 0

xxxxxxxxy
---
x 0
y 1 (these may be swapped)

xxxxxyyyz
---
x 0
y 10
z 11

uuvvwwxxyyzz
---   (or)
u 000      000
v 001      001
w 100      010
x 101      011
y 01       10
z 11       11

this question is about huffman coding
---
  101
i 011
n 1100
o 1101
s 1110
t 1111
u 001
a 10011
f 0001
h 0101
b 00000
c 00001
d 01000
e 01001
g 10000
m 10001
q 10010

Happy coding!

Note that this similar question is closely related, even to the point that this one is a duplicate. However, the consensus so far on Meta is that the older one should be considered a duplicate of this one.

*/

package main

import (
	"container/heap"
	"fmt"
	"math/big"
	"sort"
	"unicode/utf8"
)

func main() {
	test("aaaabbbccd")
	test("x")
	test("xxxxxxxxx")
	test("xxxxxxxxy")
	test("xxxxxyyyz")
	test("uuvvwwxxyyzz")
	test("this question is about huffman coding")
	test("abcdefghijklmnopqrstuvwxyz")
	test("blah blah blah blah kolmogorov blah blah complexity")
}

func test(s string) {
	t := huffman(s)
	output(s, t)
}

func output(s string, t *Sym) {
	var y []Sym
	encode(t, &y, "")
	sort.Slice(y, func(i, j int) bool {
		return len(y[i].Encoding) < len(y[j].Encoding)
	})

	uc, hc := cost(s, y)
	fmt.Printf("%q utf8: %d bits huffman: %d bits\n", s, uc, hc)
	fmt.Printf("Huffman Encoding\n")
	fmt.Printf("----------------\n")
	for _, y := range y {
		fmt.Printf("%q %s\n", y.Char, y.Encoding)
	}
	fmt.Println()
	fmt.Println()
}

func cost(s string, y []Sym) (uc, hc int) {
	m := make(map[rune]int)
	for _, y := range y {
		m[y.Char] = len(y.Encoding)
	}

	for _, r := range s {
		uc += utf8.RuneLen(r) * 8
		hc += m[r]
	}
	return
}

func encode(n *Sym, y *[]Sym, p string) {
	if n == nil {
		return
	}

	if n.Left == nil && n.Right == nil {
		if p == "" {
			p = "0"
		}

		*y = append(*y, Sym{Char: n.Char, Encoding: p})
		return
	}

	encode(n.Left, y, p+"0")
	encode(n.Right, y, p+"1")
}

type Sym struct {
	Char     rune
	Encoding string
	Weight   *big.Rat
	Left     *Sym
	Right    *Sym
}

func huffman(s string) *Sym {
	p := mksym(s)
	h := new(Hist)
	heap.Init(h)
	for i := range p {
		heap.Push(h, &p[i])
	}

	for h.Len() > 1 {
		x := heap.Pop(h).(*Sym)
		y := heap.Pop(h).(*Sym)

		w := new(big.Rat)
		w.Add(x.Weight, y.Weight)

		heap.Push(h, &Sym{
			Weight: w,
			Left:   x,
			Right:  y,
		})
	}

	var r *Sym
	if h.Len() > 0 {
		r = h.Pop().(*Sym)
	}
	return r
}

func mksym(s string) []Sym {
	m := make(map[rune]int)
	n := 0
	for _, r := range s {
		m[r]++
		n++
	}

	var p []Sym
	for k, v := range m {
		p = append(p, Sym{Char: k, Weight: big.NewRat(int64(v), int64(n))})
	}

	return p
}

type Hist []*Sym

func (p Hist) Len() int { return len(p) }
func (p Hist) Less(i, j int) bool {
	n := p[i].Weight.Cmp(p[j].Weight)
	if n == 0 {
		return p[i].Char < p[j].Char
	}
	return n < 0
}

func (p Hist) Swap(i, j int) { p[i], p[j] = p[j], p[i] }

func (p *Hist) Push(x interface{}) { *p = append(*p, x.(*Sym)) }
func (p *Hist) Pop() interface{} {
	n := len(*p) - 1
	x := (*p)[n]
	*p = (*p)[:n]
	return x
}
