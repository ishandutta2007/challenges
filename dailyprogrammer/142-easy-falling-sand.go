/*

 (Easy): Falling Sand

Falling-sand Games are particle-simulation games that focus on the interaction between particles in a 2D-world. Sand, as an example, might fall to the ground forming a pile.
Other particles might be much more complex, like fire, that might spread depending on adjacent particle types.

Your goal is to implement a mini falling-sand simulation for just sand and stone. The simulation is in 2D-space on a uniform grid, where we are viewing this grid from the side. Each type's simulation properties are as follows:

    Stone always stays where it was originally placed. It never moves.

    Sand keeps moving down through air, one step at a time, until it either hits the bottom of the grid, other sand, or stone.

Formal Inputs & Outputs
Input Description

On standard console input, you will be given an integer N which represents the N x N grid of ASCII characters.
This means there will be N-lines of N-characters long. This is the starting grid of your simulated world: the character ' ' (space) means an empty space, while '.' (dot) means sand, and '#' (hash or pound) means stone.
Once you parse this input, simulate the world until all particles are settled (e.g. the sand has fallen and either settled on the ground or on stone). "Ground" is defined as the solid surface right below the last row.
Output Description

Print the end result of all particle positions using the input format for particles.
Sample Inputs & Outputs
Sample Input

5
.....
  #
#

    .

Sample Output

  .
. #
#
    .
 . ..

*/

package main

import (
	"fmt"
	"io"
	"os"
	"strings"
)

func main() {
	const s1 = `
5
.....
  #  
#    
     
    .
`

	test(s1)
}

func test(s string) {
	s = strings.Trim(s, "\n")
	r := strings.NewReader(s)

	var sp Sandpile
	sp.Load(r)
	sp.Output(os.Stdout)
	sp.Sim()
	sp.Output(os.Stdout)
}

type Sandpile struct {
	rp, wp [][]rune
	pile   [][]rune
}

func (c *Sandpile) Load(r io.Reader) {
	var (
		n  int
		nl rune
	)
	fmt.Fscanf(r, "%d\n", &n)

	c.rp, c.wp = c.alloc(n), c.alloc(n)
	for y := 0; y < n; y++ {
		for x := 0; x < n; x++ {
			fmt.Fscanf(r, "%c", &c.rp[y][x])
		}
		fmt.Fscanf(r, "%c", &nl)
	}
	c.pile = c.rp
}

func (*Sandpile) alloc(n int) [][]rune {
	p := make([][]rune, n)
	for i := range p {
		p[i] = make([]rune, n)
	}
	return p
}

func (c *Sandpile) Sim() {
	for !c.Step() {
	}
}

func (c *Sandpile) Step() bool {
	for y := range c.wp {
		copy(c.wp[y], c.rp[y])
	}

	eof := true
	n := len(c.rp)
	for y := 0; y < n; y++ {
		for x := 0; x < n; x++ {
			if c.rp[y][x] != '.' || y+1 >= n || c.rp[y+1][x] != ' ' {
				continue
			}
			c.wp[y][x] = ' '
			c.wp[y+1][x] = '.'
			eof = false
		}
	}
	c.rp, c.wp = c.wp, c.rp
	c.pile = c.rp
	return eof
}

func (c *Sandpile) Output(w io.Writer) {
	for y := range c.pile {
		fmt.Fprintf(w, "|")
		for x := range c.pile[y] {
			fmt.Fprintf(w, "%c", c.pile[y][x])
		}
		fmt.Fprintf(w, "|")
		fmt.Fprintf(w, "\n")
	}
	fmt.Fprintf(w, "\n")
}
