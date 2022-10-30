/*

Output the following result (which is a result of calculating 6 * 9 in bases from 2 to 36). Make sure letters are uppercase, and the multiplication itself is outputed on every line.

6 * 9 = 110110
6 * 9 = 2000
6 * 9 = 312
6 * 9 = 204
6 * 9 = 130
6 * 9 = 105
6 * 9 = 66
6 * 9 = 60
6 * 9 = 54
6 * 9 = 4A
6 * 9 = 46
6 * 9 = 42
6 * 9 = 3C
6 * 9 = 39
6 * 9 = 36
6 * 9 = 33
6 * 9 = 30
6 * 9 = 2G
6 * 9 = 2E
6 * 9 = 2C
6 * 9 = 2A
6 * 9 = 28
6 * 9 = 26
6 * 9 = 24
6 * 9 = 22
6 * 9 = 20
6 * 9 = 1Q
6 * 9 = 1P
6 * 9 = 1O
6 * 9 = 1N
6 * 9 = 1M
6 * 9 = 1L
6 * 9 = 1K
6 * 9 = 1J
6 * 9 = 1I

Shortest code wins.

*/

package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	table(6, 9)
}

func table(a, b int64) {
	for i := 2; i <= 36; i++ {
		s := strconv.FormatInt(a*b, i)
		s = strings.ToUpper(s)
		fmt.Printf("%d * %d = %s\n", a, b, s)
	}
}
