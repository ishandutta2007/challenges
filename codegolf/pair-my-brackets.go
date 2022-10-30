/*

Given a string consisting of ()[]{}, print the paired brackets in the same order as they appear in the string.
Any opening bracket ([{ can be paired with any closing bracket )]}.

For example:

({()[}]]
returns:
(], {], (), [}
Rules
A string consisting of ()[]{} should be received as the input
The bracket-pairs should be returned as a list, or separated by a distinct character (or nothing), etc.
The bracket-pairs should be in the same order as the starting brackets in the string
The brackets will be balanced, i.e. the number of opening brackets and the number of the closing brackets will be the same
Default Loopholes apply
This is code-golf, so the shortest code wins!
Examples
[In]: ()
[Out]: ()

[In]: (}{]
[Out]: (}, {]

[In]: ([{}])
[Out]: (), [], {}

[In]: {]([(}]{)}
[Out]: {], (}, [], (}, {)

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test("()", []string{"()"})
	test("(}{]", []string{"(}", "{]"})
	test("([{}])", []string{"()", "[]", "{}"})
	test("{]([(}]{)}", []string{"{]", "(}", "[]", "(}", "{)"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []string) {
	p, err := pair(s)
	fmt.Println(p)
	assert(err == nil)
	assert(reflect.DeepEqual(p, r))
}

func pair(s string) ([]string, error) {
	var (
		p []string
		l []int
	)
	for i := 0; i < len(s); i++ {
		switch s[i] {
		case '(', '{', '[':
			p = append(p, string(s[i]))
			l = append(l, len(p)-1)
		case ')', '}', ']':
			n := len(l)
			if n == 0 {
				return nil, fmt.Errorf("unbalanced brackets")
			}
			p[l[n-1]] += string(s[i])
			l = l[:n-1]
		}
	}
	return p, nil
}
