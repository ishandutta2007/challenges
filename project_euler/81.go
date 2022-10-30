/*


In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down, is indicated in bold red and is equal to 2427.

[131 673 234 103 18]
[201 96 342 965 150]
[630 803 746 422 111]
[537 699 497 121 956]
[805 732 524 37 331]

Find the minimal path sum from the top left to the bottom right by only moving right and down in matrix.txt (right click and "Save Link/Target As..."), a 31K text file containing an 80 by 80 matrix.

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
	s, err := solve("p081_matrix.txt")
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(s)
}

// https://www.mathblog.dk/project-euler-81-find-the-minimal-path-sum-from-the-top-left-to-the-bottom-right-by-moving-right-and-down/
func solve(name string) (int, error) {
	p, err := readgrid(name)
	if err != nil {
		return 0, err
	}
	return pathsum(p), nil
}

func pathsum(p [][]int) (s int) {
	defer func() {
		if e := recover(); e != nil {
			s = -1
		}
	}()

	n := len(p[0])
	for i := n - 2; i >= 0; i-- {
		p[n-1][i] += p[n-1][i+1]
		p[i][n-1] += p[i+1][n-1]
	}
	for i := n - 2; i >= 0; i-- {
		for j := n - 2; j >= 0; j-- {
			p[i][j] += min(p[i+1][j], p[i][j+1])
		}
	}
	return p[0][0]
}

func readgrid(name string) (p [][]int, err error) {
	f, err := os.Open(name)
	if err != nil {
		return
	}
	defer f.Close()

	s := bufio.NewScanner(f)
	for s.Scan() {
		var q []int
		t := strings.Split(s.Text(), ",")
		for _, t := range t {
			n, _ := strconv.Atoi(t)
			q = append(q, n)
		}
		p = append(p, q)
	}
	return
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
