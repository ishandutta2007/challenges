/*

Write a function graph(f, low, high, tests) that outputs a probability graph of the function f from range low to high (inclusive) over tests tests (i.e., counting the frequencies of f() outputs).
f takes no arguments and returns an integer, low, high and tests are all integer values. For example, a function f that simulates two-dice rolls:

def two_dice():
    return random.randint(1, 6) + random.randint(1, 6)

Then graph(f, 2, 12, 10000) should output something roughly like:

  2: ##
  3: #####
  4: #######
  5: ###########
  6: #############
  7: #################
  8: #############
  9: ###########
 10: ########
 11: #####
 12: ##

For bonus points, output the graph with the numbers on the bottom and the bars drawn vertically.

*/

package main

import (
	"fmt"
	"math"
	"math/rand"
	"strings"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	graph(makedice(2, 6), 2, 12, 10000)
	for i := 1; i <= 6; i++ {
		graph(makedice(i, 6), 1, 36, 10000)
	}
}

func graph(f func() int, low, high, tests int) {
	n := high - low + 1
	g := make([]int, n)
	for i := 0; i < tests; i++ {
		if x := f(); low <= x && x <= high {
			g[x-low]++
		}
	}

	l := math.Ceil(math.Log10(math.Abs(float64(n)))) + 1
	for i, v := range g {
		p := float64(v) / float64(tests) * 100
		fmt.Printf("%*d: %s\n", int(l), low+i, strings.Repeat("#", int(p)))
	}
	fmt.Println()
}

func makedice(n, s int) func() int {
	return func() int {
		r := 0
		for i := 0; i < n; i++ {
			r += 1 + rand.Intn(s)
		}
		return r
	}
}
