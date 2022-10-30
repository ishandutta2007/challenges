/*

An army of ants walk on a horizontal pole of length l cm, each with a constant speed of 1 cm/s.
When a walking ant reaches an end of the pole, it immediatelly falls off it.
When two ants meet they turn back and start walking in opposite directions. We know the original positions of ants on the pole, unfortunately, we do not know the directions in which the ants are walking.
Your task is to compute the earliest and the latest possible times needed for all ants to fall off the pole.

Input

The first line of input contains one integer giving the number of cases that follow, at most 100.
The data for each case start with two integer numbers: the length l of the pole (in cm) and n, the number of ants residing on the pole.
These two numbers are followed by n integers giving the position of each ant on the pole as the distance measured from the left end of the pole, in no particular order.
All input integers are between 0 and 1000000 and they are separated by whitespace.

Output

For each case of input, output two numbers separated by a single space.
The first number is the earliest possible time when all ants fall off the pole (if the directions of their walks are chosen appropriately) and the second number is the latest possible such time.

*/

package main

import "fmt"

func main() {
	test(10, []int{2, 6, 7}, 4, 8)
	test(214, []int{11, 12, 7, 13, 176, 23, 191}, 38, 207)
}

func test(l int, a []int, r0, r1 int) {
	t0, t1 := ants(l, a)
	fmt.Println(t0, t1)
	assert(t0 == r0 && t1 == r1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func ants(l int, a []int) (t0, t1 int) {
	for _, m := range a {
		k := l - m
		if m < k {
			m, k = k, m
		}
		if k > t0 {
			t0 = k
		}
		if m > t1 {
			t1 = m
		}
	}
	return
}
