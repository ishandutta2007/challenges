/*

Task: convert a HTML page into a mountain!

When HTML pages are indented, they can look like:

<div>
    <div>
        <div>
        </div>
        <div>
            <div>
            </div>
        </div>
    </div>
</div>
But to be honest, a mountain is more representative of this structure.

So we can rewrite it as:

     /\
  /\/  \
 /      \
/        \
The outermost slashes on the left and right correspond to the outer div - each pair of HTML tags should be represented as / for the starting tag and \ for the ending tag - inside all tags are "higher", with the same structure.

Input:

There will be no <!DOCTYPE>
There will be no self-closing tags e.g. <img /> or <br />
There may be attributes or content inside the tags
There may be spaces or tabs - your program should ignore these
There will be no spaces between < or </ and the tag name
All input will be valid HTML
Output - a mountain representing the tags as above.

More testcases:

Input:

<div id="123"> HI </div><a><span></span></a>
Output:

   /\
/\/  \
Input:

<body id="<"></body>
Output:

/\

*/

package main

import (
	"fmt"
	"strings"

	"golang.org/x/net/html"
)

func main() {
	mountain(`<div><div><div></div><div><div></div></div></div></div>`)
	mountain(`<div id="123"> HI </div><a><span></span></a>`)
	mountain(`<body id="<"></body>`)
}

func mountain(s string) {
	r := strings.NewReader(s)
	z := html.NewTokenizer(r)
	m := make(map[[2]int]int)

	var w, h, y int
	for {
		t := z.Next()
		if t == html.ErrorToken {
			break
		}

		switch t {
		case html.StartTagToken:
			p := [2]int{w, y}
			m[p] = 1
			y += 1
			h = max(h, y)
		case html.EndTagToken:
			y -= 1
			p := [2]int{w, y}
			m[p] = 2
		case html.SelfClosingTagToken:
			p := [2]int{w, y}
			m[p] = 3
		}
		w += 1
	}

	for y := h - 1; y >= 0; y-- {
		for x := 0; x < w; x++ {
			p := [2]int{x, y}
			switch m[p] {
			case 1:
				fmt.Printf("/")
			case 2:
				fmt.Printf("\\")
			case 3:
				fmt.Printf("_")
			default:
				fmt.Printf(" ")
			}
		}
		fmt.Println()
	}
	fmt.Println()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
