/*

--- Day 3: Perfectly Spherical Houses in a Vacuum ---
Santa is delivering presents to an infinite two-dimensional grid of houses.

He begins by delivering a present to the house at his starting location, and then an elf at the North Pole calls him via radio and tells him where to move next.
Moves are always exactly one house to the north (^), south (v), east (>), or west (<). After each move, he delivers another present to the house at his new location.

However, the elf back at the north pole has had a little too much eggnog, and so his directions are a little off, and Santa ends up visiting some houses more than once. How many houses receive at least one present?

For example:

> delivers presents to 2 houses: one at the starting location, and one to the east.
^>v< delivers presents to 4 houses in a square, including twice to the house at his starting/ending location.
^v^v^v^v^v delivers a bunch of presents to some very lucky children at only 2 houses.

--- Part Two ---
The next year, to speed up the process, Santa creates a robot version of himself, Robo-Santa, to deliver presents with him.

Santa and Robo-Santa start at the same location (delivering two presents to the same starting house), then take turns moving based on instructions from the elf, who is eggnoggedly reading from the same script as the previous year.

This year, how many houses receive at least one present?

For example:

^v delivers presents to 3 houses, because Santa goes north, and then Robo-Santa goes south.
^>v< now delivers presents to 3 houses, and Santa and Robo-Santa end up back where they started.
^v^v^v^v^v now delivers presents to 11 houses, with Santa going one direction and Robo-Santa going the other.

*/

package main

import (
	"fmt"
	"log"
	"os"
)

func main() {
	b, err := os.ReadFile("3.txt")
	check(err)

	fmt.Println(part1(b))
	fmt.Println(part2(b))
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func part1(b []byte) int {
	m := make(map[[2]int]int)
	n := len(b)
	x, y := 0, 0
	for i := 0; i <= n; i++ {
		p := [2]int{x, y}
		m[p]++

		if i < n {
			x, y = move(b[i], x, y)
		}
	}

	return len(m)
}

func part2(b []byte) int {
	m := make(map[[2]int]int)
	n := len(b)
	x0, y0 := 0, 0
	x1, y1 := 0, 0
	for i := 0; i <= n; i += 2 {
		p0 := [2]int{x0, y0}
		p1 := [2]int{x1, y1}
		m[p0]++
		m[p1]++

		switch {
		case i+1 < n:
			x1, y1 = move(b[i+1], x1, y1)
			fallthrough
		case i < n:
			x0, y0 = move(b[i], x0, y0)
		}
	}

	return len(m)
}

func move(d byte, x, y int) (int, int) {
	switch d {
	case '^':
		y++
	case 'v':
		y--
	case '>':
		x++
	case '<':
		x--
	}
	return x, y
}
