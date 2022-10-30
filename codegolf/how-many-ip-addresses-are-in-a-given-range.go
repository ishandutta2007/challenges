/*

Inspired by...

    Networking - How can I work out how many IP addresses there are in a given range?

Write a program or function that takes two strings as input, each being an IPv4 address expressed in standard dotted notation and outputs or returns the number of IP addresses covered by this range, including the two IP addresses input.

    You must not use any external code, libraries or services designed to parse an IP address. (Other string processing standard library functions are acceptable.)
    All 2^32 IP addresses are equal. No distinction is made to broadcast, class E, etc.
    Normal code-golf rules apply.

For example:

"0.0.0.0","255.255.255.255" returns 4294967296.
"255.255.255.255","0.0.0.0" also returns 4294967296.
"1.2.3.4","1.2.3.4" returns 1.
"56.57.58.59","60.61.62.63" returns 67372037.
"1","2" is invalid input. Your code may do anything you like.

*/

package main

import (
	"encoding/binary"
	"math"
	"net"
)

func main() {
	assert(addresses("0.0.0.0", "255.255.255.255") == 4294967296)
	assert(addresses("255.255.255.255", "0.0.0.0") == 4294967296)
	assert(addresses("1.2.3.4", "1.2.3.4") == 1)
	assert(addresses("56.57.58.59", "60.61.62.63") == 67372037)
	assert(addresses("1", "2") == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func addresses(a, b string) uint64 {
	x := parseip(a)
	y := parseip(b)
	if y < x {
		x, y = y, x
	}
	if x == math.MaxUint64 || y == math.MaxUint64 {
		return 0
	}
	return y - x + 1
}

func parseip(s string) uint64 {
	ip := net.ParseIP(s)
	ip = ip.To4()
	if ip == nil {
		return math.MaxUint64
	}
	return uint64(binary.BigEndian.Uint32(ip))
}
