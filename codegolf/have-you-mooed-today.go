/*

The Debian Linux distribution (and Debian-based distros, like Ubuntu, Kali and others) uses a package-manager called APT. To install program foo you would type into a terminal

sudo apt-get install foo
One little Easter Egg of APT is the following

apt-get moo
Which after typing will produce the following output

                 (__)
                 (oo)
           /------\/
          / |    ||
         *  /\---/\
            ~~   ~~
..."Have you mooed today?"...
You must write a program that produces this EXACT output in as few bytes as possible. (including trailing spaces and a new line)

Here is the same output with \n added to represent newline characters, and a * to represent trailing spaces

                 (__)*\n
                 (oo)*\n
           /------\/*\n
          / |    ||***\n
         *  /\---/\*\n
            ~~   ~~***\n
..."Have you mooed today?"...\n
As requested in the comments, here is the md5sum of the mooing.

35aa920972944a9cc26899ba50024115  -

*/

package main

import "fmt"

func main() {
	fmt.Println(ART)
}

const ART = `
                 (__)
                 (oo)
           /------\/
          / |    ||
         *  /\---/\
            ~~   ~~
..."Have you mooed today?"...`
