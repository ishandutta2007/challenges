/*

Challenge

Imagine a necklace with lettered beads that can slide along the string. Here's an example image.
In this example, you could take the N off NICOLE and slide it around to the other end to make ICOLEN.
Do it again to get COLENI, and so on. For the purpose of today's challenge, we'll say that the strings "nicole", "icolen", and "coleni" describe the same necklace.

Generally, two strings describe the same necklace if you can remove some number of letters from the beginning of one, attach them to the end in their original ordering, and get the other string.
Reordering the letters in some other way does not, in general, produce a string that describes the same necklace.

Write a function that returns whether two strings describe the same necklace.
Examples

same_necklace("nicole", "icolen") => true
same_necklace("nicole", "lenico") => true
same_necklace("nicole", "coneli") => false
same_necklace("aabaaaaabaab", "aabaabaabaaa") => true
same_necklace("abc", "cba") => false
same_necklace("xxyyy", "xxxyy") => false
same_necklace("xyxxz", "xxyxz") => false
same_necklace("x", "x") => true
same_necklace("x", "xx") => false
same_necklace("x", "") => false
same_necklace("", "") => true

Optional Bonus 1

If you have a string of N letters and you move each letter one at a time from the start to the end, you'll eventually get back to the string you started with, after N steps. Sometimes, you'll see the same string you started with before N steps. For instance, if you start with "abcabcabc", you'll see the same string ("abcabcabc") 3 times over the course of moving a letter 9 times.

Write a function that returns the number of times you encounter the same starting string if you move each letter in the string from the start to the end, one at a time.

repeats("abc") => 1
repeats("abcabcabc") => 3
repeats("abcabcabcx") => 1
repeats("aaaaaa") => 6
repeats("a") => 1
repeats("") => 1

Optional Bonus 2

There is exactly one set of four words in the enable1 word list that all describe the same necklace. Find the four words.

*/

package main

import "strings"

func main() {
	assert(rotated("nicole", "icolen") == true)
	assert(rotated("nicole", "lenico") == true)
	assert(rotated("nicole", "coneli") == false)
	assert(rotated("aabaaaaabaab", "aabaabaabaaa") == true)
	assert(rotated("abc", "cba") == false)
	assert(rotated("xxyyy", "xxxyy") == false)
	assert(rotated("xyxxz", "xxyxz") == false)
	assert(rotated("x", "x") == true)
	assert(rotated("x", "xx") == false)
	assert(rotated("x", "") == false)
	assert(rotated("", "") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func rotated(s, t string) bool {
	if len(s) != len(t) {
		return false
	}
	return strings.Index(s+s, t) >= 0
}
