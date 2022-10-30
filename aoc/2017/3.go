/*

--- Day 3: Spiral Memory ---
You come across an experimental new kind of memory stored on an infinite two-dimensional grid.

Each square on the grid is allocated in a spiral pattern starting at a location marked 1 and then counting up while spiraling outward. For example, the first few squares are allocated like this:

17  16  15  14  13
18   5   4   3  12
19   6   1   2  11
20   7   8   9  10
21  22  23---> ...

While this is very space-efficient (no squares are skipped), requested data must be carried back to square 1 (the location of the only access port for this memory system) by programs that can only move up, down, left, or right.
They always take the shortest path: the Manhattan Distance between the location of the data and square 1.

For example:

Data from square 1 is carried 0 steps, since it's at the access port.
Data from square 12 is carried 3 steps, such as: down, left, left.
Data from square 23 is carried only 2 steps: up twice.
Data from square 1024 must be carried 31 steps.
How many steps are required to carry the data from the square identified in your puzzle input all the way to the access port?

--- Part Two ---
As a stress test on the system, the programs here clear the grid and then store the value 1 in square 1. Then, in the same allocation order as shown above, they store the sum of the values in all adjacent squares, including diagonals.

So, the first few squares' values are chosen as follows:

Square 1 starts with the value 1.
Square 2 has only one adjacent filled square (with value 1), so it also stores 1.
Square 3 has both of the above squares as neighbors and stores the sum of their values, 2.
Square 4 has all three of the aforementioned squares as neighbors and stores the sum of their values, 4.
Square 5 only has the first and fourth squares as neighbors, so it gets the value 5.
Once a square is written, its value does not change. Therefore, the first few squares would receive the following values:

147  142  133  122   59
304    5    4    2   57
330   10    1    1   54
351   11   23   25   26
362  747  806--->   ...
What is the first value written that is larger than your puzzle input?

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	N := 347991
	fmt.Println(part1(N))
	fmt.Println(part2(N))
}

func part1(n int) int {
	x, y := spiral(n)
	return abs(x) + abs(y)
}

func part2(n int) int {
	for i := 0; i < n; i++ {
		v := spiralsum(i)
		if v > n || v < 0 {
			return v
		}
	}
	return -1
}

// https://math.stackexchange.com/questions/163080/on-a-two-dimensional-grid-is-there-a-formula-i-can-use-to-spiral-coordinates-in
// https://upload.wikimedia.org/wikipedia/commons/1/1d/Ulam_spiral_howto_all_numbers.svg
func spiral(n int) (x, y int) {
	k := int(math.Ceil((math.Sqrt(float64(n)) - 1) / 2))
	t := 2*k + 1
	m := t * t
	t = t - 1

	if n >= m-t {
		return k - (m - n), -k
	}

	m -= t
	if n >= m-t {
		return -k, -k + (m - n)
	}

	m -= t
	if n >= m-t {
		return -k + (m - n), k
	}

	return k, k - (m - n - t)
}

// https://oeis.org/A141481
func spiralsum(n int) int {
	tab := []int{
		1, 1, 2, 4, 5, 10, 11,
		23, 25, 26, 54, 57, 59, 122, 133,
		142, 147, 304, 330, 351, 362, 747, 806,
		880, 931, 957, 1968, 2105, 2275, 2391, 2450,
		5022, 5336, 5733, 6155, 6444, 6591, 13486, 14267,
		15252, 16295, 17008, 17370, 35487, 37402, 39835, 42452,
		45220, 47108, 48065, 98098, 103128, 109476, 116247, 123363,
		128204, 130654, 266330, 279138, 295229, 312453, 330785, 349975,
		363010, 369601, 752688, 787032, 830037, 875851, 924406, 975079,
		1009457, 1026827, 2089141, 2179400, 2292124, 2411813, 2539320, 2674100,
		2814493, 2909666, 2957731, 6013560, 6262851, 6573553, 6902404, 7251490,
		7619304, 8001525, 8260383, 8391037, 17048404, 17724526, 18565223, 19452043,
		20390510, 21383723, 22427493, 23510079, 24242690, 24612291, 49977270, 51886591,
		54256348, 56749268, 59379562, 62154898, 65063840, 68075203, 70111487, 71138314,
		144365769, 149661137, 156221802, 163105139, 170348396, 177973629, 186001542, 194399801,
		203081691, 208949088, 211906819, 429827198, 445061340, 463911304, 483650112, 504377559,
		526150757, 549023076, 572904288, 597557233, 614208653, 622599690, 1262247784, 1305411751,
		1358749904, 1414491696, 1472899472, 1534125748, 1598327474, 1665648769, 1735829031, 1808194091,
		1857049072, 1881661363,
	}
	if n >= len(tab) {
		return -1
	}
	return tab[n]
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
