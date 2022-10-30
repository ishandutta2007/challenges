/*

I am interested in seeing programs which don't ask for any input, print a googol copies of some nonempty string, no less, no more, and then stop. A googol is defined as 10100, i.e., 1 followed by a hundred 0's in decimal.

Example output:

111111111111111111111111111111111111111111111111111111111111111111111111...
or

Hello world
Hello world
Hello world
Hello world
Hello world
Hello world
...
The string can also be entirely composed of white space or special symbols. The only exception to identical copies of a fixed string is if your language decorates the output in some way that can not be prevented,
but could be trivially undone in a wrapper script, like prepending a line number to each line. The wrapper script in such cases need not be provided.

You can assume your computer will never run out of time, but other than that, your program must have a reasonable demand of resources.
Also, you must respect any restrictions that the programming language of your choice poses, for example, you can not exceed a maximum value allowed for its integer types, and at no point more than 4 GB of memory must be needed.

In other words, the program should in principle be testable by running it on your computer.
But because of the extent of this number you will be expected to prove that the number of copies of the string it outputs is exactly 10^100 and that the program stops afterwards.
Stopping can be exiting or halting or even terminating due to an error, but if so, the error must not produce any output that could not easily be separated from the program's output.

This is code-golf, so the solution with the fewest bytes wins.

Example solution (C, ungolfed, 3768 bytes)
#include <stdio.h>

int main() {
  int a00, a01, a02, a03, ..., a99;
  for(a00 = 0; a00 < 10; a00++)
  for(a01 = 0; a01 < 10; a01++)
  for(a02 = 0; a02 < 10; a02++)
  for(a03 = 0; a03 < 10; a03++)
  ...
  for(a99 = 0; a99 < 10; a99++)
    puts("1");
  return 0;
}

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	googol("Hello world")
}

func googol(s string) {
	var (
		one     = big.NewInt(1)
		hundred = big.NewInt(100)
	)

	n := big.NewInt(0)
	m := big.NewInt(10)
	m.Exp(m, hundred, nil)
	for n.Cmp(m) != 0 {
		fmt.Println(s)
		n.Add(n, one)
	}
}
