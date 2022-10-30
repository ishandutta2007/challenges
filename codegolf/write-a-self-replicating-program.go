/*

Write a simple program that copies itself when executed.

Your program should be some kind of executable file on Windows, Linux, etc.., should generate new executable file, which is identical to your original executable file, with random name, and quits.

Your program shouldn't involve any kind of file reading or copying. Only file writing for generating new executable file is permitted.

(PS. I was quite embarrassed when at Wikipedia, Self-replicating program redirects to Computer virus article... :/...)

Smallest executable file size wins. Your answer may be a programming code with proper OS & compiler, assembly code, or HEX dump of a executable file.

*/

package main

import (
	"io"
	"log"
	"os"
)

func main() {
	exe, err := os.Executable()
	ck(err)

	f, err := os.Open(exe)
	ck(err)
	defer f.Close()

	io.Copy(os.Stdout, f)
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}
