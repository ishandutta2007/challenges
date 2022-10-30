/*

Given an object with students and the grades that they made on the tests that they took, determine which student has the best Test Average.
The key will be the student's name and the value will be an array of their grades.
You will only have to return the student's name. You do not need to return their Test Average.

Notes

All students in an object will have the same amount of test scores.
So no student will have taken more tests than another.

*/

package main

import "fmt"

func main() {
	fmt.Println(beststudent(map[string][]int{
		"John": []int{100, 90, 80},
		"Bob":  []int{100, 70, 80},
	}))

	fmt.Println(beststudent(map[string][]int{
		"Susan": []int{64, 84, 75, 63},
		"Mike":  []int{87, 98, 64, 71},
		"Jim":   []int{90, 58, 73, 86},
	}))

	fmt.Println(beststudent(map[string][]int{
		"Tim":   []int{94, 84, 49, 71, 76, 83},
		"Nick":  []int{88, 91, 74, 72, 63, 68},
		"Brad":  []int{100, 94, 72, 64, 58, 81},
		"Annie": []int{79, 93, 82, 82, 63, 87},
	}))

	fmt.Println(beststudent(map[string][]int{
		"Eddie":   []int{65, 85, 72, 76},
		"Brock":   []int{55, 97, 82, 91},
		"Jessica": []int{78, 62, 79, 99},
	}))
}

func beststudent(g map[string][]int) string {
	m := 0.0
	s := ""
	for k, v := range g {
		n := average(v)
		if m < n {
			m, s = n, k
		}
	}
	return s
}

func average(x []int) float64 {
	m := 0
	for i := range x {
		m += x[i]
	}
	return float64(m) / float64(len(x))
}
