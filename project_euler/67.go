/*

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.

NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, as there are 299 altogether! If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)

*/

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

func main() {
	t1 := [][]int{
		{3},
		{7, 4},
		{2, 4, 6},
		{8, 5, 9, 3},
	}
	fmt.Println(maxpath(t1))

	t2 := [][]int{
		{75},
		{95, 64},
		{17, 47, 82},
		{18, 35, 87, 10},
		{20, 4, 82, 47, 65},
		{19, 1, 23, 75, 3, 34},
		{88, 2, 77, 73, 7, 63, 67},
		{99, 65, 4, 28, 6, 16, 70, 92},
		{41, 41, 26, 56, 83, 40, 80, 70, 33},
		{41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
		{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
		{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
		{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
		{63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
		{04, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23},
	}
	fmt.Println(maxpath(t2))

	t, err := readints("p067_triangle.txt")
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(maxpath(t))
}

func readints(name string) ([][]int, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	var t [][]int
	s := bufio.NewScanner(f)
	for s.Scan() {
		l := s.Text()
		p := strings.Split(l, " ")
		u := make([]int, len(p))
		for i := range p {
			u[i], _ = strconv.Atoi(p[i])
		}
		t = append(t, u)
	}

	return t, nil
}

func maxpath(t [][]int) int {
	p := make([][]int, len(t))
	for i := range p {
		p[i] = append(p[i], t[i]...)
	}
	for i := len(p) - 2; i >= 0; i-- {
		for j := 0; j <= i; j++ {
			p[i][j] += max(p[i+1][j], p[i+1][j+1])
		}
	}
	return p[0][0]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
