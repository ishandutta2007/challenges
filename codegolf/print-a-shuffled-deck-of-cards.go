/*

Input

None
Output

52 cards. No duplicates. Cards are represented as their unicode characters, e.g. 🂹.

The Unicode codepoints follow the following format:

    The first three digits are 1F0.
    The next digit is A, B, C, or D for spades, hearts, diamonds, and clubs respectively.
    The next digit is 1 through C and E for the various numbers/face cards. 1 is ace, 2-A are the number cards, and B, D, and E are the jack, queen, and king respectively. (C is the knight, which isn't in most decks.)

Example output:

🂶🃁🃛🃎🂧🂵🃗🂦🂽🂹🂣🃊🃚🂲🂡🂥🂷🃄🃃🃞🂺🂭🃑🃙🂪🃖🂳🃘🃒🂻🃆🂮🃍🂱🂴🃋🂸🃈🃅🃂🂨🃓🃉🂾🃇🂩🂢🂫🃔🃕🂤🃝

Rules:

    This is code-golf. Shortest answer wins.
    Forbidden loopholes are forbidden.
    Your deck must be actually randomized. If run 20 times, 20 random (and most likely unique) outputs must be generated.

Note

If you only see boxes, install the DejaVu fonts.

*/

package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	fmt.Println(shuffle())
}

func shuffle() string {
	tab := "🂶🃁🃛🃎🂧🂵🃗🂦🂽🂹🂣🃊🃚🂲🂡🂥🂷🃄🃃🃞🂺🂭🃑🃙🂪🃖🂳🃘🃒🂻🃆🂮🃍🂱🂴🃋🂸🃈🃅🃂🂨🃓🃉🂾🃇🂩🂢🂫🃔🃕🂤🃝"

	var c []rune
	for _, r := range tab {
		c = append(c, r)
	}

	p := rand.Perm(len(c))
	sort.Slice(c, func(i, j int) bool {
		return c[p[i]] < c[p[j]]
	})

	return string(c)
}
