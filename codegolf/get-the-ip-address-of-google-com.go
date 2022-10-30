/*

Challenge

In this simple challenge, you have to print the public IP address of google.com.
Rules

    You have to output either the IPv6 or IPv4 address, and do it by somehow using internet.

    Output does not strictly need to be the IP address, your answer will be valid if the correct IP address is somewhere in the output, like Hello - google.com - 142.250.67.78 is a valid output.

    You can use DNS queries and any kind of web APIs or web scraping.

    Standard loopholes apply, except usage of URL shorteners, wanna see how creative you can get ;-)

    This is code-golf, so the shortest answer wins!!

*/

package main

import (
	"fmt"
	"log"
	"net"
)

func main() {
	lookup("google.com")
}

func lookup(name string) {
	fmt.Println(name)
	addrs, err := net.LookupHost(name)
	if err != nil {
		log.Fatal(err)
	}
	for _, addr := range addrs {
		fmt.Println(addr)
	}
}
