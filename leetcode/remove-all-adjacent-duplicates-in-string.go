/*

Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

Note:
1 <= S.length <= 20000
S consists only of English lowercase letters.

Hint 1
Use a stack to process everything greedily.

*/

package main

import "fmt"

func main() {
	fmt.Println(adjrmdup("abbaca"))
	fmt.Println(adjrmdup("abbacaaaaaaaaaaaxyz"))
	fmt.Println(adjrmdup("bb"))
}

func adjrmdup(s string) string {
	var p []rune
	for _, r := range s {
		if len(p) > 0 && p[len(p)-1] == r {
			p = p[:len(p)-1]
		} else {
			p = append(p, r)
		}
	}
	return string(p)
}
