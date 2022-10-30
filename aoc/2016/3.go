/*

--- Day 3: Squares With Three Sides ---
Now that you can think clearly, you move deeper into the labyrinth of hallways and office furniture that makes up this part of Easter Bunny HQ. This must be a graphic design department; the walls are covered in specifications for triangles.

Or are they?

The design document gives the side lengths of each triangle it describes, but... 5 10 25? Some of these aren't triangles. You can't help but mark the impossible ones.

In a valid triangle, the sum of any two sides must be larger than the remaining side. For example, the "triangle" given above is impossible, because 5 + 10 is not larger than 25.

In your puzzle input, how many of the listed triangles are possible?

--- Part Two ---
Now that you've helpfully marked up their design documents, it occurs to you that triangles are specified in groups of three vertically. Each set of three numbers in a column specifies a triangle. Rows are unrelated.

For example, given the following specification, numbers with the same hundreds digit would be part of the same triangle:

101 301 501
102 302 502
103 303 503
201 401 601
202 402 602
203 403 603
In your puzzle input, and instead reading by columns, how many of the listed triangles are possible?

*/

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

func main() {
	v, err := readvals("3.txt")
	check(err)

	fmt.Println(part1(v))
	fmt.Println(part2(v))
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func readvals(name string) ([][3]int, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	var r [][3]int
	s := bufio.NewScanner(f)
	for s.Scan() {
		var x, y, z int
		l := s.Text()
		n, _ := fmt.Sscanf(l, "%d %d %d", &x, &y, &z)
		if n == 3 {
			r = append(r, [3]int{x, y, z})
		}
	}
	return r, nil
}

func triangle(x, y, z int) bool {
	if x > y {
		x, y = y, x
	}
	if x > z {
		x, z = z, x
	}
	if y > z {
		y, z = z, y
	}
	return x+y > z
}

func part1(v [][3]int) int {
	c := 0
	for _, v := range v {
		if triangle(v[0], v[1], v[2]) {
			c++
		}
	}
	return c
}

func part2(v [][3]int) int {
	c := 0
	for i := 0; i+2 < len(v); i += 3 {
		for j := 0; j < 3; j++ {
			if triangle(v[i][j], v[i+1][j], v[i+2][j]) {
				c++
			}
		}
	}
	return c
}
