/*

Task

Given an input string of one or more ASCII characters which codepoints are between 0 and 128 (exclusive), do the following:

    Convert each character into its 7-bit ASCII code (if the ASCII code is less than 7 bits, put leading zero bits)
    Concatenate all bits (this results in 7*n bits where n is the number of characters)
    For each bit in this bitstream, print 1 if it is different from the previous bit, and print 0 otherwise. The first output bit is always 1.

Example

Input:

Hi

Output:

11011001011101

Explanation:

    The string "Hi" has the ASCII codes

    72 105

    which in bits are:

    1001000 1101001

    And the transition bits indicators:

    11011001011101

This is code golf. Lowest byte count wins.
Test Cases

Test case 1:

Hello World!
110110010101110011010101101010110001110000111110000110000001011101101010101100110001

Test case 2:

%% COMMENT %%
1110111111011111100001100010010100001010110101011010011101010011111110011000001101111110111

Test case 3 (credit to Luis Mendo):

##
11100101110010

Congrats to Luis Mendo for the shortest solution with 9 bytes in MATL!

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(translate("Hi") == "11011001011101")
	assert(translate("Hello World!") == "110110010101110011010101101010110001110000111110000110000001011101101010101100110001")
	assert(translate("%% COMMENT %%") == "1110111111011111100001100010010100001010110101011010011101010011111110011000001101111110111")
	assert(translate("##") == "11100101110010")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func translate(s string) string {
	return transition(binary(s))
}

func binary(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		fmt.Fprintf(w, "%07b", r)
	}
	return w.String()
}

func transition(s string) string {
	w := new(bytes.Buffer)
	lr := rune(-1)
	for _, r := range s {
		if lr != r {
			lr = r
			fmt.Fprint(w, 1)
		} else {
			fmt.Fprint(w, 0)
		}
	}
	return w.String()
}
