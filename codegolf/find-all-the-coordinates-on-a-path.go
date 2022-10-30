/*

Given a 2D string as input, either as a string with newlines or a list of lines, output the coordinates (x, y) of all the hashes (#) in the list.
The input will only contain hashes and spaces. (and newlines, if you choose to take input as a 2D string)

If there are no hashes, you can output anything.

Output should be unambiguous as to which numbers are paired with which.

Example:

##
Should output:

(0,0), (1,0)
That assumes 0-based indexing, starting from the top left. You may start from any corner, use 0 or 1-based indexing, and/or output y first. (e.g. in the form y,x).

More test cases (again, all using 0-based top-left (x, y) indexing):

    #
#####
#

(4, 0), (0, 1), (1, 1), (2, 1), (3, 1), (4, 1), (0, 2)


# ###
### #

(0, 0), (2, 0), (3, 0), (4, 0), (0, 1), (1, 1), (2, 1), (4, 1)
Note that these test cases all list by rows, not by following the path.

You may assume the hashes will form a continuous trail, i.e. # # will never be the input. (probably won't matter, but in case somebody wants to regex this)

You also can output the coordinates in any order you want, i.e. vertical columns, horizontal rows, or just an unsorted list.

*/

package main

import (
	"fmt"
	"image"
	"reflect"
)

func main() {
	test([]string{"##"}, []image.Point{{0, 0}, {1, 0}})

	test([]string{
		"    #",
		"#####",
		"#    ",
	}, []image.Point{{4, 0}, {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {0, 2}})

	test([]string{
		"# ###",
		"### #",
	}, []image.Point{{0, 0}, {2, 0}, {3, 0}, {4, 0}, {0, 1}, {1, 1}, {2, 1}, {4, 1}})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s []string, r []image.Point) {
	p := coords(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func coords(s []string) []image.Point {
	p := []image.Point{}
	for i := 0; i < len(s); i++ {
		for j := 0; j < len(s[i]); j++ {
			if s[i][j] == '#' {
				p = append(p, image.Pt(j, i))
			}
		}
	}
	return p
}
