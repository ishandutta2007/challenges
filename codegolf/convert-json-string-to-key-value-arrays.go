/*

Convert JSON (key/value pairs) to two native arrays, one array of keys and another of values, in your language.

var X = '{"a":"a","b":"b","c":"c","d":"d","e":"e","f":"f9","g":"g2","h":"h1"}';

The value array could be an array of strings or integers.

So we need two functions keys & vals, returning native arrays on input of JSON string.

In above example the output would be:

keys : ["a", "b", "c", "d", "e", "f", "g", "h"]
vals : ["a", "b", "c", "d", "e", "f9", "g2", "h1"]

Here is my attempt at this using javascript:

keys : (53 Chars)

function keys(X){return X.match(/[a-z0-9]+(?=":)/gi)}

vals : (56 Chars)

function vals(X){return X.match(/[a-z0-9]+(?="[,}])/gi)}

Can other languages challenge this??

*/

package main

import (
	"encoding/json"
	"fmt"
	"sort"
)

func main() {
	fmt.Println(kvpair(`{"a":"a","b":"b","c":"c","d":"d","e":"e","f":"f9","g":"g2","h":"h1"}`))
}

func kvpair(str string) (keys, vals []string, err error) {
	var m map[string]string
	err = json.Unmarshal([]byte(str), &m)
	if err != nil {
		return
	}

	var r [][2]string
	for k, v := range m {
		r = append(r, [2]string{k, v})
	}
	sort.Slice(r, func(i, j int) bool {
		return r[i][0] < r[j][0]
	})

	for i := range r {
		keys = append(keys, r[i][0])
		vals = append(vals, r[i][1])
	}

	return
}
