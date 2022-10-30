/*

I've been working on this iOS app recently and I encountered a (rather easily solved) problem: How do I determine if my string is comprised only of emojis?

Well, that's your job today!
Input

A string. If the presence of unicode characters is problematic for you then you may use a different reasonable format. Please state what you do if you do something different from a regular string for taking input.
Output

Print or return a truthy value if the input string contains only emojis, and a falsey value if it contains any characters other than emojis.
Wait a sec... what's an emoji? 😅

An emoji is a character that falls in these ranges:

0x1F600...0x1F64F  // Emoticons
0x1F300...0x1F5FF  // Misc Symbols and Pictographs
0x1F680...0x1F6FF  // Transport and Map
0x2600...0x26FF    // Misc symbols
0x2700...0x27BF    // Dingbats
0xFE00...0xFE0F    // Variation Selectors

(I think)
This is 🔹code-golf🔹, so shortest code in bytes wins❕
Test cases

"Is it an emoji? 🤔" -> False
"🔹code-golf🔹" -> False
"😮 😥 😨 😩 😪" -> False
"I have no fancy emojis :(" -> False

"😎" -> True
"😊😘" -> True

For you poor souls who cannot see emojis, here is an image of the test cases.

*/

package main

import (
	"sort"
)

func main() {
	assert(isemoji("Is it an emoji? 🤔") == false)
	assert(isemoji("🔹code-golf🔹") == false)
	assert(isemoji("😮 😥 😨 😩 😪") == false)
	assert(isemoji("I have no fancy emojis :(") == false)
	assert(isemoji("😎") == true)
	assert(isemoji("😊😘") == true)
	assert(isemoji(string([]rune{0x2600, 0x2601, 0x2602})) == true)
	assert(isemoji(string([]rune{0x2599})) == false)
	assert(isemoji(string([]rune{0x1f64f, 0x1f64e})) == true)
	assert(isemoji(string([]rune{0x1f64f + 1, 0x1f64e + 2})) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func isemoji(s string) bool {
	ranges := [][2]rune{
		{0x2600, 0x26FF},
		{0x2700, 0x27BF},
		{0xFE00, 0xFE0F},
		{0x1F300, 0x1F5FF},
		{0x1F600, 0x1F64F},
		{0x1F680, 0x1F6FF},
	}

	n := len(ranges)
	for _, r := range s {
		i := sort.Search(n, func(i int) bool { return r < ranges[i][0] })
		if i--; i < 0 || i >= n || !(ranges[i][0] <= r && r <= ranges[i][1]) {
			return false
		}
	}
	return true
}
