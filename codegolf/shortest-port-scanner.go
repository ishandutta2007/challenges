/*

Write the shortest program that will attempt to connect to open ports on a remote computer and check if they are open. (It's called a Port Scanner)

Take input from command line arguments.

your-port-scanner host_ip startPort endPort

Assume, startPort < endPort (and endPort - startPort < 1000)

Output: All the open ports between that range should space or comma seperated.

*/

package main

import (
	"fmt"
	"net"
)

func main() {
	scan("127.0.0.1", 1, 65536)
}

func scan(host string, start, end int) error {
	if start > end {
		start, end = end, start
	}

	fmt.Println("Scanning", host)
	fmt.Println()
	fmt.Println("PORT")

	for port := start; port <= end; port++ {
		addr := fmt.Sprintf("%v:%v", host, port)
		conn, err := net.Dial("tcp", addr)
		if err != nil {
			continue
		}
		fmt.Println(port)
		conn.Close()
	}

	return nil
}
