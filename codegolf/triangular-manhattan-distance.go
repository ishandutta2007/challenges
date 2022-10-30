/*

The Manhattan distance on a regular grid is the number of orthogonal steps one needs to take to reach one cell from another.
Orthogonal steps are those that go through the edges of the grid cells (as opposed to the corners, which would give us the Chebyshev distance).

We can define a similar distance on other grids, for example the triangular grid. We can address the individual cells in the grid with the following indexing scheme, where each cell contains an x,y pair:

    ____________________________________...
   /\      /\      /\      /\      /\
  /  \ 1,0/  \ 3,0/  \ 5,0/  \ 7,0/  \
 / 0,0\  / 2,0\  / 4,0\  / 6,0\  / 8,0\
/______\/______\/______\/______\/______\...
\      /\      /\      /\      /\      /
 \ 0,1/  \ 2,1/  \ 4,1/  \ 6,1/  \ 8,1/
  \  / 1,1\  / 3,1\  / 5,1\  / 7,1\  /
   \/______\/______\/______\/______\/___...
   /\      /\      /\      /\      /\
  /  \ 1,2/  \ 3,2/  \ 5,2/  \ 7,2/  \
 / 0,2\  / 2,2\  / 4,2\  / 6,2\  / 8,2\
/______\/______\/______\/______\/______\...
\      /\      /\      /\      /\      /
 \ 0,3/  \ 2,3/  \ 4,3/  \ 6,3/  \ 8,3/
  \  / 1,3\  / 3,3\  / 5,3\  / 7,3\  /
   \/______\/______\/______\/______\/___...
   /\      /\      /\      /\      /\
  .  .    .  .    .  .    .  .    .  .
 .    .  .    .  .    .  .    .  .    .

Now the Manhattan distance on this grid is again the minimal number of steps across edges to get from one cell to another.
So you can move from 3,1 to 2,1, 4,1 or 3,2, but not to any other triangle, since those would be crossing points rather than edges.

For instance, the distance from 2,1 to 5,2 is 4. The shortest path is generally not unique, but one way to make the distance in 4 steps is:

2,1 --> 3,1 --> 3,2 --> 4,2 --> 5,2

The Challenge
Given two coordinate pairs x1,y1 and x2,y2 from the above addressing scheme, return the Manhattan distance between them.

You may assume that all four inputs are non-negative integers, each less than 128. You may take them in any order and arbitrarily grouped (four separate arguments, a list of four integers, two pairs of integers, a 2x2 matrix, ...).

You may write a program or a function and use any of the standard methods of receiving input and providing output.

You may use any programming language, but note that these loopholes are forbidden by default.

This is code-golf, so the shortest valid answer – measured in bytes – wins.

Test Cases
Each test case is given as x1,y1 x2,y2 => result.

1,2 1,2 => 0
0,1 1,1 => 1
1,0 1,1 => 3
2,1 5,2 => 4
0,0 0,127 => 253
0,0 127,0 => 127
0,0 127,127 => 254
0,127 127,0 => 254
0,127 127,127 => 127
127,0 127,127 => 255
75,7 69,2 => 11
47,58 36,79 => 42
77,9 111,23 => 48
123,100 111,60 => 80
120,23 55,41 => 83
28,20 91,68 => 111
85,107 69,46 => 123
16,25 100,100 => 159
62,85 22,5 => 160
92,26 59,113 => 174
62,22 35,125 => 206

*/

package main

import "fmt"

func main() {
	test(1, 2, 1, 2, 0)
	test(0, 1, 1, 1, 1)
	test(1, 0, 1, 1, 3)
	test(2, 1, 5, 2, 4)
	test(0, 0, 0, 127, 253)
	test(0, 0, 127, 0, 127)
	test(0, 0, 127, 127, 254)
	test(0, 127, 127, 0, 254)
	test(0, 127, 127, 127, 127)
	test(127, 0, 127, 127, 255)
	test(75, 7, 69, 2, 11)
	test(47, 58, 36, 79, 42)
	test(77, 9, 111, 23, 48)
	test(123, 100, 111, 60, 80)
	test(120, 23, 55, 41, 83)
	test(28, 20, 91, 68, 111)
	test(85, 107, 69, 46, 123)
	test(16, 25, 100, 100, 159)
	test(62, 85, 22, 5, 160)
	test(92, 26, 59, 113, 174)
	test(62, 22, 35, 125, 206)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x1, y1, x2, y2, r int) {
	v := tmd(x1, y1, x2, y2)
	fmt.Println(v)
	assert(v == r)
}

/*

@feersum:

abs(y-Y)+max(x-X,X-x,abs(y-Y)+((x+y+X+Y)%-2)**(x^y^(Y>=y)))
The power is due to the fact that moving by a distance 1 vertically can take either 1 or 3 moves;
there's no way to tell by just looking at parities so you have to compare the y values.

*/

func tmd(x1, y1, x2, y2 int) int {
	return abs(y1-y2) + max(abs(x1-x2), abs(y1-y2)+sig(x1+y1+x2+y2, (x1^y1^truth(y2 >= y1))))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}

func sig(x, y int) int {
	if x&1 == 0 {
		return 0
	}
	if y&1 == 0 {
		return 1
	}
	return -1
}
