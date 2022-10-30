/*

You are attending the International Construction by Preschoolers Contest.
Unfortunately, you are too old to participate, but you still enjoy watching the competition.

In between rounds, you are walking around the contest area when you see a toddler, one of the contestants, playing with her blocks.
Annoyed that she is having all the fun, you decide to challenge her to a game.

You set up two stacks of blocks of a certain height.
Then, you and the toddler take turns removing some number of blocks from the stack which contains the largest number of blocks (if both stacks have the same number of blocks, the current player can choose either stack to remove blocks from).
The number of blocks removed must be a positive multiple of the number of blocks in the smaller stack. For instance, if there is a stack with 5 blocks, and one with 23 blocks, then the current player can remove 5, 10, 15 or 20 blocks from the stack of 23 blocks.
The player who empties one of the stacks wins the game.

You have graciously decided to take the first move, but then a worry strikes you – might this devious preschooler still be able to beat you?

Input

One line with two integers N and M, satisfying 1≤N,M≤1018, the initial sizes of the two stacks of blocks.

Output

Output a single line containing a single word: the word “win” if you are guaranteed to win if you play correctly, and the word “lose” if your opponent can force you to lose.

*/

package main

func main() {
	assert(outcome(3, 2) == "lose")
	assert(outcome(3, 3) == "win")
	assert(outcome(5, 2) == "win")
	assert(outcome(5, 3) == "win")
	assert(outcome(13, 10) == "lose")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func outcome(a, b int) string {
	if a <= 0 || b <= 0 {
		return "invalid"
	}

	w := true
	for ; a%b != 0 && a < b*2; w = !w {
		if a -= b; a-b != 0 {
			a, b = b, a
		}
	}

	if w {
		return "win"
	}
	return "lose"
}
