/*

You have to print out your username, by only using the characters in your username.

Standard loopholes are forbidden

This is not code-golf, so shortest does not win

Don't modify your username please

And each language be used one time

*/

package main

import (
	"fmt"
	"log"
	"os/user"
)

func main() {
	u, err := user.Current()
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(u.Username)
}
