/*

The task is simple, given two IP adresses a and b, output all addresses within that range.

Examples

Example #1:

f(a = 192.168.0.1, b = 192.168.0.4)
    192.168.0.1
    192.168.0.2
    192.168.0.3
    192.168.0.4

Example #2 (TIO will truncate this, use a smaller range when testing):

f (a = 123.0.200.0, b = 124.0.0.0)
    123.0.200.0
    123.0.200.1
    ...            # Omitted pattern
    123.0.200.255
    123.0.201.0
    ...            # Omitted pattern
    123.0.201.255
    ...            # Omitted pattern
    123.0.255.255
    123.1.0.0
    ...            # Omitted pattern
    123.255.255.255
    124.0.0.0

Input and Output

    a < b in other words:
        Defined Programatically: a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]) || (a[0:1] == b[0:1] && a[2] < b[2]) || (a[0:2] == b[0:2] && a[3] < b[3])
        Defined in Words: a will always be lower than b (so you will have to increment the subnet to reach b).
        No, you do not have to handle a == b (if you do, kudos).
    Output should be in order from "lowest" to "highest" (see examples).
    For this challenge, the valid syntax for an IP is: \d{1-3}\.\d{1-3}\.\d{1-3}\.\d{1-3}.
    You do not have to handle non-IP address input, if it's unexpected input you may error.
    Output may be as an array or as a delimited string (using any whitespace character).

Winning

    This is code-golf, lowest byte-count wins.

*/

package main

import (
	"fmt"
	"net"
)

func main() {
	ips("192.168.0.1", "192.168.0.4")
	ips("123.255.200.0", "124.0.0.0")
	ips("255.255.255.0", "255.255.255.255")
}

func ips(a, b string) {
	if a > b {
		a, b = b, a
	}
	x := net.ParseIP(a)
	y := net.ParseIP(b)

	x = x.To4()
	y = y.To4()

	if x == nil || y == nil {
		return
	}

	fmt.Printf("%v - %v\n", x, y)
	for {
		fmt.Println(x)
		if x.Equal(y) {
			break
		}
		inc(x)
	}
	fmt.Println()
}

func inc(b []byte) {
	n := len(b) - 1
	for ; n >= 0; n-- {
		if b[n] == 0xff {
			b[n] = 0
		} else {
			b[n]++
			break
		}
	}
}
