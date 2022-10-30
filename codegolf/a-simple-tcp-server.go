/*

Write a program or function that listens for incoming TCP traffic on port N. It offers a simple service: it calculates sum of IP address fields of incoming connection and returns.

Program or function reads integer N from arguments or stdin. It listens to incoming TCP connections on port N.
When someone connects to that port, the program calculates sum of its IP address fields and sends it back to the client with trailing newline and closes connection.

    Port number N is a valid port, and 210 < N < 215
    Trailing newline can be either \nor \r\n
    You can use either IPv4 or IPv6. Since IPv6 addresses are written in hexadecimal form, you must also provide result in same format, for example 2001:0db8:0000:0042:0000:8a2e:0370:7334 => 12ecd.

This is code-golf. Standard rules and loopholes apply.
Example

You run your server with ./server 1234. The server is now running and waiting for connections on port 1234. Then a client from 127.0.0.1 connects to your server.
Your server performs a simple calculation: 127+0+0+1 => 128 and sends the result to the client (with trailing newline): 128\n. Then server closes connection and waits for next client.

*/

package main

import (
	"flag"
	"fmt"
	"log"
	"net"
	"os"
	"strconv"
	"strings"
)

func main() {
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	port, _ := strconv.Atoi(flag.Arg(0))
	err := server(port)
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: <port>")
	flag.PrintDefaults()
	os.Exit(2)
}

func server(port int) error {
	addr := fmt.Sprintf(":%d", port)
	ln, err := net.Listen("tcp", addr)
	if err != nil {
		return err
	}
	defer ln.Close()

	for {
		conn, err := ln.Accept()
		if err != nil {
			log.Println(err)
			continue
		}

		fmt.Println("Connection", conn.LocalAddr(), conn.RemoteAddr())
		go serve(conn)
	}
}

func parseip(conn net.Conn) net.IP {
	addr := conn.LocalAddr()
	str := addr.String()
	index := strings.LastIndexByte(str, ':')
	if index >= 0 {
		str = str[:index]
	}
	str = strings.TrimLeft(str, "[")
	str = strings.TrimRight(str, "]")

	return net.ParseIP(str)
}

func sumip(ip net.IP) string {
	v4 := ip.To4()
	v6 := ip.To16()

	data := v4
	if data == nil {
		data = v6
	}

	sum := 0
	for i := range data {
		sum += int(data[i])
	}

	if v4 != nil {
		return fmt.Sprintf("%d", sum)
	}
	return fmt.Sprintf("%x", sum)
}

func serve(conn net.Conn) {
	ip := parseip(conn)
	fmt.Fprintf(conn, "%s\n", sumip(ip))
	conn.Close()
}
