/*

Your task is to print this exact text:

            z
            yz
           xyz
           wxyz
          vwxyz
          uvwxyz
         tuvwxyz
         stuvwxyz
        rstuvwxyz
        qrstuvwxyz
       pqrstuvwxyz
       opqrstuvwxyz
      nopqrstuvwxyz
      mnopqrstuvwxyz
     lmnopqrstuvwxyz
     klmnopqrstuvwxyz
    jklmnopqrstuvwxyz
    ijklmnopqrstuvwxyz
   hijklmnopqrstuvwxyz
   ghijklmnopqrstuvwxyz
  fghijklmnopqrstuvwxyz
  efghijklmnopqrstuvwxyz
 defghijklmnopqrstuvwxyz
 cdefghijklmnopqrstuvwxyz
bcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz

Case does not matter.

Remember, this is code-golf, so the code with the smallest number of bytes wins.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	partyhat()
}

func partyhat() {
	var s string
	for i := 26; i > 0; i-- {
		s = fmt.Sprintf("%c%s", 'a'+i-1, s)
		fmt.Printf("%s%s\n", strings.Repeat(" ", (i-1)/2), s)
	}
}
