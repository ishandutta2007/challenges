/*

Sardar Singh has many men fighting for him, and he would like to calculate the power of each of them to better plan for his fight against Ramadhir.

The power of a string S of lowercase English alphabets is defined to be

∑i=1|S|i⋅ord(Si)

where ord(Si) is the position of Si in the alphabet, i.e, ord(′a′)=1,ord(′b′)=2,…,ord(′z′)=26.

Each of Sardar Singh's men has a name consisting of lowercase English alphabets. The power of a man is defined to be the maximum power over all possible rearrangements of this string.

Find the power of each of Sardar Singh's men.

Input Format

The first line of input contains an integer T, denoting the total number of Sardar Singh's men.
Each of the next T lines contains a single string Si, the name of Sardar Singh's i-th man.

Output Format

Output T lines, each containing a single integer. The i-th of these lines should have the power of the i-th of Sardar Singh's men.

Constraints

1≤T≤60
1≤|Si|≤100
Si consists of lowercase english alphabets only.

*/

package main

import (
	"sort"
)

func main() {
	assert(power("faizal") == 273)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func power(s string) int {
	r := []rune(s)
	sort.Slice(r, func(i, j int) bool {
		return r[i] < r[j]
	})

	p := 0
	for i := range r {
		if 'a' <= r[i] && r[i] <= 'z' {
			p += int(r[i]-'a'+1) * (i + 1)
		}
	}
	return p
}
