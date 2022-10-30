/*

This reminds me when a few years ago someone uploaded a torrent "Hacker tool: complete list of all IP addresses". This was, of course, just a generated list of the ~4 billion IPv4 addresses, but thousands of "h4xx0rz" downloaded it. Look mum, imahacker!

This was then, but nowadays everybody has switched to IPv6. (Right?)

Your task is to write a program that prints out all IPv6 addresses.

You should write a full program that takes no input and prints IPv6 addresses, one per line, and no other output. Your program must print all 2^128 possible addresses, including invalid ones.
Each address must be printed exactly once. You may print the addresses in any order.

Each address may be printed in full, with 8 groups of 4 hexadecimal digits separated by colons, e.g.

2001:0db8:85a3:0000:0000:8a2e:0370:7334

You may, at your discretion, use any of the standard abbreviations from RFC 5952:

    Leading zeros in a group may be omitted, except that 0 cannot be abbreviated further.
    :: may be used at most once per address to abbreviate a sequence of one or more all-zero groups.
    The hexadecimal digits may use lowercase or uppercase.

If you achieve the representation recommendation from RFC 5952 (lowercase letters only, shortest possible representation, with :: used as early as possible if there are multiple places where it can be used), you get a -20% bonus.

Due to the size of the output, your program is not expected to finish while we're sitting there.
Your program may be interrupted by external means at some point (Ctrl+C, pulling out the power, …).
Your program must produce output as a stream, so that after a “reasonable” wait, it will have produced some lines.
Basically, building a giant string in memory only to print it at the end is not allowed.
Any program that would run out of memory on a “standard” PC is disqualified. (Nonetheless, if your program was left to run for sufficiently long, it must print all IPv6 addresses and then exit.)

(If this condition is a problem for web interpreters that run the program until completion and then let you see the output, and you don't have a hosted interpreter, test your program on a smaller version of the problem, and then carefully adjust it to the full 2128.)

Your score is your program's length in bytes, multiplied by 0.8 if you get the bonus. It's code golf, so the lowest score wins.

*/

package main

import (
	"fmt"
	"math/big"
	"net"
)

func main() {
	enumerate()
}

func enumerate() {
	x := xint("0")
	y := xint("340282366920938463463374607431768211456")
	n := xint("1")
	for ; x.Cmp(y) != 0; x.Add(x, n) {
		fmt.Println(ipv6(x.Bytes()))
	}
}

func xint(s string) *big.Int {
	x := new(big.Int)
	x.SetString(s, 0)
	return x
}

func ipv6(b []byte) net.IP {
	return net.IP(padbytes(b, 16))
}

func padbytes(b []byte, n int) []byte {
	if m := len(b); m < n {
		b = append(b, make([]byte, n-m)...)
	}
	return b[:n]
}
