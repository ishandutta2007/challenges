/*

Create a function that takes a start position of the chess knight and return all possible moves.

Alternative Text Alternative Text Alternative Text Alternative Text
Formating

    Letters (A, B, C, D, E, F, G,H) must be on Uppercase.
    On result moves must be sorted alphabetically (numbers too).
    Moves must be separated by space-space.

Examples

knightMove("A1") ➞ "B3 - C2"

knightMove("A2") ➞ "B4 - C1 - C3"

knightMove("E2") ➞ "C1 - C3 - D4 - F4 - G1 - G3"

Notes

N/A

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	assert(knightmove("A1") == "B3 - C2")
	assert(knightmove("E2") == "C1 - C3 - D4 - F4 - G1 - G3")
	assert(knightmove("C1") == "A2 - B3 - D3 - E2")
	assert(knightmove("H8") == "F7 - G6")
	assert(knightmove("A4") == "B2 - B6 - C3 - C5")
	assert(knightmove("E4") == "C3 - C5 - D2 - D6 - F2 - F6 - G3 - G5")
	assert(knightmove("F7") == "D6 - D8 - E5 - G5 - H6 - H8")
	assert(knightmove("A2") == "B4 - C1 - C3")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func knightmove(s string) string {
	tab := [][2]int{
		{-2, -1},
		{-2, 1},
		{-1, -2},
		{-1, 2},
		{1, -2},
		{1, 2},
		{2, -1},
		{2, 1},
	}

	r, f := fsq(s)
	if r == 0 || f == 0 {
		return ""
	}

	var (
		t [8]string
		n int
	)
	for _, p := range tab {
		if r := tsq(r+p[0], f+p[1]); r != "" {
			t[n], n = r, n+1
		}
	}

	return strings.Join(t[:n], " - ")
}

func fsq(s string) (r, f int) {
	if len(s) != 2 {
		return
	}
	if !('A' <= s[0] && s[0] <= 'H') {
		return
	}
	if !('1' <= s[1] && s[1] <= '8') {
		return
	}

	r = int(s[0] - 'A' + 1)
	f = int(s[1] - '1' + 1)
	return
}

func tsq(r, f int) string {
	if r < 1 || r > 8 || f < 1 || f > 8 {
		return ""
	}
	return fmt.Sprintf("%c%c", r+'A'-1, f+'1'-1)
}
