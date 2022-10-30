/*

Create two functions to_camel_case() and to_snake_case() that each take a single string and convert it into either camelCase or snake_case. If you're not sure what these terms mean, check the Resources tab above.

Notes

Test input will always be appropriately formatted as either camelCase or snake_case, depending on the function being called.

*/
package main

import (
	"fmt"
	"unicode"
)

func main() {
	fmt.Println(snakecase("edabit"))
	fmt.Println(snakecase("helloEdabit"))
	fmt.Println(snakecase("isModalOpen"))
	fmt.Println(snakecase("getBackgroundColor"))
	fmt.Println(snakecase("isLoading"))
	fmt.Println(snakecase("x"))

	fmt.Println(camelcase("edabit"))
	fmt.Println(camelcase("hello_edabit"))
	fmt.Println(camelcase("is_modal_open"))
	fmt.Println(camelcase("get_background_color"))
	fmt.Println(camelcase("is_loading"))
	fmt.Println(camelcase("x"))
}

func camelcase(s string) string {
	p := ""
	u := false
	for _, r := range s {
		if r == '_' {
			u = true
			continue
		}
		if u {
			r = unicode.ToUpper(r)
			u = false
		}
		p += string(r)
	}
	return p
}

func snakecase(s string) string {
	p := ""
	for i, r := range s {
		if unicode.IsUpper(r) && i > 0 {
			p += "_" + string(unicode.ToLower(r))
		} else {
			p += string(r)
		}
	}
	return p
}
