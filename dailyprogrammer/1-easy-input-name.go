/*

create a program that will ask the users name, age, and reddit username. have it tell them the information back, in the format:

your name is (blank), you are (blank) years old, and your username is (blank)
for extra credit, have the program log this information in a file to be accessed later.

*/

package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"math/big"
	"os"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("userinfo: ")

	flag.Parse()
	var (
		name     string
		age      = new(big.Int)
		username string
	)
	ask("What is your name?", &name)
	ask("What is your age?", age)
	ask("What is your reddit username?", &username)
	fmt.Printf("Your name is %v, you are %v years old, and your reddit username is %v\n",
		name, age, username)

	if flag.NArg() >= 1 {
		f, err := os.Create(flag.Arg(0))
		if err != nil {
			log.Fatal(err)
		}
		fmt.Fprintf(f, "Your name is %v, you are %v years old, and your reddit username is %v\n",
			name, age, username)
		err = f.Close()
		if err != nil {
			log.Fatal(err)
		}
	}
}

func ask(str string, v interface{}) {
	s := bufio.NewScanner(os.Stdin)
	for {
		fmt.Println(str)
		if !s.Scan() {
			os.Exit(0)
		}

		l := s.Text()
		n, err := fmt.Sscanln(l, v)
		if n == 0 || err != nil {
			fmt.Println("Invalid response! Please try again")
			continue
		}

		break
	}
}
