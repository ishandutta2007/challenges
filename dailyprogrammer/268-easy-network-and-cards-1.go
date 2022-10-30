/*

Description
This week we are creating a game playable over network. This will be a 3-parter.

The first part is to set up a connection between a server and one or more client. The server needs to send out a heartbeat message to the clients and the clients need to respond to it.

For those who want to be prepared, we are going to deal and play cards over the network.

Formal Inputs & Outputs
Input description
No input for the server, but the client needs to know where the server is.

Output description
The client needs to echo the heartbeat from the server.

Notes/Hints
The server needs to able to handle multiple clients in the end, so a multithreaded approach is advised. It is advised to think of some command like pattern, so you can send messages to the server and back.

For the server and client, just pick some random ports that you can use. Here you have a list off all "reserved" ports.

For the connection, TCP connections are the easiest way to do this in most languages. But you are not limited to that if you want to use something more high-level if your language of choice supports that.

Bonus
Make the server broadcast it's existince on the network, so clients can detect him.

Send messages to the server and broadcast it to all the clients

Let the client identify itself (username)

Create a way to list all connected clients

Send messages to the server and relay it to a requested client

These bonuses are not required, but it will make the next part a whole lot easier.

Finally
Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas

*/

package main

import (
	"flag"
	"fmt"
	"log"
	"net"
	"os"
	"strconv"
	"time"
)

func main() {
	var (
		timeout time.Duration
		period  time.Duration
	)
	flag.DurationVar(&timeout, "timeout", 5*time.Second, "set heartbeat timeout")
	flag.DurationVar(&period, "period", 1*time.Second, "set heartbeat period")

	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	port, _ := strconv.Atoi(flag.Arg(0))
	err := server(port, timeout, period)
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <port>")
	flag.PrintDefaults()
	os.Exit(2)
}

func server(port int, timeout, period time.Duration) error {
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

		log.Println("Connection", conn.LocalAddr(), conn.RemoteAddr())
		go serve(conn, timeout, period)
	}
}

func serve(conn net.Conn, timeout, period time.Duration) {
	var buf [128]byte
	for {
		now := time.Now()
		deadline := now.Add(timeout)
		conn.SetDeadline(deadline)

		_, err := conn.Write([]byte{'H', '\n'})
		if err != nil {
			log.Println(err)
			break
		}

		_, err = conn.Read(buf[:])
		if err != nil {
			log.Println(err)
			break
		}

		time.Sleep(period)
	}
	conn.Close()
}
