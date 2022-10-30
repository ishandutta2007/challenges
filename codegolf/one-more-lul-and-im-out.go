/*

Challenge description
On some channels on a popular streaming site twitch.tv a common message people tend to spam in chats to bait people into spamming "LUL" is

One more LUL and I'm out
LUL is a popular emote used to express that something funny happened on stream.

Soon dank memes showed their potential and a parody of the copy-pasta ensued:

One more "One more LUL and I'm out" and I'm out
Which is the same message nested in itself. Given a non-negative integer N, output the LUL-pasta nested N times in itself following the pattern below.

Standard code-golf rules apply, the shortest code in bytes wins.

Sample input / output
0: One more LUL and I'm out
1: One more "One more LUL and I'm out" and I'm out
2: One more "One more "One more LUL and I'm out" and I'm out" and I'm out
...
7: One more "One more "One more "One more "One more "One more "One more "One more LUL and I'm out" and I'm out" and I'm out" and I'm out" and I'm out" and I'm out" and I'm out" and I'm out

Notes
Leading/trailing newlines are allowed
Capitalization must be preserved
Your code may be a full program or a function
Instead of printing, you may return a string or its equivalent in your language of choice
You may index from 1 instead of 0

*/

package main

import "fmt"

func main() {
	assert(lul(0) == `One more LUL and I'm out`)
	assert(lul(1) == `One more "One more LUL and I'm out" and I'm out`)
	assert(lul(2) == `One more "One more "One more LUL and I'm out" and I'm out" and I'm out`)
	assert(lul(7) == `One more "One more "One more "One more "One more "One more "One more "One more LUL and I'm out" and I'm out" and I'm out" and I'm out" and I'm out" and I'm out" and I'm out" and I'm out`)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func lul(n int) string {
	if n < 0 {
		return ""
	}

	s := "LUL"
	for i := 0; i <= n; i++ {
		if i > 0 {
			s = `"` + s + `"`
		}
		s = fmt.Sprintf("One more %s and I'm out", s)
	}
	return s
}
