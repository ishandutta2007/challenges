/*

A cruise control has 3 different options to move the handle to set the speed you want to drive with.

Towards you: Adds 1 speed.
Upwards: Increases speed to the next multiple of 10 (e.g. 20-->30, 32-->40)
Downwards: Decreases speed to the next multiple of 10 (e.g. 20-->10, 32-->30)

Input

2 integers: the first is the starting speed and the second is your desired speed, both non-negative and in any form you like (array, two arguments, etc.)

Task

Determine the optimal way of using the handle to reach the desired speed and print out the moves in the correct order.

Rules

If you have the choice between pulling towards you and going upwards (like from 39 to 40) you can choose either option, but stay with whatever you choose for similar cases
You may use any 3 different (preferably visible) symbols to distinguish between the moves in the output (T, U and D for example).
The symbols can be seperated by new lines, spaces, etc. but don't have to be
Here are some test cases:

start speed, desired speed  -->  output
30, 40  -->  U
30, 43  -->  UTTT
43, 30  -->  DD
51, 39  -->  DDDTTTTTTTTT
29, 30  -->  T or U
29, 50  -->  TUU or UUU
12, 12  -->

*/

package main

import (
	"bytes"
)

func main() {
	assert(control(30, 40) == "U")
	assert(control(30, 43) == "UTTT")
	assert(control(43, 30) == "DD")
	assert(control(51, 39) == "DDDTTTTTTTTT")
	assert(control(29, 30) == "U")
	assert(control(29, 50) == "UUU")
	assert(control(12, 12) == "")
	assert(control(32, 30) == "D")
	assert(control(36, 40) == "U")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func control(s, d int) string {
	w := new(bytes.Buffer)
	for s != d {
		switch {
		case s > d:
			v := 0
			if s%10 < 1 {
				v = 10
			}
			s = (s/10)*10 - v
			w.WriteByte('D')
		case s/10 < d/10:
			s = (s/10 + 1) * 10
			w.WriteByte('U')
		default:
			s = s + 1
			w.WriteByte('T')
		}
	}
	return w.String()
}
