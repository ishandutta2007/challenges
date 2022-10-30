/*

Intro:

I remember, when I was a kid, I would get a calculator and keep on pressing the + button, and see how high I could count. Now, I like to program, and I'm developing for iOS.

Counting is a fundamental skill for both humans and computers alike to do. Without it, the rest of math can't be done. It's done simply by starting at 1 and repetitively adding 1 to it.
The challenge:

This is but a simple challenge. What I would like your program to do is print from 1 to whatever Integer it takes in. However, I'll throw a twist in it, since decimal counting is kinda boring:

The counting cannot be in base 10, it has to show itself counting in binary.

So, to count to 5, using 32-bit integers, it would look like this:

0000 0000 0000 0000 0000 0000 0000 0001 ..... 1
0000 0000 0000 0000 0000 0000 0000 0010 ..... 2
0000 0000 0000 0000 0000 0000 0000 0011 ..... 3
0000 0000 0000 0000 0000 0000 0000 0100 ..... 4
0000 0000 0000 0000 0000 0000 0000 0101 ..... 5

It's a computer. They know binary best. Your input can be either a 32-bit or 64-bit integer.
It is truly up to you. However, if you use 32-bit integers, your output must be 32-bit integers in binary, and if you use 64-bit integers, your output must be 64-bit integers in binary.
Sample input:

a 32-bit integer, 5
Sample output:

0000 0000 0000 0000 0000 0000 0000 0001
0000 0000 0000 0000 0000 0000 0000 0010
0000 0000 0000 0000 0000 0000 0000 0011
0000 0000 0000 0000 0000 0000 0000 0100
0000 0000 0000 0000 0000 0000 0000 0101

Scoring:

Your score is equal to however many bytes your code is. As this is Code Golf, lowest score wins.
Bonus points:

If you show, in the output, the number it's at as a base 10 number (for example, 0000 0000 0000 0000 0000 0000 0000 0001 in binary is equal to the base 10 1), multiply your score by 0.8.

If you group 4 digits of output like I did, then multiply your score by 0.8 (again). This isn't required.

Do not round up, and do not round down. Your score is a floating-point number.
Good luck!

*/

package main

import "fmt"

func main() {
	count(5)
	count(100)
}

func count(n uint32) {
	for i := uint64(1); i <= uint64(n); i++ {
		fmt.Printf("%032b\n", i)
	}
	fmt.Println()
}
