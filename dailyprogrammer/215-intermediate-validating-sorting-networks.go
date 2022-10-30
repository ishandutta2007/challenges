/*

Description

When we computer programmers learn all about how computers sort lists of numbers, we are usually taught about sorting algorithms like Quicksort and Heapsort.
There is, however, an entirely different model for how computers can sort numbers called sorting networks.
Sorting networks are very useful for implementing sorting in hardware, and they have found a use for designing sorting algorithms in GPUs.
Today, we are going to explore these strange and fascinating beasts.

In a sorting network, a list of numbers travel down idealized "wires" that are connected with so-called "comparators".
Each comparator connects two wires and swaps the values between them if they're out of order (the smaller value going to the top wire, and the larger to the bottom wire).
This image shows the principle clearly, and this image demonstrates a full run of a 4-wire sorting network wtih 5 comparators (both images courtesy of wikipedia, which has an excellent article on sorting networks if you are interested in learning more).
Notice that the list on the right is correctly sorted top to bottom.

It is easy to see why that particular network correctly sorts a list of numbers: the first four comparators "float" the smallest value to the top and "sinks" the largest value to the bottom, and the final comparator sorts out the middle two values.

In general, however, there's often no easy way to tell whether or not a sorting network will actually correctly sort a list of numbers, and the only way to tell is to actually test it.
This seems like a daunting task, since for a sorting network with N wires, there's N! (i.e. "N factorial") possible input permutations. That function grows extremely quickly, and become prohibitively large for even N of 14 or 15.

The zero-one principle

Thankfully, there's a better way, thanks to the so-called "zero-one principle", which is as follows:

If an N-wire sorting network can correctly sort all 2N possible sequences of 0's and 1's, it will correctly sort all possible input sequences.

So, instead of having to try and check all N! possible permutations of the input sequence, we can just check all 2N sequences consisting of 0's and 1's. While this is still exponential, it is far smaller than N!.

Today, you will be given a sorting network and your challenge will be to check whether or not that network will correctly sort all inputs.

Formal inputs & outputs

Inputs

The input will first consist of a single line with two numbers on it separated by a space. The first number is the number of wires in the sorting network, and the second number is the total number of comparators on the network.

After that, there will follow a number of lines, each of which describes one comparator. The lines will consist of two numbers separated by a space describing which two wires the comparator connects. The first number will always be smaller than the second number

The "top" wire of the sorting network is wire 0, and the bottom wire is wire N-1.
So, for a 16-wire sorting network, the top wire (which will hold the smallest number at the end, hopefully) is wire 0, and the bottom wire is wire 15 (which will hold the highest number at the end, hopefully).

Note that in most sorting networks, several comparators compare numbers in parallel. For the purposes of this problem, you can ignore that and assume that all comparators work in sequence, following the order provided in the input.

Output

The output will consist of a single line which will either be "Valid network" if the network will indeed sort all sequences correctly, or "Invalid network" if it won't.

Sample inputs and outputs

Input 1
This is the example 4-wire, 5-comparator sorting network from the description:

4 5
0 2
1 3
0 1
2 3
1 2

Output 1
Valid network

Input 2
8 19
0 2
1 3
0 1
2 3
1 2
4 6
5 7
4 5
6 7
5 6
0 4
1 5
2 6
3 7
2 4
3 5
1 2
3 4
6 7

Output 2
Invalid network

Challenge inputs
Input 1
This 16-wire 60-comparator network

Input 2
This (slightly different) 16-wire 60-comparator network

Notes
As always, if you have any challenge idea, head on over to r/dailyprogrammer_ideas and let us know!

*/

package main

