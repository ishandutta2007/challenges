/*

Chef has recently learnt some new facts about the famous number π. For example, he was surprised that ordinary fractions are sometimes used to represent this number approximately. For example, 22/7, 355/113 or even 103993/33102.

Soon, by calculating the value of 22/7 and 355/113 on paper Chef became quite disappointed because these values are not precise enough. For example, 22/7 differs in the third digit after the decimal point. So, these values are definitely should not be used for serious calculations.

However, Chef doesn't know anything about 103993/33102. This fraction is quite inconvenient to calculate on paper. Chef is curious how precise this value is. So he asks you to help him and to calculate the first K digits after the decimal point of such an approximation of π. He consider this ordinary fraction as infinite decimal fraction so formally he asks you to calculate this approximation truncated to the first K digits after the decimal point.

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	fmt.Println(calc(0))
	fmt.Println(calc(6))
	fmt.Println(calc(20))
	fmt.Println(calc(50))
	fmt.Println(calc(100))
	fmt.Println(calc(500))
	fmt.Println(calc(1e6))
}

func calc(n int) string {
	r := big.NewRat(103993, 33102)
	s := r.FloatString(n + 1)
	return s[:len(s)-1]
}
