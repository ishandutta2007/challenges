/*

Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.

Follow up:
Try to solve it in O(n log k) time and O(n) extra space.

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(topkfreq([]string{"i", "love", "leetcode", "i", "love", "coding"}, 2))
	fmt.Println(topkfreq([]string{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"}, 4))
	fmt.Println(topkfreq([]string{""}, 0))
}

func topkfreq(w []string, k int) []string {
	if k < 0 {
		return nil
	}

	f := make(map[string]int)
	for _, w := range w {
		f[w]++
	}

	var s []string
	for t, _ := range f {
		s = append(s, t)
	}
	sort.Slice(s, func(i, j int) bool {
		return f[s[i]] > f[s[j]]
	})

	return s[:min(len(s), k)]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
