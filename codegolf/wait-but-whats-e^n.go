/*

Objective:

The objective is to calculate e^N for some real or imaginary N (e.g. 2, -3i, 0.7, 2.5i, but not 3+2i). This is code golf, so, shortest code (in bytes) wins.

So, for example:

    N = 3, e^N = 20.0855392
    N = -2i, e^N = -0.416146837 - 0.9092974268i

The letter i shouldn't be capitalized (since in math it is lowercase)

If your language supports raising numbers to complex numbers, you can't use that. You may use built-in real exponentiation.

For any answer where b (in a + bi) is negative, it is OK to have both the plus and minus sign (e.g. 2 + -3i), since that is understood to be (2 - 3i)

Bonus (-15 bytes): Solve this for N is a any complex number (e.g. 5 + 7i). If you are going for the bonus, you can assume that both components will always be given (even for the standard objective)

*/

package main

import (
	"fmt"
	"math/cmplx"
)

func main() {
	fmt.Println(cmplx.Exp(3))
	fmt.Println(cmplx.Exp(-2i))
}
