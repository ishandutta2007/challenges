/*

It is simple. I cannot stand when people use spaces when naming files. It sometimes wrecks console commands and makes the output of ls ugly.

The challenge is to write a program (only ascii characters) which

renames all files (including directories) in the current directory to versions with spaces removed or replaced by '_'
on collision, you need to append a unique identifier (up to you)
descends recursively into all subdirectories
You can assume UNIX-style path names. Who would need this program on a Windows machine anyways?

This is code golf, the shortest program wins (#ascii characters). Since I hate spaces so much, each space has to be counted twice.

Please provide your language, score, program and a short description of how to run it.

The program must compile and execute with reasonable effort on my linux machine.

EDIT: As Etan requested a file structure for testing, here is the script I currently use to create a suitable file tree:

#!/bin/bash
rm -r TestDir

touchfiles()
{
    touch my_file
    touch my__file
    touch "my file"
    touch "my  file"
    touch " my_file  "
}

mkdir TestDir
cd TestDir

touchfiles

for dir in "Test Sub" Test_Sub "Te stSub" Te_stSub
do
    mkdir "$dir"
    cd "$dir"
    touchfiles
    cd ..
done

*/

package main

import (
	"bytes"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"unicode"
)

func main() {
	root := "."
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() == 1 {
		root = flag.Arg(1)
	}
	renamer(root)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] path")
	flag.PrintDefaults()
	os.Exit(2)
}

func renamer(root string) {
	entries, err := os.ReadDir(root)
	if err != nil {
		fmt.Println(err)
		return
	}

	var next []string
	for _, entry := range entries {
		name0 := entry.Name()
		name1 := trim(name0)
		if name0 == name1 {
			if entry.IsDir() {
				next = append(next, filepath.Join(root, name0))
			}
			continue
		}

		path0 := filepath.Join(root, name0)
		path1 := filepath.Join(root, name1)
		fmt.Printf("attempting to rename %q\n", path0)

		err := rename(path0, path1, 1e6)
		if err != nil {
			fmt.Println(err)
			path1 = path0
		}

		if entry.IsDir() {
			next = append(next, path1)
		}
	}

	for _, path := range next {
		renamer(path)
	}
}

func trim(str string) string {
	buf := new(bytes.Buffer)
	for _, r := range str {
		if unicode.IsSpace(r) {
			r = '_'
		}
		buf.WriteRune(r)
	}
	return buf.String()
}

func rename(path, newpath string, tries int) error {
	nextpath := newpath
	for trie := 0; trie < tries+1; trie++ {
		f, err := os.Open(nextpath)
		if err != nil {
			return os.Rename(path, nextpath)
		}
		f.Close()

		nextpath = fmt.Sprintf("%v_%d", newpath, trie)
	}
	return fmt.Errorf("%s: rename failed due to collisions", path)
}
