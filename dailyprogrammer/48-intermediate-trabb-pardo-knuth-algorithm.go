/*

Your task is to write a program that implements the Trabb Pardo Knuth algorithm.

*/

package main

import (
	"fmt"
	"io"
	"math"
)

func main() {
	var a [11]float64
	for i := range a {
		_, err := fmt.Scan(&a[i])
		if err == io.EOF {
			return
		}
	}

	for i := len(a) - 1; i >= 0; i-- {
		y := f(a[i])
		if y > 400 {
			fmt.Printf("%d TOO LARGE\n", i)
		} else {
			fmt.Printf("%d %.16g\n", i, y)
		}
	}
}

func f(t float64) float64 {
	return math.Sqrt(math.Abs(t)) + 5*math.Pow(t, 3)
}
