/*

Given a directory (such as C:/), given from stdin or read from a file, produce a directory tree, with each file/folder indented based on its depth.

Example
If I have a C:/ drive which only contains two folders foo and bar, and bar is empty while foo contains baz.txt, then running with input C:/ produces:

C:/
    bar/
    foo/
        baz.txt
while running with input C:/foo/ should produce

foo/
    baz.txt

As this is codegolf, lowest byte count wins. The file extensions (such as baz.txt) are optional.
Extra notes: hidden files can be ignored, directories must actually exist, it can be assumed that files do not contain unprintable characters or new lines but all other printable ASCII characters are fine (file names with spaces must be supported).
Output can be written to file or stdout. The indentations can be made up of either a tab character or 4 spaces.

*/

package main

import (
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"strings"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}
	treehouse(flag.Arg(0))
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] path")
	flag.PrintDefaults()
	os.Exit(2)
}

func treehouse(name string) {
	walk(name, 0)
}

func walk(name string, indent int) {
	output(name, indent, true)

	fis, err := os.ReadDir(name)
	if err != nil {
		return
	}
	for _, fi := range fis {
		subname := filepath.Join(name, fi.Name())
		if fi.IsDir() {
			walk(subname, indent+1)
		} else {
			output(subname, indent+1, false)
		}
	}
}

func output(name string, indent int, dir bool) {
	spaces := strings.Repeat(" ", 4*indent)
	name = filepath.Clean(name)

	fmt.Printf("%s%s", spaces, name)
	if dir {
		fmt.Printf("/")
	}
	fmt.Println()
}
