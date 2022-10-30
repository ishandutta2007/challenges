/*

In physics, like electric charges repel, and unlike charges attract.

The potential energy between two unit charges separated by a distance d is 1/d for like charges and -1/d for unlike charges. The potential energy of a system of charges is the sum of the potential energies between all pairs of charges.

Challenge
Determine the potential energy of a system of unit charges represented by a string.

This is code-golf, so the shortest solution in bytes wins.

Input
A nonempty multiline string, consisting of only +, -,   and newlines, with each line a constant width. The + and - represent charges of +1 and -1 respectively. For example, the following string:

    + -
 +
(considering the top-left to be the origin) represents a system with positive charges at (4,0) and (1,-1) and a negative charge at (6,0).

Alternatively, you may take input as a list of lines.

Output
A signed real number representing the potential energy of the system of charges. Output should be correct to four significant figures or 10-4, whichever is looser.

Test cases:
   -

Should output 0. There are no pairs of charges to repel or attract, and the whitespace doesn't change anything.

+
  -
There are only two charges; they are 1 unit away in the vertical direction and 2 units away in the horizontal direction, so their distance is sqrt(5). Output should be -1/sqrt(5)=-0.447213595.

+       -
-       +
Should give -2.001930531.

 - -- -+ - - -+-++-+
 +-- + +-- + ++-++ -
---++-+-+- -+- - +-
-- - -++-+  --+  +
-   + --+ ++-+  +-
--  ++- + +  -+--+
+ +++-+--+ +--+++ +
-+- +-+-+-+  -+ +--+
- +-+- +      ---+
-     - ++ -+- --+--
Should give -22.030557890.

---+--- ++-+++- -+ +
-+ ---+++-+- +- +  +
---+-+ - ----  +-- -
 -   + +--+ -++- - -
--+ - --- - -+---+ -
+---+----++ -   +  +
-+ - ++-- ++-  -+++
 +----+-   ++-+-+  -
++- -+ -+---+  -- -+
+-+++ ++-+-+ -+- +-
Should give 26.231088767.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test([]string{
		"   - ",
		"     ",
	}, 0)

	test([]string{
		"+  ",
		"  -",
	}, -0.447213595)

	test([]string{
		"+       -",
		"-       +",
	}, -2.001930531)

	test([]string{
		" - -- -+ - - -+-++-+",
		" +-- + +-- + ++-++ -",
		"---++-+-+- -+- - +- ",
		"-- - -++-+  --+  +  ",
		"-   + --+ ++-+  +-  ",
		"--  ++- + +  -+--+  ",
		"+ +++-+--+ +--+++ + ",
		"-+- +-+-+-+  -+ +--+",
		"- +-+- +      ---+  ",
		"-     - ++ -+- --+--",
	}, -22.030557890)

	test([]string{
		"---+--- ++-+++- -+ +",
		"-+ ---+++-+- +- +  +",
		"---+-+ - ----  +-- -",
		" -   + +--+ -++- - -",
		"--+ - --- - -+---+ -",
		"+---+----++ -   +  +",
		"-+ - ++-- ++-  -+++ ",
		" +----+-   ++-+-+  -",
		"++- -+ -+---+  -- -+",
		"+-+++ ++-+-+ -+- +- ",
	}, 26.231088767)
}

func test(s []string, r float64) {
	p := potentials(s)
	fmt.Println(p)
	assert(math.Abs(p-r) < 1e-8)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func potentials(s []string) float64 {
	p := particles(s)
	n := len(p)
	r := 0.0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			s := 1.0
			if p[i].c != p[j].c {
				s = -s
			}
			r += s / distance(p[i], p[j])
		}
	}
	return r
}

func particles(s []string) []Particle {
	var p []Particle
	for y := range s {
		for x, r := range s[y] {
			switch r {
			case '+', '-':
				p = append(p, Particle{x, y, r})
			}
		}
	}
	return p
}

func distance(a, b Particle) float64 {
	dx := float64(a.x - b.x)
	dy := float64(a.y - b.y)
	return math.Hypot(dx, dy)
}

type Particle struct {
	x, y int
	c    rune
}
