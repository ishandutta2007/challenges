/*

Binary to decimal converter
As far as I can see, we don't have a simple binary to decimal conversion challenge.

Write a program or function that takes a positive binary integer and outputs its decimal value.

You are not allowed to use any builtin base conversion functions. Integer-to-decimal functions (e.g., a function that turns 101010 into [1, 0, 1, 0, 1, 0] or "101010") are exempt from this rule and thus allowed.

Rules:

The code must support binary numbers up to the highest numeric value your language supports (by default)
You may choose to have leading zeros in the binary representation
The decimal output may not have leading zeros.
Input and output formats are optional, but there can't be any separators between digits. (1,0,1,0,1,0,1,0) is not a valid input format, but both 10101010 and (["10101010"]) are.
You must take the input in the "normal" direction. 1110 is 14 not 7.
Test cases:

1
1

10
2

101010
42

1101111111010101100101110111001110001000110100110011100000111
2016120520371234567

This challenge is related to a few other challenges, for instance this, this and this.

*/

fn main() {
    assert_eq!(0b1, 1);
    assert_eq!(0b10, 2);
    assert_eq!(0b101010, 42);
    assert_eq!(0b1101111111010101100101110111001110001000110100110011100000111u128, 2016120520371234567u128);
}
