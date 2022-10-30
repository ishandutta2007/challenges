/*

Write the shortest program to forecast the weather for the next 7 days

The input (from stdin) is the weekday and the season

The output (to stdout) is seven lines weekday and the temperature in centigrade

The weekdays begin on the input weekday

The temperatures are random numbers with the range depending on the season

Spring 10 - 30 degrees
Summer 20 - 40 degrees
Autumn  5 - 25 degrees  (Fall is a synonym for autumn)
Winter -5 - 15 degrees

Sample Input

Thursday Winter

Sample Output

Thursday -1
Friday 3
Saturday 8
Sunday 7
Monday 10
Tuesday 10
Wednesday -1

Your program must not have identical output every time it is run with the same input

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	days := []string{
		"Monday", "Tuesday", "Wednesday", "Thursday",
		"Friday", "Saturday", "Sunday",
	}
	seasons := []string{"Spring", "Summer", "Autumn", "Winter"}

	rand.Seed(time.Now().UnixNano())
	for _, s := range seasons {
		fmt.Println(s)
		for _, d := range days {
			fmt.Println(forecast(d, s))
		}
		fmt.Println()
	}
}

func forecast(d, s string) string {
	m := map[string][2]int{
		"Spring": [2]int{10, 30},
		"Summer": [2]int{20, 40},
		"Autumn": [2]int{5, 25},
		"Winter": [2]int{-5, 15},
	}
	r := m[s]
	t := rand.Intn(r[1]-r[0]+1) + r[0]
	return fmt.Sprintf("%v %v", d, t)
}
