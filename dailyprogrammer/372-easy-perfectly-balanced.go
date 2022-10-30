/*

Given a string containing only the characters x and y, find whether there are the same number of xs and ys.

balanced("xxxyyy") => true
balanced("yyyxxx") => true
balanced("xxxyyyy") => false
balanced("yyxyxxyxxyyyyxxxyxyx") => true
balanced("xyxxxxyyyxyxxyxxyy") => false
balanced("") => true
balanced("x") => false

Optional bonus

Given a string containing only lowercase letters, find whether every letter that appears in the string appears the same number of times. Don't forget to handle the empty string ("") correctly!

balanced_bonus("xxxyyyzzz") => true
balanced_bonus("abccbaabccba") => true
balanced_bonus("xxxyyyzzzz") => false
balanced_bonus("abcdefghijklmnopqrstuvwxyz") => true
balanced_bonus("pqq") => false
balanced_bonus("fdedfdeffeddefeeeefddf") => false
balanced_bonus("www") => true
balanced_bonus("x") => true
balanced_bonus("") => true

Note that balanced_bonus behaves differently than balanced for a few inputs, e.g. "x".

*/

package main

import "fmt"

func main() {
	fmt.Println(balanced("xxxyyy"))
	fmt.Println(balanced("yyyxxx"))
	fmt.Println(balanced("xxxyyyy"))
	fmt.Println(balanced("yyxyxxyxxyyyyxxxyxyx"))
	fmt.Println(balanced("xyxxxxyyyxyxxyxxyy"))
	fmt.Println(balanced(""))
	fmt.Println(balanced("x"))
	fmt.Println()

	fmt.Println(balancedbonus("xxxyyyzzz"))
	fmt.Println(balancedbonus("abccbaabccba"))
	fmt.Println(balancedbonus("xxxyyyzzzz"))
	fmt.Println(balancedbonus("abcdefghijklmnopqrstuvwxyz"))
	fmt.Println(balancedbonus("pqq"))
	fmt.Println(balancedbonus("fdedfdeffeddefeeeefddf"))
	fmt.Println(balancedbonus("www"))
	fmt.Println(balancedbonus("x"))
	fmt.Println(balancedbonus(""))
}

func balanced(s string) bool {
	c := 0
	for _, r := range s {
		switch r {
		case 'x':
			c++
		case 'y':
			c--
		default:
			return false
		}
	}
	return c == 0
}

func balancedbonus(s string) bool {
	m := make(map[rune]int)
	for _, r := range s {
		m[r]++
	}

	c := -1
	for _, v := range m {
		switch {
		case c == -1:
			c = v
		case c != v:
			return false
		}
	}

	return true
}
