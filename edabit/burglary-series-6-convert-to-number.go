/*

You prepare a list to send to the insurance company. As you finish, you notice you misformatted it.
Given an object with at least one key/value pair, convert all the values to numbers.

Examples

convertToNumber({ "piano"="200" }) ➞ { "piano"=200 }

convertToNumber({ "piano"="200", "tv"="300" }) ➞ { "piano"=200, "tv"=300 }

convertToNumber({ "piano"="200", "tv"="300", "stereo"="400" }) ➞ { "piano"=200, "tv"=300, "stereo"=400 }

Notes

N/A

*/

package main

import (
	"fmt"
	"reflect"
	"strconv"
)

func main() {
	test(map[string]string{"piano": "200"}, map[string]int{"piano": 200})
	test(map[string]string{"piano": "200", "tv": "300"}, map[string]int{"piano": 200, "tv": 300})
	test(map[string]string{"piano": "200", "tv": "300", "stereo": "400"}, map[string]int{"piano": 200, "tv": 300, "stereo": 400})
}

func test(m map[string]string, r map[string]int) {
	p := convert(m)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func convert(m map[string]string) map[string]int {
	r := make(map[string]int)
	for k, v := range m {
		r[k], _ = strconv.Atoi(v)
	}
	return r
}
