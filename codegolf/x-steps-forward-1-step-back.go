/*

Here the first 100 numbers of an easy sequence:

0,1,0,2,1,4,3,7,6,11,10,16,15,22,21,29,28,37,36,46,45,56,55,67,66,79,78,92,91,106,105,121,120,137,136,154,153,172,171,191,190,211,210,232,231,254,253,277,276,301,300,326,325,352,351,379,378,407,406,436,435,466,465,497,496,529,528,562,561,596,595,631,630,667,666,704,703,742,741,781,780,821,820,862,861,904,903,947,946,991,990,1036,1035,1082,1081,1129,1128,1177,1176,1226
How does this sequence work?

n: 0 1     2           3     4     5     6     7     8      9       10      11      12

   0,      1-1=0,      2-1=1,      4-1=3,      7-1=6,       11-1=10,        16-1=15,
     0+1=1,      0+2=2,      1+3=4,      3+4=7,      6+5=11,        10+6=16,        15+7=22

	 a(0) = 0

For every odd n (0-indexed), it's a(n-1) + X (where X=1 and increases by 1 every time it's accessed)
For every even n (0-indexed), it's a(n-1) - 1

Challenge:
One of:

Given an input integer n, output the n'th number in the sequence.
Given an input integer n, output the first n numbers of the sequence.
Output the sequence indefinitely without taking an input (or taking an empty unused input).

Challenge rules:
Input n can be both 0- or 1-indexed.
If you output (part of) the sequence, you can use a list/array, print to STDOUT with any delimiter (space, comma, newline, etc.). Your call.
Please state which of the three options you've used in your answer.
You'll have to support at least the first 10,000 numbers (10,000th number is 12,497,501).

General rules:

This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.

Default Loopholes are forbidden.

If possible, please add a link with a test for your code.
Also, please add an explanation if possible.

Test cases:
Pastebin with the first 10,001 numbers in the sequence. Feel free to pick any you'd like.

Some higher numbers:

n (0-indexed)    Output:

68,690           589,772,340
100,000          1,249,975,000
162,207          3,288,888,857
453,271          25,681,824,931
888,888          98,765,012,346
1,000,000        124,999,750,000

*/

package main

func main() {
	tab := []int64{0, 1, 0, 2, 1, 4, 3, 7, 6, 11, 10, 16, 15, 22, 21, 29, 28, 37, 36, 46, 45, 56, 55, 67, 66, 79, 78, 92, 91, 106, 105, 121, 120, 137, 136, 154, 153, 172, 171, 191, 190, 211, 210, 232, 231, 254, 253, 277, 276, 301, 300, 326, 325, 352, 351, 379, 378, 407, 406, 436, 435, 466, 465, 497, 496, 529, 528, 562, 561, 596, 595, 631, 630, 667, 666, 704, 703, 742, 741, 781, 780, 821, 820, 862, 861, 904, 903, 947, 946, 991, 990, 1036, 1035, 1082, 1081, 1129, 1128, 1177, 1176, 1226}
	c := newseq()
	for i, v := range tab {
		assert(c.Value(int64(i)) == v)
	}

	assert(c.Value(68690) == 589772340)
	assert(c.Value(100000) == 1249975000)
	assert(c.Value(162207) == 3288888857)
	assert(c.Value(453271) == 25681824931)
	assert(c.Value(888888) == 98765012346)
	assert(c.Value(1000000) == 124999750000)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Seq struct {
	lut map[int64]int64
	cnt int64
}

func newseq() *Seq {
	return &Seq{
		lut: map[int64]int64{0: 0},
		cnt: 1,
	}
}

func (c *Seq) Value(n int64) int64 {
	if n < 0 {
		return 0
	}

	if v, ok := c.lut[n]; ok {
		return v
	}

	v := c.Value(n - 1)
	if n&1 != 0 {
		v, c.cnt = v+c.cnt, c.cnt+1
	} else {
		v--
	}
	c.lut[n] = v

	return v
}