func main() {
	assert(sortnetwork(4, [][2]int{
		{0, 2},
		{1, 3},
		{0, 1},
		{2, 3},
		{1, 2},
	}) == true)

	assert(sortnetwork(8, [][2]int{
		{0, 2},
		{1, 3},
		{0, 1},
		{2, 3},
		{1, 2},
		{4, 6},
		{5, 7},
		{4, 5},
		{6, 7},
		{5, 6},
		{0, 4},
		{1, 5},
		{2, 6},
		{3, 7},
		{2, 4},
		{3, 5},
		{1, 2},
		{3, 4},
		{6, 7},
	}) == false)

	assert(sortnetwork(16, [][2]int{
		{0, 1},
		{2, 3},
		{4, 5},
		{6, 7},
		{8, 9},
		{10, 11},
		{12, 13},
		{14, 15},
		{0, 2},
		{1, 3},
		{4, 6},
		{5, 7},
		{8, 10},
		{9, 11},
		{12, 14},
		{13, 15},
		{0, 4},
		{1, 5},
		{2, 6},
		{3, 7},
		{8, 12},
		{9, 13},
		{10, 14},
		{11, 15},
		{0, 8},
		{1, 9},
		{2, 10},
		{3, 11},
		{4, 12},
		{5, 13},
		{6, 14},
		{7, 15},
		{5, 10},
		{6, 9},
		{3, 12},
		{7, 11},
		{13, 14},
		{1, 2},
		{4, 8},
		{1, 4},
		{7, 13},
		{2, 8},
		{11, 14},
		{2, 4},
		{5, 6},
		{9, 10},
		{11, 13},
		{3, 8},
		{7, 12},
		{6, 8},
		{3, 5},
		{7, 9},
		{10, 12},
		{3, 4},
		{5, 6},
		{7, 8},
		{9, 10},
		{11, 12},
		{6, 7},
		{12, 13},
	}) == false)

	assert(sortnetwork(16, [][2]int{
		{0, 1},
		{2, 3},
		{4, 5},
		{6, 7},
		{8, 9},
		{10, 11},
		{12, 13},
		{14, 15},
		{0, 2},
		{1, 3},
		{4, 6},
		{5, 7},
		{8, 10},
		{9, 11},
		{12, 14},
		{13, 15},
		{0, 4},
		{1, 5},
		{2, 6},
		{3, 7},
		{8, 12},
		{9, 13},
		{10, 14},
		{11, 15},
		{0, 8},
		{1, 9},
		{2, 10},
		{3, 11},
		{4, 12},
		{5, 13},
		{6, 14},
		{7, 15},
		{5, 10},
		{6, 9},
		{3, 12},
		{7, 11},
		{13, 14},
		{1, 2},
		{4, 8},
		{1, 4},
		{7, 13},
		{2, 8},
		{11, 14},
		{2, 4},
		{5, 6},
		{9, 10},
		{11, 13},
		{3, 8},
		{7, 12},
		{6, 8},
		{3, 5},
		{7, 9},
		{10, 12},
		{3, 4},
		{5, 6},
		{7, 8},
		{9, 10},
		{11, 12},
		{6, 7},
		{8, 9},
	}) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sortnetwork(n int, c [][2]int) bool {
	p := make([]byte, n)
	b := 1 << n
	for i := 0; i < b; i++ {
		gen(i, p)
		bubble(p, c)
		if !sorted(p) {
			return false
		}
	}
	return true
}

func gen(n int, p []byte) {
	for i := range p {
		p[i] = 0
		if n&(1<<i) != 0 {
			p[i] = 1
		}
	}
}

func bubble(p []byte, c [][2]int) {
	n := len(p)
	for i := range c {
		x, y := c[i][0], c[i][1]
		if x > y {
			x, y = y, x
		}

		if x < 0 || y < 0 || x >= n || y >= n {
			continue
		}

		if p[x] > p[y] {
			p[x], p[y] = p[y], p[x]
		}
	}
}

func sorted(p []byte) bool {
	n := len(p)
	for i := 1; i < n; i++ {
		if p[i] < p[i-1] {
			return false
		}
	}
	return true
}
