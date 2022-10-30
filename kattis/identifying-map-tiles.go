/*

Map websites such as Bing Maps and Google Maps often store their maps as many different image files, called tiles.
The lowest zoom level (level 0) consists of a single tile with a low-detail image of the whole map,
zoom level 1 consists of four tiles each containing a slightly more detailed version of a quarter of the map,
and in general zoom level n contains 4n different tiles that each contain a part of the map.

One way of identifying a tile is by means of a quadkey. A quadkey is a string of digits uniquely identifying a tile at a certain zoom level.
The first digit specifies in which of the four quadrants of the whole map the tile lies:
0 for the top-left quadrant, 1 for the top-right quadrant, 2 for the bottom-left quadrant and 3 for the bottom-right quadrant.
The subsequent digits specify in which sub quadrant of the current quadrant the tile is. The quadkeys for zoom levels 1 to 3 are shown in Figure 1(a).

\includegraphics[width=0.85\textwidth ]{maptiles.jpg}
(a) Quadkeys for zoom levels 1
to 3
\includegraphics[width=0.90\textwidth ]{maptiles2.jpg}
(b) Coordinates for zoom level 3
Figure 1: Visualisation of the two representations. The images are taken from the MSDN.

Another way of identifying a tile is to give the zoom level and x and y coordinates, where (0,0) is the left-top corner.
The coordinates for the tiles of zoom level 3 are shown in Figure 1(b).
Given the quadkey of a tile, output the zoom level and x and y coordinates of that tile.

Input

The input consists of:

	one line with a string s (1≤length(s)≤30), the quadkey of the map tile.

The string s consists of only the digits ‘0’, ‘1’, ‘2’ and ‘3’.

Output

Output three integers, the zoom level and the x and y coordinates of the tile.

*/

package main

import "fmt"

func main() {
	test("3", 1, 1, 1)
	test("130", 3, 6, 2)
}

func test(s string, rz, rx, ry int) {
	z, x, y := resolution(s)
	fmt.Println(z, x, y)
	assert(z == rz)
	assert(x == rx)
	assert(y == ry)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func resolution(s string) (z, x, y int) {
	for _, r := range s {
		x, y, z = 2*x, 2*y, z+1
		if (r-'0')&1 != 0 {
			x++
		}
		if (r-'0')&2 != 0 {
			y++
		}
	}
	return
}
