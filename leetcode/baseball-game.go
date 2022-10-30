/*

You're now a baseball game point recorder.

Given a list of strings, each string can be one of the 4 following types:

    Integer (one round's score): Directly represents the number of points you get in this round.
    "+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
    "D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
    "C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.

Each round's operation is permanent and could have an impact on the round before and the round after.

You need to return the sum of the points you could get in all the rounds.

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	fmt.Println(rounds([]string{"5", "2", "C", "D", "+"}))
	fmt.Println(rounds([]string{"5", "-2", "4", "C", "D", "9", "+", "+"}))
}

func rounds(s []string) int {
	var stk []int
	for _, op := range s {
		switch op {
		case "+":
			u, v := 0, 0
			if l := len(stk); l >= 2 {
				u, v = stk[l-1], stk[l-2]
			}
			stk = append(stk, u+v)

		case "D":
			v := 0
			if l := len(stk); l > 0 {
				v = stk[l-1]
			}
			stk = append(stk, 2*v)

		case "C":
			if l := len(stk); l > 0 {
				stk = stk[:l-1]
			}

		default:
			v, err := strconv.Atoi(op)
			if err == nil {
				stk = append(stk, v)
			}
		}
	}

	sum := 0
	for len(stk) > 0 {
		l := len(stk)
		sum += stk[l-1]
		stk = stk[:l-1]
	}
	return sum
}
