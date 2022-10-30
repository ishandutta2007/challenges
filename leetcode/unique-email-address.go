/*

Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.  For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails?

Note:

    1 <= emails[i].length <= 100
    1 <= emails.length <= 100
    Each emails[i] contains exactly one '@' character.
    All local and domain names are non-empty.
    Local names do not start with a '+' character.

*/

package main

import (
	"fmt"
	"strings"
	"unicode"
)

func main() {
	fmt.Println(uniq([]string{
		"alice@leetcode.com",
		"alice.z@leetcode.com",
		"alicez@leetcode.com",
		"m.y+name@email.com",
		"my@email.com",
	}))
	fmt.Println(uniq([]string{
		"test.email+alex@leetcode.com",
		"test.e.mail+bob.cathy@leetcode.com",
		"testemail+david@lee.tcode.com",
	}))
}

func uniq(s []string) int {
	m := make(map[string]bool)
	u := 0
	for _, s := range s {
		s = canon(s)
		if s == "" {
			continue
		}
		if !m[s] {
			m[s] = true
			u++
		}
	}
	return u
}

func canon(s string) string {
	var i int
	var r rune

	l := ""
	ign := false
	for i, r = range s {
		if r == '+' {
			ign = true
			continue
		}
		if r == '.' {
			continue
		}
		if r == '@' {
			break
		}
		if !ign {
			l += string(unicode.ToLower(r))
		}
	}

	d := strings.ToLower(s[i:])
	if l == "" || d == "" {
		return ""
	}

	m := l + d
	if strings.Count(m, "@") != 1 {
		return ""
	}
	return m
}
