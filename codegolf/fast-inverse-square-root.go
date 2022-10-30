/*

Inspired by http://meta.codegolf.stackexchange.com/questions/547/write-a-code-golf-problem-in-which-script-languages-are-at-a-major-disadvantage question on meta, I've decided to make a question which could be problematic for scripting languages.

The goal is to calculate fast inverse square root, just like it was done in Quake III Arena.
You will get the floating point number as first argument after program name and you should implement it.
Simply doing ** -0.5 is disallowed as it doesn't implement the algorithm.

Your program will be called like this. The 12.34 could be other value.

$ interpreter program 12.34 # for interpreted languages
$ ./a.out 12.34 # for compiled languages

For comparison, this is original Quake III Arena implementation.

float Q_rsqrt( float number )
{
        long i;
        float x2, y;
        const float threehalfs = 1.5F;

        x2 = number * 0.5F;
        y = number;
        i = * ( long * ) &y;                       // evil floating point bit level hacking
        i = 0x5f3759df - ( i >> 1 );               // what the heck?
        y = * ( float * ) &i;
        y = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//      y = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

        return y;
}

You have to do just one iteration because the second was commented out.

Winning condition: Shortest code.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	m := 0.0
	for i := float32(1); i <= 100000; i += 1e-2 {
		x := 1 / math.Sqrt(float64(i))
		y := rsqrt(i)
		e := math.Abs(x - float64(y))
		if e > m {
			m = e
		}
	}
	fmt.Printf("max error %v\n", m)
}

func rsqrt(x float32) float32 {
	const threehalfs = 1.5

	x2 := x * 0.5
	y := x
	i := math.Float32bits(y)
	i = 0x5f3759df - (i >> 1)
	y = math.Float32frombits(i)
	y = y * (threehalfs - (x2 * y * y))
	y = y * (threehalfs - (x2 * y * y))
	return y
}
