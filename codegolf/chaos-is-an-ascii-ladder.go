/*

You know nothing The things I do for "Chaos is a ladder" is a memorable line from the television series Game of Thrones.

The purpose of this challenge is to build a ladder from chaos, in ASCII art.
The challenge

Input

    Ladder width, W >= 3 (integer)
    Step height, H >= 2 (integer)
    Number of rungs, N >= 2 (integer).

Output

A ladder with horizontal rungs and vertical rails, all 1 character wide. Ladder width (W) includes the two rails, and step height (H) includes the corresponding rung.

All rungs, including the uppermost and the lowermost, will have a piece of vertical rail of length H-1 directly above and below. The example will make this clearer.

The ladder will be made of printable, non-whitespace ASCII characters, that is, the inclusive range from ! (code point 33) to ~ (code point 126).
The actual characters will be chosen randomly. Given the inputs, each of the random choices of characters must have nonzero probability. Other than that, the probability distribution is arbitrary.

Leading or trailing whitespace, either horizontal or vertical, is allowed.

Example

Given W=5, H=3, N=2, one possible output is as follows.

x   :
g   h
q$UO{
t   T
6   <
bUZXP
8   T
5   g

Note that total height is H*(N+1)-1, as there are N rungs and N+1 vertical sections.

Aditional rules

    Input means and format are flexible as usual. For example, you can input the three numbers in any order, or an array containing them.

    Output may be through STDOUT or an argument returned by a function. In this case it may be a string with newlines, a 2D character array or an array of strings.

    A program or a function can be provided.

    Standard loopholes are forbidden.

    Shortest code in bytes wins.

Test cases

For each W, H, N a possible output is shown.

W=5, H=3, N=2:

\   ~
:   K
ke:[E
5   u
0   _
8Fr.D
#   r
7   X


W=3, H=2, N=2:

$ X
Mb)
0 ]
(T}
j 9


W=12, H=4, N=5:

d          Y
P          `
5          3
p$t$Ow7~kcNX
D          x
`          O
*          H
LB|QX1'.[:[F
p          p
x          (
2          ^
ic%KL^z:KI"^
C          p
(          7
7          h
TSj^E!tI&TN8
|          [
<          >
=          Q
ffl`^,tBHk?~
O          +
p          e
n          j


W=20, H=5, N=3:

G                  %
o                  y
%                  3
-                  7
U'F?Vml&rVch7{).fLDF
o                  }
U                  I
h                  y
a                  g
;W.58bl'.iHm\8v?bIn&
,                  U
N                  S
4                  c
5                  r
F3(R|<BP}C'$=}xK$F]^
'                  h
h                  u
x                  $
6                  5

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	chaosladder(5, 3, 2)
	chaosladder(3, 2, 2)
	chaosladder(12, 4, 5)
	chaosladder(20, 5, 3)
}

func chaosladder(w, h, n int) {
	for i := 0; i <= n; i++ {
		for y := 0; y < h; y++ {
			for x := 0; x < w; x++ {
				if (x == 0 || x+1 == w) || (y+1 == h && i < n) {
					fmt.Printf("%c", randchar())
				} else {
					fmt.Printf(" ")
				}
			}
			fmt.Println()
		}
	}
	fmt.Println()
}

func randchar() rune {
	return rune(33 + rand.Intn(94))
}
