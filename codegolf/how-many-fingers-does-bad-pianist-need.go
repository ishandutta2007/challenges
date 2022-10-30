/*

Challenge
Premise

Bob is a novice pianist who can only play sequences of single notes. In addition, he does quite an interesting thing: for every note after the first, if it's higher than the previous note was, he uses the finger directly to the right of the previous finger used; if lower, to the left; if the same pitch, well, the same finger.

Let's take Auld Lang Syne as an example, and arbitrarily suppose, only for the sake of this example, that Bob uses the very right side of his right hand.

Pitch: Should < auld = ac- = quain- < tance > be > for- < got
Digit: mid      ring   ring  ring     pinky   ring mid    ring

Alice wants to convince him of the stupidity of his playing...
Task

Input: a sequence of n
MIDI note numbers (which are integers between 0 and 127 inclusive), where 2≤n≤10000.

Output: the number of fingers required to finish the melody with the playing style outlined in 'Premise'.

Please note that the answer may be more than 5.

No consideration of the starting finger is needed. Assume that the choice is optimal for playable melodies and has nothing (else) to do with the number of fingers required.
Example 1

Input: 0 0 0 0

Output: 1
Example 2

Input: 43 48 48 48 52 50 48 50

Output: 3
Example 3

Input: 86 88 84 81 83 79 74 76 72 69 71 67 62 64 60 57 59 57 56 55

Output: 9
Example 4

Input: 82 79 78 76 78 76 74 73 70 67 66 64 66 64 62 61

Output: 12
Remarks

    This is code-golf, so fewest bytes wins.
    Standard rules, I/O rules and loophole rules apply.
    If possible, link an online demo of your code.
    Please explain your code.


*/

package main

func main() {
	assert(fingers([]int{0, 0, 0, 0}) == 1)
	assert(fingers([]int{43, 48, 48, 48, 52, 50, 48, 50}) == 3)
	assert(fingers([]int{86, 88, 84, 81, 83, 79, 74, 76, 72, 69, 71, 67, 62, 64, 60, 57, 59, 57, 56, 55}) == 9)
	assert(fingers([]int{82, 79, 78, 76, 78, 76, 74, 73, 70, 67, 66, 64, 66, 64, 62, 61}) == 12)
	assert(fingers([]int{2}) == 1)
	assert(fingers([]int{}) == 0)
}

func sign(x, y int) int {
	if y > x {
		return 1
	}
	if y < x {
		return -1
	}
	return 0
}

func fingers(p []int) int {
	if len(p) == 0 {
		return 0
	}

	n := 1
	m := map[int]struct{}{n: struct{}{}}
	for i := 0; i < len(p)-1; i++ {
		n += sign(p[i], p[i+1])
		m[n] = struct{}{}
	}
	return len(m)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
