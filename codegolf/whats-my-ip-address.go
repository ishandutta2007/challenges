/*

I'm surprised this hasn't come up in a challenge yet.

Output the IP address of the machine you're running on. You are required to output both the local and external IP addresses.

Local IP address, ie along the default format of 192.168.x.x

Public IP address can be verified by using google https://www.google.co.uk/search?source=hp&q=whats+my+ip

Output can be in any format. IPv4 or IPv6 or any mix of each is allowed, however they must be the only output. Code can be a full program or a function.

code-golf rules apply so shortest code wins.

Standard Loopholes are forbidden.

EDIT: As per @Peter Taylor's comment, in the case where multiple of either type of address are present, you can choose to either output the first one, or as many as you can access. So long as at least one local and one public are present.

*/

package main

import (
	"fmt"
	"log"
	"net"
)

func main() {
	err := netifs()
	if err != nil {
		log.Fatal(err)
	}
}

func netifs() error {
	intf, err := net.Interfaces()
	if err != nil {
		return err
	}

	for _, it := range intf {
		fmt.Println(it.Index, it.Name, it.MTU, it.HardwareAddr)
		printaddrs("unicast", it.Addrs)
		printaddrs("multicast", it.MulticastAddrs)
	}

	return nil
}

func printaddrs(pfx string, f func() ([]net.Addr, error)) {
	a, err := f()
	if err != nil {
		return
	}
	for _, p := range a {
		fmt.Printf("\t%-12s %s\n", pfx, p)
	}
}
