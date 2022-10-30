/*

No one is quite certain what the emoticon >:U is intended to represent, but many scholars believe it looks like an angry duck. Let's assume that's the case.

Task
Given an integer n between 0 and 3 inclusive, print or return

quack
if n = 0,

>:U
if n = 1,

     U   U
>  : U   U
 >   U   U
>  : U   U
      UUU
if n = 2, or

                  >:U         >:U
>:U               >:U         >:U
   >:U       >:U  >:U         >:U
      >:U         >:U         >:U
         >:U      >:U         >:U
      >:U         >:U         >:U
   >:U       >:U  >:U         >:U
>:U               >:U         >:U
                     >:U>:U>:U
if n = 3.

You can assume the input will always be valid. There should be no leading space in the output, but any amount of trailing space is fine.
Ducks (with the possible exception of @cobaltduck) have no tolerance for loopholes. Shortest code in bytes wins.

*/

package main

import "fmt"

func main() {
	for i := 0; i <= 3; i++ {
		quack(i)
	}
}

func quack(n int) {
	tab := []string{q0, q1, q2, q3}
	fmt.Println(tab[n&3])
}

const q0 = `quack`
const q1 = `>:U`

const q2 = `
     U   U
>  : U   U
 >   U   U
>  : U   U
      UUU`

const q3 = `
                  >:U         >:U
>:U               >:U         >:U
   >:U       >:U  >:U         >:U
      >:U         >:U         >:U
         >:U      >:U         >:U
      >:U         >:U         >:U
   >:U       >:U  >:U         >:U
>:U               >:U         >:U
                     >:U>:U>:U`
