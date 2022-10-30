/*

Consider a stream/file with one integer per line. For example:

123
5
99
Your code should output the sum of these numbers, that is 227.

The input format is strictly one integer per line. You cannot, for example, assume the input is on one line as an array of integers.

You can take input either from STDIN, in form of a filename, or a file with a name of your choice; you can choose which one. No other ways of getting input are allowed.

The input will contain at least one integer. You can assume all integers are non-negative and that their total sum is less than 232.

*/

package main

import (
	"fmt"
	"io"
	"os"
)

func main() {
	fmt.Println(sum(os.Stdin))
}

func sum(r io.Reader) int {
	s := 0
	for {
		var v int
		_, err := fmt.Fscanf(r, "%d", &v)
		if err != nil {
			break
		}

		s += v
	}
	return s
}
