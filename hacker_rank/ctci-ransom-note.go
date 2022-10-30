/*
Check out the resources on the page's right side to learn more about hashing. The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book Cracking the Coding Interview.

Harold is a kidnapper who wrote a ransom note, but now he is worried it will be traced back to him through his handwriting.
He found a magazine and wants to know if he can cut out whole words from it and use them to create an untraceable replica of his ransom note.
The words in his note are case-sensitive and he must use only whole words available in the magazine. He cannot use substrings or concatenation to create the words he needs.

Given the words in the magazine and the words in the ransom note, print Yes if he can replicate his ransom note exactly using whole words from the magazine; otherwise, print No.

For example, the note is "Attack at dawn". The magazine contains only "attack at dawn". The magazine has all the right words, but there's a case mismatch. The answer is No.
*/
package main

import (
	"fmt"
	"strings"
)

func main() {
	tests := [][2]string{
		{"Attack at dawn", "attack at dawn"},
		{"give me one grand today night", "give one grand today"},
		{"two times three is not four", "two times two is four"},
		{"ive got a lovely bunch of coconuts", "ive got some coconuts"},
	}
	for _, t := range tests {
		fmt.Println(check(t[0], t[1]))
	}
}

func check(magazine, note string) string {
	p := strings.Split(magazine, " ")
	m := make(map[string]int)
	for _, t := range p {
		m[t]++
	}

	q := strings.Split(note, " ")
	for _, t := range q {
		if n := m[t]; n <= 0 {
			return "No"
		}
		m[t]--
	}

	return "Yes"
}
