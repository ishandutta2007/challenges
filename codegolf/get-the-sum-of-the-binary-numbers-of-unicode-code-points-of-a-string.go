/*

Yeah... it's confusing. Let me explain it a little better:

    With a string, get the unicode code points of each letter
        Let's use "Hello World!".
        The code points would be [72, 101, 108, 108, 111, 32, 87, 111, 114, 108, 100, 33]
    Of each digit of the code points, get their binary format
        Get the binary of 7, then 2, then 1, then 0, and so on...
        ['111', '10', '1', '0', '1', '1', '0', '1000', ...]
    The binary integers are treated as decimal and summed, and that's the result.
        Take the integer of the binary (e.g. '111' is the integer 111 in decimal; one hundred and one) then sum all of these integers.
        The result of "Hello World!" would be 4389.

Test Cases

"Hello World!" -> 4389
"Foo Bar!" -> 1594
"Code Golf" -> 1375
"Stack Exchange" -> 8723
"Winter Bash" -> 2988

Shortest code in bytes wins!

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	assert(sum("Hello World!") == 4389)
	assert(sum("Foo Bar!") == 1594)
	assert(sum("Code Golf") == 1375)
	assert(sum("Stack Exchange") == 8723)
	assert(sum("Winter Bash") == 2988)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sum(s string) int {
	t := 0
	for _, v := range s {
		for ; v != 0; v /= 10 {
			b := fmt.Sprintf("%b", v%10)
			n, _ := strconv.Atoi(b)
			t += n
		}
	}
	return t
}
