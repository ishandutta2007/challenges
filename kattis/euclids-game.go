/*

Two players, Stan and Ollie, play, starting with two natural numbers. Stan, the first player, subtracts any positive multiple of the lesser of the two numbers from the greater of the two numbers, provided that the resulting number must be nonnegative.
Then Ollie, the second player, does the same with the two resulting numbers, then Stan, etc., alternately, until one player is able to subtract a multiple of the lesser number from the greater to reach 0, and thereby wins.
For example, the players may start with (25,7) and the game might progress as
         25 7
         11 7
          4 7
          4 3
          1 3
          1 0
and Stan wins.

Input

The input consists of a number of lines. Each line contains two positive integers less than 2^31 giving the starting two numbers of the game.
Stan always starts. The last line of input contains two zeroes and should not be processed.

Output

For each line of input, output one line saying either Stan wins or Ollie wins assuming that both of them play perfectly.

*/

package main

func main() {
	assert(winner(25, 7) == "Stan")
	assert(winner(34, 12) == "Stan")
	assert(winner(15, 24) == "Ollie")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func winner(a, b int) string {
	switch {
	case a > b:
		return winner(b, a)
	case b%a == 0:
		return "Stan"
	case b/a == 1:
		s := winner(a, b-a)
		if s == "Stan" {
			return "Ollie"
		}
	}
	return "Stan"
}
