/*

Description

A knight piece in chess can only make L-shaped moves. Specifically, it can only move x steps to the right and y steps up if (x,y) is one of:

(-1,-2) ( 1,-2) (-1, 2) ( 1, 2)
(-2,-1) ( 2,-1) (-2, 1) ( 2, 1)
(For this problem, assume the board extends infinitely in all directions, so a knight may always make eight moves from any starting point.)
A knight starting from (0,0) can reach any square, but it may have to take a roundabout route. For instance, to reach the square (0,1) requires three steps:

 2,  1
-1,  2
-1, -2

(Notice that the x's add up to 0, and the y's add up to 1.) Write a program, that, given a square (x,y), returns how many moves it takes a knight to reach that square starting from (0,0).

Example Input
3 7

Example Output
4

Optional: also output one route the knight could take to reach this square.

Credit

This challenge was suggested by /u/Cosmologicon, a well-known moderator of this sub. Many thanks! This one was hiding in the archives ...

*/

package main

func main() {
	assert(moves(0, 0) == 0)
	assert(moves(0, 12) == 6)
	assert(moves(0, 4) == 2)
	assert(moves(3, 7) == 4)
	assert(moves(5, 10) == 5)
	assert(moves(13, 13) == 10)
	assert(moves(7, 12) == 7)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@gabyjunior:

Based on pattern recognition looking at the number of moves it takes to reach each (x, y) square from (0,0), with 0 <= y <= x.

    0  1  2  3  4  5  6  7  8  9 10 11 12 13
   +----------------------------------------
 0 |0- 3* 2- 3- 2- 3- 4- 5- 4- 5- 6- 7- 6- 7-
   |
 1 |   2  1- 2- 3- 4- 3- 4- 5- 6- 5- 6- 7- 8-
   |
 2 |      4* 3  2- 3- 4- 5- 4- 5- 6- 7- 6- 7-
   |
 3 |         2  3  4  3- 4- 5- 6- 5- 6- 7- 8-
   |
 4 |            4  3  4  5  4- 5- 6- 7- 6- 7-
   |
 5 |               4  5  4  5  6  5- 6- 7- 8-
   |
 6 |                  4  5  6  5  6  7  6- 7-
   |
 7 |                     6  5  6  7  6  7  8
   |
 8 |                        6  7  6  7  8  7
   |
 9 |                           6  7  8  7  8
   |
10 |                              8  7  8  9
   |
11 |                                 8  9  8
   |
12 |                                    8  9
   |
13 |                                      10

You can notice 2 different groups in the above matrix

When y = 0 or x/y >= 2 (Marked with a '-' after the result), a pattern of 4 increasing numbers is repeating on each line (ex [2, 3, 4, 5], [4, 5, 6, 7], ... on first line). There is only one exception in this group when x = 1 and y = 0 (Marked with a '*')

In the second group, a pattern of 3 identical numbers is repeating on each diagonal (ex [4, 4, 4], [6, 6, 6] on first diagonal). There is only one exception in this group when x = 2 and y = 2 (Marked with a '*')

Based on that here is the source code that gives the number of moves depending on the target coordinates.

EDIT: a bit of simplication, also the commented part will give the result matrix for (x, y) = (0, 0) to (19, 19).

*/

func moves(x, y int) int {
	x = abs(x)
	y = abs(y)
	if x < y {
		x, y = y, x
	}

	switch d := x - y; {
	case d < y:
		if x == 2 && y == 2 {
			return 4
		}
		return d + ((y-d+2)/3)*2

	default:
		if x == 1 && y == 0 {
			return 3
		}
		xb := x - (y%2)*2
		return (xb/4)*2 + xb%4 + y%2
	}
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
