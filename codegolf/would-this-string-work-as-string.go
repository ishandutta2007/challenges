/*

Write a program that takes a single line string that you can assume will only contain the characters /\_‾. (That's forward and backward slash, underline and overline. You can use ~ in place of overline if you need since overline is not convenient ASCII.)

For example, one possible input is:

__/‾‾\/\_/‾

Your program needs to output a truthy or falsy value depending on whether the left edge of the string is "connected", so to speak, to the right edge of the string via the lines of the characters. So, if the kerning was a bit less, there would be a solid black (albeit kinky) line all the way from the left edge to the right, like an unbroken piece of string or twine.

The output for the above example would be true because the edges are connected:

example path

To be clear on the connections:

    / connects on its bottom left and top right
    \ connects on its top left and bottom right
    _ connects on its bottom left and bottom right
    ‾ (or ~) connects on its top left and top right

Also:

    It doesn't matter whether the edges of the string started on the top or the bottom, it only matters that they connect horizontally through the whole length of the string.

    You can assume the input string is non-empty, and of course just one line.

Here are some more examples followed by 1 (truthy) if they are connected or 0 (falsy) if not:

__/‾‾\/\_/‾
1

_
1

\
1

/
1

‾
1

___
1

\/
1

/\/
1

/\/\
1

‾‾‾
1

\\
0

‾‾
1

_‾
0

‾_
0

\_____/
1

\/\\/\\___
0

\/\__/‾‾\
1

______/\_____
1

‾‾‾‾‾‾\\_____
0

‾‾‾‾‾‾\______
1

_____/‾‾‾‾‾
1

\___/‾‾‾\___/‾‾‾
1

\_/_\_
0

\_/\_
1

/\/\/\/\/\/\/\/\/\/\/\/
1

____________________
1

‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
1

‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾/
0

‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\
1

/\‾/\‾___/\_\/__\/\‾‾
0

The shortest code is the winner.

*/

package main

func main() {
	assert(connected(`__/‾‾\/\_/‾`) == true)
	assert(connected(`_`) == true)
	assert(connected(`\`) == true)
	assert(connected(`/`) == true)
	assert(connected(`‾`) == true)
	assert(connected(`___`) == true)
	assert(connected(`\/`) == true)
	assert(connected(`/\/`) == true)
	assert(connected(`/\/\`) == true)
	assert(connected(`‾‾‾`) == true)
	assert(connected(`\\`) == false)
	assert(connected(`‾‾`) == true)
	assert(connected(`_‾`) == false)
	assert(connected(`‾_`) == false)
	assert(connected(`\_____/`) == true)
	assert(connected(`\/\\/\\___`) == false)
	assert(connected(`\/\__/‾‾\`) == true)
	assert(connected(`______/\_____`) == true)
	assert(connected(`‾‾‾‾‾‾\\_____`) == false)
	assert(connected(`‾‾‾‾‾‾\______`) == true)
	assert(connected(`_____/‾‾‾‾‾`) == true)
	assert(connected(`\___/‾‾‾\___/‾‾‾`) == true)
	assert(connected(`\_/_\_`) == false)
	assert(connected(`\_/\_`) == true)
	assert(connected(`/\/\/\/\/\/\/\/\/\/\/\/`) == true)
	assert(connected(`____________________`) == true)
	assert(connected(`‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾`) == true)
	assert(connected(`‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾/`) == false)
	assert(connected(`‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\`) == true)
	assert(connected(`/\‾/\‾___/\_\/__\/\‾‾`) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func connected(s string) bool {
	tab := [4][4]int{
		{0, 1, 0, 1},
		{1, 0, 1, 0},
		{1, 0, 1, 0},
		{0, 1, 0, 1},
	}

	r := []rune(s)
	for i := 0; i < len(r)-1; i++ {
		x := ci(r[i])
		y := ci(r[i+1])
		if x < 0 || y < 0 || tab[x][y] != 1 {
			return false
		}
	}
	return true
}

func ci(r rune) int {
	switch r {
	case '/':
		return 0
	case '\\':
		return 1
	case '_':
		return 2
	case '‾', '~':
		return 3
	}
	return -1
}
