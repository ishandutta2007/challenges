/*

This is a challenge in which two people, 1 and 2, are running for office. People deterministically vote in certain ways in the world of 1 and 2, which can allow for the candidates to figure out the results before the election.

NOTE: this is not meant to refer to any outside elections or other political events.

Two people are running for office. We'll call these people 1 and 2. Because they both want to know if they will win the election, they decide to use their knowledge of people and some code to figure out what the result will be. Due to the want to minimize government spending, the code needs to be a short as possible.

Your task: Given a string of people based on how they are voting, output who wins the election.

There are five kinds of people in the fun and exciting world of 1 and 2:

A: people who will definitely vote for 1.
B: people who will definitely vote for 2.
X: people who will vote for whoever the person to their left will vote for. If there is no person to their left, then they vote for whoever the person at their right will vote for. If it is not clear who the person to their right is voting for, then they do not vote.
Y: people will vote the opposite of the person to their left. If there is no person to their left, then they vote opposite of whoever is at their right. If it is not clear who the person to their right is voting for, then they do not vote.
N: people who do not vote.
This is evaluated from left to right.

Example:

Whoever is being "evaluated" is in lowercase, for clarity.

Input: `XXAYAN`
        xX      Votes for whoever their friend is voting for. Their friend has not decided yet, so it is unclear, so they do not vote.
        Xx      Person to left is voting "none" so votes "none."
          a     Votes for 1
          Ay    Since person on left is voting for 1, votes for 2.
            a   Votes for 1
             n  Does not vote
Final poll:

2 people voted for 1

1 people voted for 2

3 people did not vote

1 has the most votes, so 1 wins!

Test cases:

You may use other characters or values as input and output, as long as they are distinct. (For example: numbers instead of letters, different letters, lowercase letters, truthy/falsy or positive/negative (for output), etc.)

Input -> Output

"AAAA" -> 1
"BBBB" -> 2
"BBAXY" -> 2
"BAXYBNXBAYXBN" -> 2
"XXAYAN" -> 1
"AAAABXXXX" -> 2
"AXNXXXXAYB" -> 1
"NANNY" -> 1
"XA" -> 1
"YAB" -> 2
"XY" -> anything (do not need to handle test cases with no victor)
"AB" -> anything (do not need to handle test cases with no victor)

*/

package main

import (
	"bytes"
)

func main() {
	assert(victor("AAAA") == 1)
	assert(victor("BBBB") == 2)
	assert(victor("BBAXY") == 2)
	assert(victor("BAXYBNXBAYXBN") == 2)
	assert(victor("XXAYAN") == 1)
	assert(victor("AAAABXXXX") == 2)
	assert(victor("AXNXXXXAYB") == 1)
	assert(victor("NANNY") == 1)
	assert(victor("XA") == 1)
	assert(victor("YAB") == 2)
	assert(victor("XY") == 0)
	assert(victor("AB") == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func victor(s string) int {
	a, b := count(meld(s))
	if a > b {
		return 1
	}
	if a < b {
		return 2
	}
	return 0
}

func count(s string) (int, int) {
	a, b := 0, 0
	for _, r := range s {
		switch r {
		case 'A':
			a++
		case 'B':
			b++
		}
	}
	return a, b
}

func meld(s string) string {
	w := new(bytes.Buffer)
	n := len(s)
	for i := 0; i < n; i++ {
		switch s[i] {
		case 'A', 'B', 'N':
			w.WriteByte(s[i])

		case 'X', 'Y':
			t := w.String()
			m := len(t)

			c := byte('N')
			if m > 0 {
				c = t[m-1]
			} else if i+1 < n && (s[i+1] == 'A' || s[i+1] == 'B') {
				c = s[i+1]
			}

			if s[i] == 'Y' {
				if c == 'A' {
					c = 'B'
				} else if c == 'B' {
					c = 'A'
				}
			}

			w.WriteByte(c)
		}
	}
	return w.String()
}
