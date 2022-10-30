/*

A laser shoots a straight beam in one of the four orthogonal directions, indicated by <>^v. Determine whether it will hit the target O on a rectangular grid.

Each of these will hit (True):

.....
...O.
.....
...^.
.....

>O.
...

v....
O....

...........
...........
O.........<
...........
These will miss (False):

......
......
.^..O.

......
.....>
O.....
......
......


.O.
...
.v.

.....<.
..O....

Input: A rectangular grid of ., sized at least 2x2, with exactly one target O and one laser that's one of <>^v. The lines can be a list of strings, a 2D array or nested list of characters, or a single newline-separated string with an optional trailing newline.

Output: A consistent truthy value if the laser beam hits the target, and a consistent falsy value if it misses.

I'll consider submissions that don't use regular expressions (or built-in pattern-based string matching) as a separate category. If you put (no regex) after the language name, your answer will appear separately in the leaderboard.

*/

package main

func main() {
	assert(hit([]string{
		".....",
		"...O.",
		".....",
		"...^.",
		".....",
	}) == true)

	assert(hit([]string{
		">O.",
		"...",
	}) == true)

	assert(hit([]string{
		"v....",
		"O....",
	}) == true)

	assert(hit([]string{
		"...........",
		"...........",
		"O.........<",
		"...........",
	}) == true)

	assert(hit([]string{
		"......",
		"......",
		".^..O.",
	}) == false)

	assert(hit([]string{
		"......",
		".....>",
		"O.....",
		"......",
		"......",
	}) == false)

	assert(hit([]string{
		".O.",
		"...",
		".v.",
	}) == false)

	assert(hit([]string{
		".....<.",
		"..O....",
	}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func hit(m []string) bool {
	var (
		l = vec2{-1, -1}
		o = vec2{-1, -1}
		t byte
	)

	for y := range m {
		for x := range m[y] {
			switch m[y][x] {
			case 'O':
				o = vec2{x, y}
			case '<', '>', '^', 'v':
				l = vec2{x, y}
				t = m[y][x]
			}
		}
	}

	switch t {
	case '<':
		return l.x >= o.x && l.y == o.y
	case '>':
		return l.x <= o.x && l.y == o.y
	case '^':
		return l.x == o.x && l.y >= o.y
	case 'v':
		return l.x == o.x && l.y <= o.y
	default:
		return false
	}
}

type vec2 struct {
	x, y int
}
