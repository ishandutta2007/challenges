/*

Given an object of people and their ages, return how old the people would be after n years have passed. Use the absolute value of n.

Notes

    Assume that everyone is immortal (it would be a bit grim if I told you to remove names once they reached 75).
    n should be a positive number because last time I checked, people don't tend to age backwards. Therefore, use the absolute value of n.

*/

package main

import "fmt"

func main() {
	fmt.Println(agethem(map[string]int{
		"Joel":     32,
		"Fred":     44,
		"Reginald": 65,
		"Susan":    33,
		"Julian":   13,
	}, 1))

	fmt.Println(agethem(map[string]int{
		"Baby":     2,
		"Child":    8,
		"Teenager": 15,
		"Adult":    25,
		"Elderly":  71,
	}, 19))

	fmt.Println(agethem(map[string]int{
		"Genie": 1000,
		"Joe":   40,
	}, 5))

	fmt.Println(agethem(map[string]int{
		"Adam": 0,
		"Eve":  0,
	}, 800))

	fmt.Println(agethem(map[string]int{
		"Ambitious Old Scientist":            87,
		"Ambitious Scientist":                42,
		"Slightly Concerned Young Scientist": 23,
	}, -35))

	fmt.Println(agethem(map[string]int{
		"USA":    243,
		"Person": 27,
	}, 0))
}

func agethem(m map[string]int, y int) map[string]int {
	for k := range m {
		m[k] += abs(y)
	}
	return m
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
