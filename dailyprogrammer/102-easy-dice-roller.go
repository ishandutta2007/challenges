/*

In tabletop role-playing games like Dungeons & Dragons, people use a system called dice notation to represent a combination of dice to be rolled to generate a random number.
Dice rolls are of the form AdB (+/-) C, and are calculated like this:

    Generate A random numbers from 1 to B and add them together.

    Add or subtract the modifier, C.

If A is omitted, its value is 1; if (+/-)C is omitted, step 2 is skipped. That is, "d8" is equivalent to "1d8+0".

Write a function that takes a string like "10d6-2" or "d20+7" and generates a random number using this syntax.

Here's a hint on how to parse the strings, if you get stuck:

Split the string over 'd' first; if the left part is empty, A = 1,
otherwise, read it as an integer and assign it to A. Then determine
whether or not the second part contains a '+' or '-', etc.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	fmt.Println(roll("1d8+0"))
	fmt.Println(roll("d8"))
	fmt.Println(roll("10d6-2"))
	fmt.Println(roll("d20+7"))
}

func roll(s string) int {
	tab := []struct {
		fmt  string
		args int
		neg  bool
	}{
		{"%dd%d+%d", 3, false},
		{"%dd%d-%d", 3, true},
		{"d%d+%d", 2, false},
		{"d%d-%d", 2, true},
		{"d%d", 1, false},
	}

	a, b, c := 1, 0, 0
	for _, p := range tab {
		var n int
		switch p.args {
		case 1:
			n, _ = fmt.Sscanf(s, p.fmt, &b)
		case 2:
			n, _ = fmt.Sscanf(s, p.fmt, &b, &c)
		case 3:
			n, _ = fmt.Sscanf(s, p.fmt, &a, &b, &c)
		}
		if n == p.args {
			if p.neg {
				c = -c
			}
			break
		}
	}

	r := c
	for i := 0; i < a; i++ {
		r += 1 + rand.Intn(b)
	}
	return r
}
