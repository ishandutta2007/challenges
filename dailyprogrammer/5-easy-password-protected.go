/*

Your challenge for today is to create a program which is password protected, and wont open unless the correct user and password is given.
For extra credit, have the user and password in a seperate .txt file.
For even more extra credit, break into your own program :)

*/

package main

import (
	"crypto/sha512"
	"crypto/subtle"
	"fmt"
	"strings"
)

func main() {
	for {
		user, _ := input("Username")
		pass, _ := input("Password")
		if auth(user, pass) {
			break
		}
	}
	fmt.Println("FREEDOM")
}

func auth(name, pass string) bool {
	h := sha512.Sum512([]byte(pass))

	x := name
	y := fmt.Sprintf("%x", h)

	a := subtle.ConstantTimeCompare([]byte(x), []byte("luser"))
	b := subtle.ConstantTimeCompare([]byte(y), []byte("197bcc298645b84bd95bba43749f708745375ce30262d3ecdc8439605d157786a6f9d8bac4a8dd31e9e68364820e3fc39ab6a15a75988d994f3a6361d0d37309"))
	return a&b != 0
}

func input(str string) (string, error) {
	var val string
	fmt.Printf("%s: ", str)
	_, err := fmt.Scan(&val)
	val = strings.TrimSpace(val)
	return val, err
}
