/*

Comparing two numbers written in index form like 211 and 37 is not difficult, as any calculator would confirm that 211 = 2048 < 37 = 2187.

However, confirming that 632382518061 > 519432525806 would be much more difficult, as both numbers contain over three million digits.

Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K text file containing one thousand lines with a base/exponent pair on each line, determine which line number has the greatest numerical value.

NOTE: The first two lines in the file represent the numbers in the example given above.

*/

package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
	"os"
)

func main() {
	n, err := largest("p099_base_exp.txt")
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(n)
}

func largest(name string) (int, error) {
	f, err := os.Open(name)
	if err != nil {
		return 0, err
	}
	defer f.Close()

	z := 0.0
	l := 0
	s := bufio.NewScanner(f)
	for ln := 1; s.Scan(); ln++ {
		var b, e uint64
		n, _ := fmt.Sscanf(s.Text(), "%d,%d", &b, &e)
		if n != 2 {
			return 0, fmt.Errorf("invalid input at line: %d", ln)
		}

		w := float64(e) * math.Log10(float64(b))
		if w > z {
			z = w
			l = ln
		}
	}

	return l, nil
}
