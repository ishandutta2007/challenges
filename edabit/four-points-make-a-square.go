/*

The function is given four points with (x, y) coordinates in no particular order. Determine if these points make a square and return True / False.

A square has four equal sides with positive length and four 90-degree angles.

Examples

valid_square((0, 0), (1, 1), (1, 0), (0, 1)) ➞ True

valid_square((0, 0), (1, 1), (1, 0), (0, 12)) ➞ False

valid_square((1, 0), (-1, 0), (0, 1), (0, -1)) ➞ True

valid_square((0, 0), (0, 0), (0, 0), (0, 0)) ➞ False

Notes

A square also has equal diagonals.

*/

package main

import "image"

func main() {
	tab := []struct {
		p [4]image.Point
		r bool
	}{
		{[4]image.Point{{0, 0}, {1, 1}, {1, 0}, {0, 1}}, true},
		{[4]image.Point{{0, 0}, {1, 1}, {1, 0}, {0, 12}}, false},
		{[4]image.Point{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, true},
		{[4]image.Point{{0, 0}, {0, 0}, {0, 0}, {0, 0}}, false},
		{[4]image.Point{{0, 4}, {4, 6}, {3, 3}, {1, 7}}, true},
		{[4]image.Point{{11, 23}, {16, 32}, {18, 18}, {23, 25}}, false},
		{[4]image.Point{{2, 2}, {8, 15}, {-11, 8}, {-5, 21}}, true},
		{[4]image.Point{{-16, 20}, {-18, 3}, {-1, -1}, {3, 16}}, false},
		{[4]image.Point{{-28, 16}, {-27, 11}, {-22, 17}, {-21, 11}}, false},
		{[4]image.Point{{41, -37}, {49, 10}, {2, 18}, {-6, -29}}, true},
		{[4]image.Point{{-74, 89}, {-28, 71}, {-46, 25}, {-92, 43}}, true},
		{[4]image.Point{{23, 36}, {1, -36}, {45, -14}, {-21, 8}}, false},
		{[4]image.Point{{-29, 88}, {-43, 19}, {-112, 33}, {-98, 102}}, true},
		{[4]image.Point{{15, 125}, {-86, 133}, {-31, 179}, {-41, 78}}, false},
		{[4]image.Point{{-149, 115}, {-28, 158}, {-110, 197}, {-67, 76}}, true},
		{[4]image.Point{{148, 349}, {169, 96}, {32, 212}, {285, 233}}, true},
		{[4]image.Point{{-84, 19}, {56, -48}, {-2, -187}, {-141, -130}}, false},
		{[4]image.Point{{77, -133}, {42, 164}, {207, 34}, {-91, -3}}, false},
		{[4]image.Point{{-922, 84}, {-1088, 1061}, {55, 250}, {-111, 1227}}, true},
		{[4]image.Point{{53, 2547}, {22, 787}, {919, 1650}, {-840, 1681}}, false},
		{[4]image.Point{{-1040, 1021}, {-1069, 729}, {-748, 992}, {-777, 700}}, true},
	}

	for _, t := range tab {
		assert(square(t.p[0], t.p[1], t.p[2], t.p[3]) == t.r)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func dsq(p1, p2 image.Point) int {
	dy := p2.Y - p1.Y
	dx := p2.X - p1.X
	return dx*dx + dy*dy
}

func valid(p1, p2, p3, p4 image.Point) bool {
	return dsq(p1, p2) > 0 &&
		dsq(p1, p2) == dsq(p2, p3) &&
		dsq(p2, p3) == dsq(p3, p4) &&
		dsq(p3, p4) == dsq(p4, p1) &&
		dsq(p1, p3) == dsq(p2, p4)
}

func square(p1, p2, p3, p4 image.Point) bool {
	return valid(p1, p2, p3, p4) || valid(p1, p3, p2, p4) || valid(p1, p2, p4, p3)
}
