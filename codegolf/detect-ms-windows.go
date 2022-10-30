/*

Challenge

Create a program that returns a truthy value when run on Microsoft Windows (for simplicity we'll stick with Windows 7, 8.1 and 10) and a falsey value when run on any other operating system (OSX, FreeBSD, Linux).
Rules

    Code that fails to run/compile on a platform doesn't count as a falsey value.

Winning criteria

I'm labelling this as code-golf, so lowest score wins, but I'm also very interested in seeing creative solutions to this problem.

*/

package main

import (
	"fmt"
	"runtime"
)

func main() {
	fmt.Println(iswindows())
}

func iswindows() bool {
	return runtime.GOOS == "windows"
}
