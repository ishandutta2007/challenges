/*

Challenge

Detect the newest file in a specific folder and pass it as an argument to another process. The first argument to your program will be the folder, and the second argument will be the full path to the process.

Please specify the platform(s) your code works on.

Examples

Windows
newestfile "C:\Public_domain_movies\" "C:\Mplayer\mplayer.exe"

Linux
./newestfile /home/user /bin/ls

*/

package main

import (
	"flag"
	"fmt"
	"io/fs"
	"log"
	"os"
	"os/exec"
	"path/filepath"
	"time"
)

func main() {
	log.SetPrefix("newest: ")
	log.SetFlags(0)

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}

	file, err := newest(flag.Arg(0))
	check(err)

	cmd := exec.Command(flag.Arg(1), file)
	cmd.Stdin = os.Stdin
	cmd.Stderr = os.Stderr
	cmd.Stdout = os.Stdout
	err = cmd.Run()
	check(err)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <dir> <program>")
	flag.PrintDefaults()
	os.Exit(2)
}

func newest(dir string) (file string, err error) {
	file = dir
	entries, err := os.ReadDir(dir)
	if err != nil {
		return
	}

	var (
		latest time.Time
		info   fs.FileInfo
	)
	for _, entry := range entries {
		info, err = entry.Info()
		if err != nil {
			return
		}

		mode := info.Mode()
		if !mode.IsRegular() {
			continue
		}

		modtime := info.ModTime()
		if latest.Before(modtime) {
			file = filepath.Join(dir, entry.Name())
			latest = modtime
		}
	}

	return
}
