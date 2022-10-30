/*

Write the shortest code that traverses a directory tree and outputs a flat list of all files.

It should traverse the whole directory tree
The order in which it enters sub-directories doesn't matter
The directories should not be output
The output should be a plain list — the definition is flexible, but it shouldn't contain irrelevant data
You are free to use any programming technique

*/

package main

import (
	"flag"
	"fmt"
	"io/fs"
	"os"
	"path/filepath"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	filepath.Walk(flag.Arg(0), walk)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <path>")
	flag.PrintDefaults()
	os.Exit(2)
}

func walk(path string, info fs.FileInfo, err error) error {
	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Println(path)
	}
	return nil
}
