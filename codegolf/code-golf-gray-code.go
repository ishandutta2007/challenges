/*

The Challenge
The shortest program by character count that outputs the n-bit Gray Code. n will be an arbitrary number smaller than 1000100000 (due to user suggestions) that is taken from standard input. The gray code will be printed in standard output, like in the example.

Note: I don't expect the program to print the gray code in a reasonable time (n=100000 is overkill); I do expect it to start printing though.

Example
Input:

4
Expected Output:

0000
0001
0011
0010
0110
0111
0101
0100
1100
1101
1111
1110
1010
1011
1001
1000

*/

package main

import "fmt"

func main() {
	gen(4)
}

func gen(n uint) {
	for i := uint(0); i < 1<<n; i++ {
		fmt.Printf("%0*b\n", n, bin2gray(i))
	}
}

func bin2gray(n uint) uint {
	return n ^ (n >> 1)
}
