/*

For strings S and T, we say "T divides S" if and only if S = T + ... + T  (T concatenated with itself 1 or more times)

Return the largest string X such that X divides str1 and X divides str2.

Note:
    1 <= str1.length <= 1000
    1 <= str2.length <= 1000
    str1[i] and str2[i] are English uppercase letters.

*/

package main

import "fmt"

func main() {
	fmt.Println(gcds("ABCABC", "ABC"))
	fmt.Println(gcds("ABABAB", "ABAB"))
	fmt.Println(gcds("LEET", "CODE"))
	fmt.Println(gcds("x", ""))
	fmt.Println(gcds("aaa", "aaaaa"))
	fmt.Println(gcds("aaaaa", "aaaaa"))
	fmt.Println(gcds("aaaaa", "aaaaaaaaaa"))
	fmt.Println(gcds("xxxxxx", "xx"))
}

func gcds(s, t string) string {
	for {
		if s+t != t+s || s == "" || t == "" {
			return ""
		}
		if s == t {
			return s
		}
		if len(s) > len(t) {
			s = s[len(t):]
		}
		if len(t) > len(s) {
			t = t[len(s):]
		}
	}
	return ""
}
