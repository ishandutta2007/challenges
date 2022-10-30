/*

This challenge is straightforward, but hopefully, there are plenty of avenues you can approach it:

You need to print/return a valid JSON object of at least 15 characters, not counting unessential whitespace. Your program should work without any input.

In the interest of clarity, a JSON object starts and ends with curly braces {}, and contains zero or more key:value pairs separated by commas. The full JSON specification can be found at json.org, and the output of your code must pass this validator.

Therefore, any of the following would not be valid:

4                               //Too short, not an object
"really, really long string"    //A string, not an object
["an","array","of","values"]    //An array is not a JSON object
{"this":4      }                //You can't count unessential whitespace
{"1":1,"2":3}                   //Too short
{"a really long string"}        //Not valid JSON, it needs a value
{'single-quoted':3}             //JSON requires double-quotes for strings
However, the following would be valid:

{"1":1,"2":2,"3":3,"4":4}       //Long enough
{"whitespace      ":4}          //This whitespace isn't unessential
Non-programming languages are allowed on this challenge. You may return a string from a function, or print it out. This is a code-golf, so answer it with as little code as possible!

*/

package main

import (
	"encoding/json"
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	m := gen(32)
	b, _ := json.MarshalIndent(m, "", "\t")
	fmt.Printf("%s\n", b)
}

func gen(n int) map[int64]int64 {
	m := make(map[int64]int64)
	for i := 0; i < n; i++ {
		m[rand.Int63()] = rand.Int63()
	}
	return m
}
