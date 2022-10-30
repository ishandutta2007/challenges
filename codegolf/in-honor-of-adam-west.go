/*

Adam West passed away, and I'd like to honor his memory here on PPCG, though I doubt he knew of our existence.
While there are many, many different things that this man is known for, none are more prominent than his role as the original batman.
I'll always remember my step-father still watching the old-school Batman and Robin to this day.
This challenge is simplistic in nature, not at all in line with the complicated man that was Adam West.
However, it's the best I could come up with, as this is the most iconic image of the man's career.

I wanted to post this earlier, but I was waiting for someone to come up with something better.

Output the following (with or without trailing spaces/newlines):

           *                         *
       ****          *     *          ****
     ****            *******            ****
   ******            *******            ******
  *********         *********         *********
 ***********************************************
*************************************************
*************************************************
*************************************************
 ***********************************************
  *****       *********************       *****
    ****       ***    *****    ***       ****
       **       *      ***      *       **

This is code-golf, the lowest byte-count will win.

*/

package main

import "fmt"

func main() {
	fmt.Println(batman)
}

const batman = `
           *                         *
       ****          *     *          ****
     ****            *******            ****
   ******            *******            ******
  *********         *********         *********
 ***********************************************
*************************************************
*************************************************
*************************************************
 ***********************************************
  *****       *********************       *****
    ****       ***    *****    ***       ****
       **       *      ***      *       **
`
