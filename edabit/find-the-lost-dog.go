/*

0 represents the dog.
Each list represents a house and each 1 represents an empty room.
Return the house and the room where it is located, there can be only one dog lost per building.

Examples

lost_dog([1, 1, 1, 1, 1, 1],  [1, 1, 1, 1, 1, 1],  [1, 1, 1, 1, 1, 1],  [1, 1, 1, 1, 1, 1])
➞ "Dog not found!"

lost_dog([1, 1, 1, 1, 1, 1],  [0, 1, 1, 1, 1, 1],  [1, 0, 1, 1, 1, 1],  [1, 1, 1, 1, 1, 1])
➞ {"Dog1": "House (2) and Room (1)", "Dog2": "House (3) and Room (2)"}

lost_dog([1, 1, 1, 1, 1, 0],  [0, 1, 1, 1, 1, 1],  [1, 0, 1, 1, 1, 1],  [1, 1, 0, 1, 1, 1])
➞ {"Dog1": "House (1) and Room (6)", "Dog2": "House (2) and Room (1)", "Dog3": "House (3) and Room (2)", "Dog4": "House (4) and Room (3)"}

Notes

Check the Resources if you're stuck.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	a1 := [][]int{
		{1, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 1},
		{1, 0, 1, 1, 1, 1},
		{1, 1, 0, 1, 1, 1},
	}
	m1 := map[string]string{
		"Dog1": "House (1) and Room (6)",
		"Dog2": "House (2) and Room (1)",
		"Dog3": "House (3) and Room (2)",
		"Dog4": "House (4) and Room (3)",
	}

	a2 := [][]int{
		{1, 1, 0, 1, 1, 1},
		{1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1, 1},
	}
	m2 := map[string]string{
		"Dog1": "House (1) and Room (3)",
		"Dog2": "House (4) and Room (3)",
	}

	a3 := [][]int{
		{1, 1, 0, 1, 1, 1},
		{1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1},
	}
	m3 := map[string]string{
		"Dog1": "House (1) and Room (3)",
	}

	a4 := [][]int{
		{1, 1, 1, 1, 1, 1},
		{0, 1, 1, 1, 1, 1},
		{0, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1},
	}
	m4 := map[string]string{
		"Dog1": "House (2) and Room (1)",
		"Dog2": "House (3) and Room (1)",
	}

	a5 := [][]int{
		{1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1},
	}
	m5 := "Dog not found!"

	a6 := [][]int{
		{1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 1},
	}
	m6 := map[string]string{
		"Dog1": "House (4) and Room (4)",
	}

	test(m1, a1...)
	test(m2, a2...)
	test(m3, a3...)
	test(m4, a4...)
	test(m5, a5...)
	test(m6, a6...)
}

func test(m interface{}, a ...[]int) {
	assert(reflect.DeepEqual(find(a...), m))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func find(a ...[]int) interface{} {
	m := make(map[string]string)
	n := 1
loop:
	for i := range a {
		for j := range a[i] {
			if a[i][j] == 0 {
				k := fmt.Sprintf("Dog%d", n)
				v := fmt.Sprintf("House (%d) and Room (%d)", i+1, j+1)
				m[k], n = v, n+1
				continue loop
			}
		}
	}
	if len(m) == 0 {
		return "Dog not found!"
	}
	return m
}
