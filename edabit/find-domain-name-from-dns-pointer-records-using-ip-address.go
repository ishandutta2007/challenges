/*

Write a function that takes an IP address and returns the domain name using PTR DNS records.

Example

get_domain("8.8.8.8") ➞ "dns.google"

get_domain("8.8.4.4") ➞ "dns.google"

Notes

    You may want to import socket.
    Don't cheat and just print the domain name, you need to make a real DNS request.
    Return as a string.

*/

package main

import (
	"fmt"
	"net"
	"strings"
)

func main() {
	fmt.Println(domain("8.8.8.8"))
	fmt.Println(domain("8.8.4.4"))
}

func domain(h string) string {
	p, err := net.LookupAddr(h)
	if err != nil {
		return ""
	}
	return strings.TrimSuffix(p[0], ".")
}
