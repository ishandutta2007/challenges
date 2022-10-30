/*

At runtime, keep prompting for a line of input until the user input is not the name of an existing file or directory or other file system item, relative to the current working directory.
Then return/print that last inputted filename. You may assume that all user inputs will be valid filenames.

Pseudo-code 1
myform = new form("GUI")
myform.mytxt = new editfield("")
myform.ok = new button("OK")
repeat
  waitfor(myform.ok,"click")
until not filesystem.exists(myform.mytxt.content)
return(myform.mytxt.content)

Pseudo-code 2
LET TEXT = "."
WHILE HASFILE(TEXT) DO
  TEXT = PROMPT("")
ENDWHILE
RETURN TEXT

Examples of user input which will cause re-prompting when on TIO:
.
..
.env.tio
/
/bin/[
/lost+found

Examples of user input which will return when on TIO:
...
env.tio
../../bin/]
/lost/found

*/

package main

import (
	"fmt"
	"os"
)

func main() {
	prompt()
}

func prompt() string {
	var name string
	for {
		fmt.Print("Enter a filename: ")
		fmt.Scanln(&name)

		f, err := os.Open(name)
		if err != nil {
			break
		}
		f.Close()
	}
	return name
}
