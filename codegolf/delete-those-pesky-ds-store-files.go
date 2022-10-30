/*

If you use OS X then you might be familiar with the infamous hidden ".DS_Store" files that are produced as a result of using Finder.

The challenge is to write code that will go through the entire file system and delete any file named ".DS_Store".

Classic code golf - shortest code wins.

Clarifications:

The code does not need to delete any .DS_Store files that require superuser; assume no such files exist.

The code should only delete the relevant .DS_Store files and nothing else.

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
	if flag.NArg() < 1 {
		usage()
	}

	for _, path := range flag.Args() {
		filepath.Walk(path, remover)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: <path> ...")
	flag.PrintDefaults()
	os.Exit(2)
}

func remover(path string, info fs.FileInfo, err error) error {
	if err != nil {
		fmt.Println(err)
		return nil
	}

	if info.Name() != ".DS_Store" || info.IsDir() {
		return nil
	}

	fmt.Printf("Removing %s\n", path)
	err = os.Remove(path)
	if err != nil {
		fmt.Printf("Failed to remove %s: %s\n", path, err)
	}

	return nil
}
