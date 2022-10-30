/*

There is a collection of input strings and a collection of query strings. For each query string, determine how many times it occurs in the list of input strings.

*/
package main

import "fmt"

func main() {
	s := []string{"ab", "ab", "abc"}
	q := []string{"ab", "abc", "bc"}
	fmt.Println(query(s, q))

	s = []string{"aba", "baba", "aba", "xzxb"}
	q = []string{"aba", "xzxb", "ab"}
	fmt.Println(query(s, q))

	s = []string{"def", "de", "fgh"}
	q = []string{"de", "lmn", "fgh"}
	fmt.Println(query(s, q))

	s = []string{"abcde", "sdaklfj", "asdjf", "na", "basdn", "sdaklfj", "asdjf", "na", "asdjf", "na", "basdn", "sdaklfj", "asdjf"}
	q = []string{"abcde", "sdaklfj", "asdjf", "na", "basdn"}
	fmt.Println(query(s, q))
}

func query(s, q []string) []int {
	m := make(map[string]int)
	for i := range s {
		m[s[i]]++
	}
	p := make([]int, len(q))
	for i := range q {
		p[i] = m[q[i]]
	}
	return p
}
