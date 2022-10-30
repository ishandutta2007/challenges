/*

Today's challenge is to draw a binary tree as beautiful ascii-art like this example:

                               /\
                              /  \
                             /    \
                            /      \
                           /        \
                          /          \
                         /            \
                        /              \
                       /                \
                      /                  \
                     /                    \
                    /                      \
                   /                        \
                  /                          \
                 /                            \
                /                              \
               /\                              /\
              /  \                            /  \
             /    \                          /    \
            /      \                        /      \
           /        \                      /        \
          /          \                    /          \
         /            \                  /            \
        /              \                /              \
       /\              /\              /\              /\
      /  \            /  \            /  \            /  \
     /    \          /    \          /    \          /    \
    /      \        /      \        /      \        /      \
   /\      /\      /\      /\      /\      /\      /\      /\
  /  \    /  \    /  \    /  \    /  \    /  \    /  \    /  \
 /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\  /\
/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
You will be given a positive integer as input. This input is the height of the tree. The above example has a height of six.

You may submit either a full-program or a function, and you are free to use any of our default IO methods. For example, printing the tree, returning a string with newlines, returning a 2d char array, saving the tree to a file, etc. would all be allowed.

Trailing spaces on each line are permitted.

Here are some examples of inputs and their corresponding outputs:

1:
/\

2:
 /\
/\/\

3:
   /\
  /  \
 /\  /\
/\/\/\/\

4:
       /\
      /  \
     /    \
    /      \
   /\      /\
  /  \    /  \
 /\  /\  /\  /\
/\/\/\/\/\/\/\/\

5:
               /\
              /  \
             /    \
            /      \
           /        \
          /          \
         /            \
        /              \
       /\              /\
      /  \            /  \
     /    \          /    \
    /      \        /      \
   /\      /\      /\      /\
  /  \    /  \    /  \    /  \
 /\  /\  /\  /\  /\  /\  /\  /\
/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

Unfortunately, the output grows exponentially, so it's hard to show larger examples. Here is a link to the output for 8.
https://gist.githubusercontent.com/DJMcMayhem/77a25b711283bf844698edb032dc924c/raw/27bc2096f59d747882750064e29c0b64df74fb29/BinaryTree

As usual, this is a code-golf challenge, so standard loopholes apply, and try to write the shortest program possible in whatever language you choose.

Happy golfing!

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	for i := 1; i <= 5; i++ {
		tree(i)
	}
}

/*

@xnor

The idea is that each row of the output is a segment copied one or more times.
The half after the input split has one copy of each segment, the quarter after the next split has two copies, and so on, until the last line with many segments of /\.

Each segment had a / and \, with spaces in between, as well as on the outside to pad to the right length. The outer padding is done with center.

The variable s tracks the current with of each segment, and the number of segments is S/s so that the total width is the tree width S.
The line number i counts down by 2's, and whenever the value s is half of it, a split occurs, and the segment width halves.
This is done via the expression s/=s/i. When i reaches 0, this gives an error that terminates the program.

*/

func tree(n int) {
	fmt.Printf("N=%d\n", n)
	if n <= 0 {
		return
	}

	l := 1 << n
	i := l
	for c := l; c != 0; c /= (c / i) {
		s := "/" + strings.Repeat(" ", c-i) + "\\"
		s = center(s, c)
		s = strings.Repeat(s, l/c)
		fmt.Println(s)

		if i -= 2; i == 0 {
			break
		}
	}
	fmt.Println()
}

func center(s string, n int) string {
	m := len(s)
	if m >= n {
		return s
	}
	p := strings.Repeat(" ", (n-m)/2)
	return p + s + p
}
