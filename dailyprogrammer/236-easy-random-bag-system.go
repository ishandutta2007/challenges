/*

Description

Contrary to popular belief, the tetromino pieces you are given in a game of Tetris are not randomly selected.
Instead, all seven pieces are placed into a "bag." A piece is randomly removed from the bag and presented to the player until the bag is empty.
When the bag is empty, it is refilled and the process is repeated for any additional pieces that are needed.

In this way, it is assured that the player will never go too long without seeing a particular piece.
It is possible for the player to receive two identical pieces in a row, but never three or more.
Your task for today is to implement this system.

Input Description

None.
Output Description

Output a string signifying 50 tetromino pieces given to the player using the random bag system. This will be on a single line.

The pieces are as follows:

    O
    I
    S
    Z
    L
    J
    T

Sample Inputs

None.
Sample Outputs

    LJOZISTTLOSZIJOSTJZILLTZISJOOJSIZLTZISOJTLIOJLTSZO
    OTJZSILILTZJOSOSIZTJLITZOJLSLZISTOJZTSIOJLZOSILJTS
    ITJLZOSILJZSOTTJLOSIZIOLTZSJOLSJZITOZTLJISTLSZOIJO

Note

Although the output is semi-random, you can verify whether it is likely to be correct by making sure that pieces do not repeat within chunks of seven.
Credit

This challenge was developed by /u/chunes on /r/dailyprogrammer_ideas. If you have any challenge ideas please share them there and there's a chance we'll use them.
Bonus

Write a function that takes your output as input and verifies that it is a valid sequence of pieces.

*/

package main

import (
	"bytes"
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 10; i++ {
		fmt.Println(gen(50))
	}
}

func gen(n int) string {
	const pieces = "OISZLJT"

	w := new(bytes.Buffer)
	l := 0
	for i := 0; i < n; i += l {
		l = min(len(pieces), n-i)
		p := rand.Perm(l)
		for _, j := range p {
			w.WriteByte(pieces[j])
		}
	}
	return w.String()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
