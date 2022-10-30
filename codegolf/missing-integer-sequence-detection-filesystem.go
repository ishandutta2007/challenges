/*

The challenge is to detect missing integer sequences of files or directories. You have a directory filled with files/directories that are named as integers.

The files/directories are generated from multiple threads yet the job did not complete - there are therefore gaps in the sequence.

The input is two integers a start and an end, and your task is detect the starting integer of the next missing sequences. You may presume that all files and directories in the directory where run have only integer named files or directories.

Acceptable answer forms: functions, code snippets - they must run on the command line.
Acceptable start/end input: included on the command line, env variables/argv are okay, parameters to functions, user input is okay.
Shortest code wins.

Update -- Although I managed to squeeze out this one, there were many interesting answers. The idea in apricotboy's Bash answer was used in part to help me design my 35 Byte Bash answer. Best of luck on the next one.

E.g. Presume files 1,2,3,4,7,8,9,10,18 are present, start is 1, end is 20:

The output should be:
5
11
19

*/

package main

import (
	"flag"
	"fmt"
	"io/fs"
	"os"
	"path/filepath"
	"strconv"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 3 {
		usage()
	}

	dir := flag.Arg(0)
	start, _ := strconv.Atoi(flag.Arg(1))
	end, _ := strconv.Atoi(flag.Arg(2))

	walker := &walker{seen: make(map[int]bool)}
	filepath.Walk(dir, walker.walk)
	for i := start; i <= end; i++ {
		if !walker.seen[i] {
			fmt.Println(i)
		}
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <dir> <start> <end>")
	flag.PrintDefaults()
	os.Exit(2)
}

type walker struct {
	seen map[int]bool
}

func (w *walker) walk(path string, info fs.FileInfo, err error) error {
	n, xerr := strconv.Atoi(info.Name())
	if xerr == nil {
		w.seen[n] = true
	}
	return nil
}
