/*

This is a code-golf question. You need to take the contents of two separate files (i.txt and o.txt) and swap them.
You can create a third file to help you with the process, but have your program delete it after the file contents are swapped.
Renaming the files is now allowed again.

Programs must work for any file content.

Shortest code wins, all eligible submissions will be up-voted.

*/

package main

import (
	"flag"
	"fmt"
	"log"
	"os"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("swap-file: ")

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}

	a := readfile(flag.Arg(0))
	b := readfile(flag.Arg(1))

	writefile(flag.Arg(1), a)
	writefile(flag.Arg(0), b)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <file1> <file2>")
	flag.PrintDefaults()
	os.Exit(2)
}

func readfile(name string) []byte {
	buf, err := os.ReadFile(name)
	if err != nil {
		log.Fatal(err)
	}
	return buf
}

func writefile(name string, buf []byte) {
	err := os.WriteFile(name, buf, 0644)
	if err != nil {
		fmt.Fprintln(os.Stderr, "swap-file:", err)
	}
}
