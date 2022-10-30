/*

Create a program which prints out a table with the month's calendar in it, when the month and year is given as input.

Extra points for highlighting the current day and providing links to next and previous months.

Happy coding :)

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	calendar(time.January, 2000)
	calendar(time.March, 2001)
}

func calendar(m time.Month, y int) {
	s := fmt.Sprintf("%v %d", m, y)
	fmt.Printf("%*s\n\n", 7*2, s)

	tab := []string{"S", "M", "Tu", "W", "Th", "F", "S"}
	for _, s := range tab {
		fmt.Printf("%2s ", s)
	}
	fmt.Println()

	t := time.Date(y, m, 1, 0, 0, 0, 0, time.UTC)
	w := t.Weekday()
	for i := 0; i < int(w); i++ {
		fmt.Printf("%3s", " ")
	}

	for d := 1; d <= 31; d++ {
		fmt.Printf("%2d ", d)
		if w++; int(w) >= len(tab) {
			fmt.Println()
			w = 0
		}

		t = t.AddDate(0, 0, 1)
		if t.Month() != m {
			break
		}
	}
	fmt.Printf("\n\n")
}
