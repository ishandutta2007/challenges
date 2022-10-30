/*

--- Day 1: No Time for a Taxicab ---
Santa's sleigh uses a very high-precision clock to guide its movements, and the clock's oscillator is regulated by stars.
Unfortunately, the stars have been stolen... by the Easter Bunny. To save Christmas, Santa needs you to retrieve all fifty stars by December 25th.

Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!

You're airdropped near Easter Bunny Headquarters in a city somewhere. "Near", unfortunately, is as close as you can get - the instructions on the Easter Bunny Recruiting Document the Elves intercepted start here, and nobody had time to work them out further.

The Document indicates that you should start at the given coordinates (where you just landed) and face North. Then, follow the provided sequence: either turn left (L) or right (R) 90 degrees, then walk forward the given number of blocks, ending at a new intersection.

There's no time to follow such ridiculous instructions on foot, though, so you take a moment and work out the destination. Given that you can only walk on the street grid of the city, how far is the shortest path to the destination?

For example:

Following R2, L3 leaves you 2 blocks East and 3 blocks North, or 5 blocks away.
R2, R2, R2 leaves you 2 blocks due South of your starting position, which is 2 blocks away.
R5, L5, R5, R3 leaves you 12 blocks away.
How many blocks away is Easter Bunny HQ?

--- Part Two ---
Then, you notice the instructions continue on the back of the Recruiting Document. Easter Bunny HQ is actually at the first location you visit twice.

For example, if your instructions are R8, R4, R4, R8, the first location you visit twice is 4 blocks away, due East.

How many blocks away is the first location you visit twice?

*/

package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	tracker := newtracker()
	fmt.Println(blocks(input, nil))
	fmt.Println(blocks(input, tracker.check))
}

type tracker struct {
	seen map[[2]int]bool
}

func newtracker() *tracker {
	return &tracker{
		seen: make(map[[2]int]bool),
	}
}

func (t *tracker) check(x, y int) bool {
	if p := [2]int{x, y}; !t.seen[p] {
		t.seen[p] = true
		return false
	}
	return true
}

func blocks(s string, f func(int, int) bool) int {
	var d, x, y int

	t := strings.Split(s, ",")
loop:
	for _, t := range t {
		l := strings.TrimSpace(t)
		if l == "" {
			continue
		}

		n, _ := strconv.Atoi(l[1:])
		switch l[0] {
		case 'L':
			d = mod(d-1, 4)
		case 'R':
			d = mod(d+1, 4)
		}

		for i := 0; i < n; i++ {
			switch d {
			case 0:
				y++
			case 1:
				x++
			case 2:
				y--
			case 3:
				x--
			}

			if f != nil && f(x, y) {
				break loop
			}
		}
	}
	return abs(x) + abs(y)
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}

func mod(x, m int) int {
	x %= m
	if x < 0 {
		x += m
	}
	return x
}

const input = `L3, R1, L4, L1, L2, R4, L3, L3, R2, R3, L5, R1, R3, L4, L1, L2, R2, R1, L4, L4, R2, L5, R3, R2, R1, L1, L2, R2, R2, L1, L1, R2, R1, L3, L5, R4, L3, R3, R3, L5, L190, L4, R4, R51, L4, R5, R5, R2, L1, L3, R1, R4, L3, R1, R3, L5, L4, R2, R5, R2, L1, L5, L1, L1, R78, L3, R2, L3, R5, L2, R2, R4, L1, L4, R1, R185, R3, L4, L1, L1, L3, R4, L4, L1, R5, L5, L1, R5, L1, R2, L5, L2, R4, R3, L2, R3, R1, L3, L5, L4, R3, L2, L4, L5, L4, R1, L1, R5, L2, R4, R2, R3, L1, L1, L4, L3, R4, L3, L5, R2, L5, L1, L1, R2, R3, L5, L3, L2, L1, L4, R4, R4, L2, R3, R1, L2, R1, L2, L2, R3, R3, L1, R4, L5, L3, R4, R4, R1, L2, L5, L3, R1, R4, L2, R5, R4, R2, L5, L3, R4, R1, L1, R5, L3, R1, R5, L2, R1, L5, L2, R2, L2, L3, R3, R3, R1`
