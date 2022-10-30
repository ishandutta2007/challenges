/*

Introduction
Emoji use a particular alphabet for their national flags, which allows one to put two symbols together to create the appropriate flag.

🇦🇧🇨🇩🇪🇫🇬🇭🇮🇯🇰🇱🇲🇳🇴🇵🇶🇷🇸🇹🇺🇻🇼🇽🇾🇿

Your challenge, is to transform any uppercase letter into the appropriate Flag Identifier.

This may be much harder for languages that do not innately handle Unicode. Each symbol is exactly 4 UTF-8 Bytes.

The Task
Given an input as one or more letters, output the same, with all letters replaced with their flag combinations.

Winner is the answer with the least Bytes, giving the tiebreaker to first answer posted.

Input / Output
Input and Output may use any standard method. Letters in the input may optionally only support one case, Upper or Lower. Please specify in your answer what case your solution supports.

Your output may, intentionally or otherwise, output flag emoji instead of letter pairs.

Test Cases
FR 🇫🇷

Hello, World! 🇭🇪🇱🇱🇴, 🇼🇴🇷🇱🇩!

Rules
Standard Loopholes Apply
Standard Input Output allowed
This is code-golf, however, All the Emoji Letters as provided above can be counted for a single byte each, instead of four. Least Bytes wins!

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	fmt.Println(translate("FR"))
	fmt.Println(translate("Hello, World!"))
}

func translate(s string) string {
	const emoji = `🇦🇧🇨🇩🇪🇫🇬🇭🇮🇯🇰🇱🇲🇳🇴🇵🇶🇷🇸🇹🇺🇻🇼🇽🇾🇿`

	w := new(bytes.Buffer)
	c := []rune(emoji)
	for _, r := range s {
		if 'a' <= r && r <= 'z' {
			w.WriteRune(c[r-'a'])
		} else if 'A' <= r && r <= 'Z' {
			w.WriteRune(c[r-'A'])
		} else {
			w.WriteRune(r)
		}
	}
	return w.String()
}
