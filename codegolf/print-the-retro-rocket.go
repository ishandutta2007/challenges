/*

(inspired by this SO question)
https://stackoverflow.com/questions/26247602/nested-for-loop-art

You are given as input a single positive integer n.

In as few characters as possible, output a rocket in ASCII art with a head, a tail, and a body composed of n segments. There should be no trailing spaces or newlines.

The head and the tail of the rocket are always the same for any value of n. The body consists of two different types of segments which alternate. The examples should make the structure of the rocket clear.

Output for n = 1:

     /**\
    //**\\
   ///**\\\
  ////**\\\\
 /////**\\\\\
+=*=*=*=*=*=*+
|\/\/\/\/\/\/|
|.\/\/..\/\/.|
|..\/....\/..|
|../\..../\..|
|./\/\../\/\.|
|/\/\/\/\/\/\|
+=*=*=*=*=*=*+
     /**\
    //**\\
   ///**\\\
  ////**\\\\
 /////**\\\\\
Output for n = 2:

     /**\
    //**\\
   ///**\\\
  ////**\\\\
 /////**\\\\\
+=*=*=*=*=*=*+
|../\..../\..|
|./\/\../\/\.|
|/\/\/\/\/\/\|
|\/\/\/\/\/\/|
|.\/\/..\/\/.|
|..\/....\/..|
+=*=*=*=*=*=*+
|\/\/\/\/\/\/|
|.\/\/..\/\/.|
|..\/....\/..|
|../\..../\..|
|./\/\../\/\.|
|/\/\/\/\/\/\|
+=*=*=*=*=*=*+
     /**\
    //**\\
   ///**\\\
  ////**\\\\
 /////**\\\\\
Output for n = 3:

     /**\
    //**\\
   ///**\\\
  ////**\\\\
 /////**\\\\\
+=*=*=*=*=*=*+
|\/\/\/\/\/\/|
|.\/\/..\/\/.|
|..\/....\/..|
|../\..../\..|
|./\/\../\/\.|
|/\/\/\/\/\/\|
+=*=*=*=*=*=*+
|../\..../\..|
|./\/\../\/\.|
|/\/\/\/\/\/\|
|\/\/\/\/\/\/|
|.\/\/..\/\/.|
|..\/....\/..|
+=*=*=*=*=*=*+
|\/\/\/\/\/\/|
|.\/\/..\/\/.|
|..\/....\/..|
|../\..../\..|
|./\/\../\/\.|
|/\/\/\/\/\/\|
+=*=*=*=*=*=*+
     /**\
    //**\\
   ///**\\\
  ////**\\\\
 /////**\\\\\

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	rocket(1)
	rocket(2)
	rocket(3)
}

func rocket(n int) {
	t := 1 - (n & 1)
	outnl(HEAD)
	for i := 0; i < n; i++ {
		switch t {
		case 0:
			outnl(BODY1)
		default:
			outnl(BODY2)
		}
		if i+1 < n {
			fmt.Println(SEP)
		}
		t = 1 - t
	}
	outnl(TAIL)
	fmt.Println()
}

func outnl(s string) string {
	i := strings.IndexRune(s, '\n')
	if i >= 0 {
		s = s[i+1:]
	}
	fmt.Println(s)
	return s
}

const HEAD = `
     /**\
    //**\\
   ///**\\\
  ////**\\\\
 /////**\\\\\
+=*=*=*=*=*=*+`

const BODY1 = `
|\/\/\/\/\/\/|
|.\/\/..\/\/.|
|..\/....\/..|
|../\..../\..|
|./\/\../\/\.|
|/\/\/\/\/\/\|`

const BODY2 = `
|../\..../\..|
|./\/\../\/\.|
|/\/\/\/\/\/\|
|\/\/\/\/\/\/|
|.\/\/..\/\/.|
|..\/....\/..|`

const SEP = `+=*=*=*=*=*=*+`

const TAIL = `
+=*=*=*=*=*=*+
     /**\
    //**\\
   ///**\\\
  ////**\\\\
 /////**\\\\\`
