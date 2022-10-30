/*

(Easy): Flood-Fill

Flood-fill is a tool used in essentially any image editing program that's worth its salt. It allows you to fill in any contigious region of colour with another colour, like flooding a depression in a board with paint. For example, take this beautiful image. If I was to flood-fill the colour orange into this region of the image, then that region would be turned completely orange.

Today, you're going to implement an algorithm to perform a flood-fill on a text ASCII-style image.
Input and Output Description
Challenge Input

You will accept two numbers, w and h, separated by a space. These are to be the width and height of the image in characters, with the top-left being (0, 0). You will then accept a grid of ASCII characters of size w*h. Finally you will accept two more numbers, x and y, and a character c. x and y are the co-ordinates on the image where the flood fill should be done, and c is the character that will be filled.

Pixels are defined as contigious (touching) when they share at least one edge (pixels that only touch at corners aren't contigious).

For example:

37 22
.....................................
...#######################...........
...#.....................#...........
...#.....................#...........
...#.....................#...........
...#.....................#...........
...#.....................#...........
...#.....................#######.....
...###.................##......#.....
...#..##.............##........#.....
...#....##.........##..........#.....
...#......##.....##............#.....
...#........#####..............#.....
...#........#..................#.....
...#.......##..................#.....
...#.....##....................#.....
...#...##......................#.....
...#############################.....
.....................................
.....................................
.....................................
.....................................
8 12 @

Challenge Output

Output the image given, after the specified flood-fill has taken place.

.....................................
...#######################...........
...#.....................#...........
...#.....................#...........
...#.....................#...........
...#.....................#...........
...#.....................#...........
...#.....................#######.....
...###.................##......#.....
...#@@##.............##........#.....
...#@@@@##.........##..........#.....
...#@@@@@@##.....##............#.....
...#@@@@@@@@#####..............#.....
...#@@@@@@@@#..................#.....
...#@@@@@@@##..................#.....
...#@@@@@##....................#.....
...#@@@##......................#.....
...#############################.....
.....................................
.....................................
.....................................
.....................................

Sample Inputs and Outputs
Input

16 15
----------------
-++++++++++++++-
-+------------+-
-++++++++++++-+-
-+------------+-
-+-++++++++++++-
-+------------+-
-++++++++++++-+-
-+------------+-
-+-++++++++++++-
-+------------+-
-++++++++++++++-
-+------------+-
-++++++++++++++-
----------------
2 2 @

Output

----------------
-++++++++++++++-
-+@@@@@@@@@@@@+-
-++++++++++++@+-
-+@@@@@@@@@@@@+-
-+@++++++++++++-
-+@@@@@@@@@@@@+-
-++++++++++++@+-
-+@@@@@@@@@@@@+-
-+@++++++++++++-
-+@@@@@@@@@@@@+-
-++++++++++++++-
-+------------+-
-++++++++++++++-
----------------

Input

9 9
aaaaaaaaa
aaadefaaa
abcdafgha
abcdafgha
abcdafgha
abcdafgha
aacdafgaa
aaadafaaa
aaaaaaaaa
8 3 ,

Output

,,,,,,,,,
,,,def,,,
,bcd,fgh,
,bcd,fgh,
,bcd,fgh,
,bcd,fgh,
,,cd,fg,,
,,,d,f,,,
,,,,,,,,,

Extension (Easy/Intermediate)

Extend your program so that the image 'wraps' around from the bottom to the top, and from the left to the right (and vice versa). This makes it so that the top and bottom, and left and right edges of the image are touching (like the surface map of a torus).
Input

9 9
\/\/\/\.\
/./..././
\.\.\.\.\
/.../.../
\/\/\/\/\
/.../.../
\.\.\.\.\
/./..././
\/\/\/\.\
1 7 #

Output

\/\/\/\#\
/#/###/#/
\#\#\#\#\
/###/###/
\/\/\/\/\
/###/###/
\#\#\#\#\
/#/###/#/
\/\/\/\#\

Further Reading

If you need a starting point with recursion, here are some reading resources.

    Recursive Algorithms

    Recursive function calls

Consider using list-like data structures in your solution, too.
Addendum

200! :)

*/

package main

import "fmt"

func main() {
	const s1 = `.....................................
...#######################...........
...#.....................#...........
...#.....................#...........
...#.....................#...........
...#.....................#...........
...#.....................#...........
...#.....................#######.....
...###.................##......#.....
...#..##.............##........#.....
...#....##.........##..........#.....
...#......##.....##............#.....
...#........#####..............#.....
...#........#..................#.....
...#.......##..................#.....
...#.....##....................#.....
...#...##......................#.....
...#############################.....
.....................................
.....................................
.....................................
.....................................`

	const s2 = `----------------
-++++++++++++++-
-+------------+-
-++++++++++++-+-
-+------------+-
-+-++++++++++++-
-+------------+-
-++++++++++++-+-
-+------------+-
-+-++++++++++++-
-+------------+-
-++++++++++++++-
-+------------+-
-++++++++++++++-
----------------`

	const s3 = `aaaaaaaaa
aaadefaaa
abcdafgha
abcdafgha
abcdafgha
abcdafgha
aacdafgaa
aaadafaaa
aaaaaaaaa`

	test(s1, 8, 12, '@')
	test(s2, 2, 2, '@')
	test(s3, 8, 3, ',')
}

func test(s string, x, y int, c byte) {
	g := grid(s)
	dump(g)
	fill(g, x, y, g[y][x], c)
	dump(g)
}

func fill(g [][]byte, x, y int, p, c byte) {
	if y < 0 || y >= len(g) || x < 0 || x >= len(g[y]) || g[y][x] != p {
		return
	}

	g[y][x] = c
	fill(g, x, y-1, p, c)
	fill(g, x-1, y, p, c)
	fill(g, x+1, y, p, c)
	fill(g, x, y+1, p, c)
}

func grid(s string) [][]byte {
	var (
		g [][]byte
		v []byte
	)

	for i := 0; i < len(s); i++ {
		v = append(v, s[i])
		if s[i] == '\n' {
			g = append(g, v)
			v = []byte{}
		}
	}
	if len(v) > 0 {
		g = append(g, v)
	}

	return g
}

func dump(g [][]byte) {
	for i := range g {
		for j := range g[i] {
			fmt.Printf("%c", g[i][j])
		}
		fmt.Println()
	}
	fmt.Printf("\n\n")
}
