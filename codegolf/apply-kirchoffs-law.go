/*

Kirchhoff's law says that when you sum up all the currents (positive for the currents going to a junction, and negative for current leaving a junction), you will always get as result 0.

Using Kirchhoff's law, you can see that i1 + i4 - i2 - i3 = 0, so i1 + i4 = i2 + i3.

Given two lists, one with all the currents entering the junction and one with all the currents leaving the junction except one, output the last one.

Testcases:

[1, 2, 3], [1, 2] = 3
[4, 5, 6], [7, 8] = 0
[5, 7, 3, 4, 5, 2], [8, 4, 5, 2, 1] = 6

The second list always has one item less than the first list. The output cannot be negative. Smallest program wins.

*/

package main

import "fmt"

func main() {
	fmt.Println(lc([]float64{1, 2, 3}, []float64{1, 2}))
	fmt.Println(lc([]float64{4, 5, 6}, []float64{7, 8}))
	fmt.Println(lc([]float64{5, 7, 3, 4, 5, 2}, []float64{8, 4, 5, 2, 1}))
}

func lc(in, out []float64) float64 {
	s := 0.0
	for i := range in {
		s += in[i]
	}
	for i := range out {
		s -= out[i]
	}
	return s
}
