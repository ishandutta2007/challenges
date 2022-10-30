/*

Goal:
Create a program to find the smallest file in the current folder.

File size may be measured in bytes or characters.

If multiple files have the same size, you can either choose one or display all of them.

You can assume there will be at least one file in the folder, and no files will have a size of 0.

Assume that all files in the folder can be loaded by the language you're using.

Assume that there are no folders in the current directory.

Input:
The program should not take any input from the user, unless:

If your language doesn't have a "current folder", it may ask the user for a folder name/path.
If your language cannot directly access files on your computer, it may allow the user to upload files. (JavaScript, for example)

Output:
The name of the smallest file should be displayed.

Leading/trailing symbols are allowed, as long as it's clear which file has been chosen.
(Printing a list of all the files is against the rules).

Notes:
Standard Loopholes are not allowed.
You cannot modify/create/delete files in the folder to change the result.
This is code-golf; shortest answer (in bytes) wins.

*/

package main

import (
	"flag"
	"fmt"
	"io/fs"
	"log"
	"os"
	"sort"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	err := smallest(flag.Arg(0))
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] path")
	flag.PrintDefaults()
	os.Exit(2)
}

func smallest(path string) error {
	de, err := os.ReadDir(path)
	if err != nil {
		return err
	}

	var fis []fs.FileInfo
	for _, de := range de {
		fi, err := de.Info()
		if err != nil {
			continue
		}

		fm := fi.Mode()
		if !fm.IsRegular() {
			continue
		}

		fis = append(fis, fi)
	}

	sort.Slice(fis, func(i, j int) bool {
		return fis[i].Size() < fis[j].Size()
	})

	for i := range fis {
		fmt.Printf("%q (%d bytes)\n", fis[i].Name(), fis[i].Size())
		if i+1 < len(fis) {
			if fis[i].Size() != fis[i+1].Size() {
				break
			}
		}
	}

	return nil
}
