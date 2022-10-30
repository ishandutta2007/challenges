/*

If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?

*/

package main

import (
	"flag"
	"fmt"
	"strconv"
)

func main() {
	P := 1000
	flag.Parse()
	if flag.NArg() >= 1 {
		P, _ = strconv.Atoi(flag.Arg(0))
	}
	fmt.Println(count(P))
}

func count(n int) (mc, mp int) {
	for p := 2; p <= n; p += 2 {
		c := 0
		for a := 2; a < p/3; a++ {
			if p*(p-2*a)%(2*(p-a)) == 0 {
				c++
			}
		}
		if c > mc {
			mc, mp = c, p
		}
	}
	return mc, mp
}
