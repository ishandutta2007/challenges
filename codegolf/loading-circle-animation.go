/*

Challenge

Write a full program that takes no input (or has an unused input) that displays exactly the following ASCII animation for as long as possible or only 8 frames.

Frame 1:

 #
#
#  #
 ##
Frame 2:

 ##
#
#
 ##
Frame 3:

 ##
#  #
#
 #
Frame 4:

 ##
#  #
#  #

(Note that the line at the end is empty.)

Frame 5:

 ##
#  #
   #
  #
Frame 6:

 ##
   #
   #
 ##
Frame 7:

  #
   #
#  #
 ##
Frame 8:


#  #
#  #
 ##
(Note that the line at the start is empty.)

Rules
The program takes no input (or has an unused input).
The animation can start at any frame, but must animate in sequential order.
The animation can be in reverse order.
The program has to run as long as possible or for exactly 8 frames.
The animation has to be displayed at the same position on screen for every frame.
Trailing/leading whitespace is okay, as long as the animation looks right.
# and space can be replaced with different (not a newline) distinct characters that are each 1 byte.
There should be an additional pause of any length but more than 0 ms after an entire frame is drawn.
This is code-golf, so the shortest answer in bytes wins.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	animate()
}

func animate() {
	tab := []string{one, two, three, four, five, six, seven, eight}

	i := 0
	for {
		fmt.Printf("\033c")
		fmt.Println(tab[i])

		time.Sleep(100 * time.Millisecond)

		i = (i + 1) % len(tab)
	}
}

const one = `
 #
#
#  #
 ##`

const two = `
 ##
#
#
 ##`

const three = `
 ##
#  #
#
 #`

const four = `
 ##
#  #
#  #`

const five = `
 ##
#  #
   #
  #`

const six = `
 ##
   #
   #
 ##`

const seven = `
  #
   #
#  #
 ##`

const eight = `

#  #
#  #
 ##`
