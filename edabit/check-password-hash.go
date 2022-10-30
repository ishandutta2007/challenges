/*

Write a function that takes a username and password and checks the list userPassDb for a match.
The list stores the passwords as a hash using the SHA1 algorithm. Return true for a match and false otherwise.

Examples

userPassDb = [{"username" : "myUsername", "pass_hash" : "5413ee24723bba2c5a6ba2d0196c78b3ee4628d1"}]

checkPass("myUsername", "myPassword") ➞ true

checkPass("myUsername", "wrongPassword") ➞ false

Notes

N/A

*/

package main

import (
	"crypto/sha1"
	"fmt"
)

func main() {
	assert(checkpass("lola", "jimbob") == true)
	assert(checkpass("tony", "hexagon") == true)
	assert(checkpass("jason", "tyrannosaurus") == true)
	assert(checkpass("dan", "FranklinPierce123") == true)
	assert(checkpass("somebot", "admin123") == false)
	assert(checkpass("lola", "wrongpass") == false)
	assert(checkpass("myUsername", "myPassword") == true)
	assert(checkpass("myUsername", "wrongPassword") == false)
}

func checkpass(user, pass string) bool {
	tab := map[string]string{
		"tony":       "11725d3f4588325f1c90c50348624dcc55978f39",
		"jason":      "5a6d719f958b1a610712f8e342ef0a4dd4b80a35",
		"lola":       "7dda6e1b3988b488b0821e24732ca42d6b72f0ce",
		"dan":        "ec09d3b165aeabf77f5c9436c2d644b6e2f31ba9",
		"myUsername": "5413ee24723bba2c5a6ba2d0196c78b3ee4628d1",
	}
	hash := fmt.Sprintf("%x", sha1.Sum([]byte(pass)))
	return tab[user] == hash
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
