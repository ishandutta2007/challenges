/*

 (Easy): Checksums

Checksums are a tool that allow you to verify the integrity of data (useful for networking, security, error-correction, etc.). Though there are many different Checksum algorithms, the general usage is that you give raw-data to your algorithm of choice, and a block of data (usually smaller than the given data) is generated and can later be used by re-computing the checksum and comparing the original and recent values.

A classic example for how helpful Checksums are is with data-networking: imagine you have a packet of information that must be guaranteed the same after receiving it. Before sending the data, you can compute its checksum, and send both blocks together. When received, the data can be used to re-compute a checksum, and validate that the given checksum and your own checksum are the same. The subject is much more complex, since there are issues of data-entropy and the importance of the checksum's size compared to the raw data size.

This example is so common in network programming, one of the basic Internet networking protocols (TCP) has it built-in!

Your goal will be more modest: you must implement a specific checksum algorithm (Fletcher's 16-bit Checksum) for given lines of text input. The C-like language pseudo-code found on Wikipedia is a great starting point!

Note: Make sure to explicitly implement this algorithm, and not call into other code (libraries). The challenge here is focused on your implementation of the algorithm.
Formal Inputs & Outputs
Input Description

On standard console input, you will first be given an integer N which ranges inclusively from 1 to 256. After this line, you will receive N-lines of ASCII text. This text will only contain regular printable characters, and will all be on a single line of input.
Output Description

For each line of input, print the index (starting from 1) and the 16-bit Fletcher's checksum as a 4-digit hexadecimal number.
Sample Inputs & Outputs
Sample Input

3
Fletcher
Sally sells seashells by the seashore.
Les chaussettes de l'archi-duchesse, sont-elles seches ou archi-seches ?

Sample Output

1 D330
2 D23E
3 404D

*/

package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"os"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("checksum: ")

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}
	err := checksum(flag.Arg(0))
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: checksum [options] file")
	flag.PrintDefaults()
	os.Exit(2)
}

func checksum(name string) error {
	f, err := os.Open(name)
	if err != nil {
		return err
	}
	defer f.Close()

	s := bufio.NewScanner(f)

	var n uint
	s.Scan()
	fmt.Sscan(s.Text(), &n)

	for i := uint(1); i <= n; i++ {
		s.Scan()
		fmt.Printf("%d %X\n", i, fletch16(s.Text()))
	}

	return nil
}

func fletch16(s string) uint16 {
	x, y := uint16(0), uint16(0)
	for i := 0; i < len(s); i++ {
		x = (x + uint16(s[i])) % 255
		y = (y + x) % 255
	}
	return y<<8 | x
}
