/*

A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]
Example 3:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]


Constraints:

1 <= s.length <= 20
s consists of digits only.

*/

package main

import (
	"fmt"
	"net"
	"reflect"
)

func main() {
	test("25525511135", []string{"255.255.11.135", "255.255.111.35"})
	test("0000", []string{"0.0.0.0"})
	test("101023", []string{"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"})
	test("255255255255", []string{"255.255.255.255"})
	test("311333333333", []string{})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []string) {
	p := ips(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func ips(s string) []string {
	r := []string{}
	n := len(s)
	for i := 1; i < n; i++ {
		for j := i + 1; j < n; j++ {
			for k := j + 1; k < n; k++ {
				a := fmt.Sprintf("%s.%s.%s.%s", s[:i], s[i:j], s[j:k], s[k:])
				if net.ParseIP(a) != nil {
					r = append(r, a)
				}
			}
		}
	}
	return r
}
