/*

Write a program or function that prints or outputs this exact text (consisting of 142 characters):

()()()()()()
|\3.1415926|
|:\53589793|
\::\2384626|
 \::\433832|
  \::\79502|
   \::\8841|
    \::\971|
     \::\69|
      \::\3|
       \__\|

Your program must take no input (except in languages where this is impossible, such as sed), and produce the above text (and only the above text) as output. A trailing newline is acceptable.

This is code-golf, so the shortest answer (in bytes) wins.

*/

package main

import "fmt"

func main() {
	fmt.Println(pie)
}

const pie = `
()()()()()()
|\3.1415926|
|:\53589793|
\::\2384626|
 \::\433832|
  \::\79502|
   \::\8841|
    \::\971|
     \::\69|
      \::\3|
       \__\|
`
