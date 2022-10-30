/*

Your task is to write a program to perform set operations. The operations and arguments are taken from command line in the format program operation [argument]. There are four operations:

    1: clears the set. no arguments. exit code 0.
    2 integer: adds the integer into the set. exit code 0.
    3 integer: removes the integer from the set. exit code 0.
    4 integer: queries the set for integer. exit code 0 if integer exists or 1 otherwise.

The integer is a 64-bits integer. Shortest program wins. You can, of course, use a temporary file. However, watch out the space and time limit.

Example:

$ program 1 ; echo $?
0
$ program 2 10 ; echo $?
0
$ program 4 10 ; echo $?
0
$ program 3 10 ; echo $?
0
$ program 4 10 ; echo $?
1
$ program 2 10 ; echo $?
0
$ program 1 ; echo $?
0
$ program 4 10 ; echo $?
1

*/

package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}
	code := strings.Join(flag.Args(), " ")

	var db DB
	db.Reset()
	db.Load("set.json")
	status, err := db.Update(code)
	ck(err)
	ck(db.Save("set.json"))
	os.Exit(status)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] operation")
	flag.PrintDefaults()
	os.Exit(2)
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

type DB struct {
	set map[int]bool
}

func (db *DB) Reset() {
	db.set = make(map[int]bool)
}

func (db *DB) Load(name string) error {
	data, err := os.ReadFile(name)
	if err != nil {
		return err
	}
	return json.Unmarshal(data, &db.set)
}

func (db *DB) Save(name string) error {
	data, err := json.MarshalIndent(db.set, "", "\t")
	if err != nil {
		return err
	}
	return os.WriteFile(name, data, 0644)
}

func (db *DB) Update(code string) (int, error) {
	tok := strings.Split(code, " ")
	val := 0
	if len(tok) > 1 {
		val, _ = strconv.Atoi(tok[1])
	}

	ret := 0
	switch tok[0] {
	case "1":
		db.Reset()
	case "2":
		db.set[val] = true
	case "3":
		delete(db.set, val)
	case "4":
		if _, exist := db.set[val]; exist {
			ret = 1
		}
	default:
		return 0, fmt.Errorf("Unknown operation %q", code)
	}
	return ret, nil
}
