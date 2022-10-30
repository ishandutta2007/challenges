/*

In the fewest bytes, generate the dictionary of keypresses for any letter (as described in https://code.google.com/codejam/contest/351101/dashboard#s=p2)

In Python, the dictionary literal itself:

{'a':2,'c':222,'b':22,'e':33,'d':3,'g':4,'f':333,'i':444,'h':44,'k':55,'j':5,'m':6,'l':555,'o':666,'n':66,'q':77,'p':7,'s':7777,'r':777,'u':88,'t':8,'w':9,'v':888,'y':999,'x':99,'z':9999}
is 187 bytes so it needs to be less than that. (The values can be strings or ints, ie you can have 'a':'2' or 'a':2 it's up to you)

NOTE: This is not asking you to solve the referenced GCJ problem, it's just asking you to generate a particular dictionary which is related to that problem.

EDIT: You may solve this in any language which has a dictionary-like type (ie hashmap, associative array etc.)

*/

package main

import "fmt"

func main() {
	for k, v := range dict {
		fmt.Printf("%c: %d\n", k, v)
	}
}

var dict = map[rune]int{
	'a': 2, 'c': 222, 'b': 22, 'e': 33, 'd': 3, 'g': 4, 'f': 333, 'i': 444, 'h': 44, 'k': 55, 'j': 5, 'm': 6, 'l': 555, 'o': 666, 'n': 66, 'q': 77, 'p': 7, 's': 7777, 'r': 777, 'u': 88, 't': 8, 'w': 9, 'v': 888, 'y': 999, 'x': 99, 'z': 9999,
}
