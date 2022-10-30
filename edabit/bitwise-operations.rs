/*

A decimal number can be represented as a sequence of bits. To illustrate:

6 = 00000110
23 = 00010111

From the bitwise representation of numbers, we can calculate the bitwise AND, bitwise OR and bitwise XOR. Using the example above:

bitwiseAND(6, 23) ➞ 00000110

bitwiseOR(6, 23) ➞ 00010111

bitwiseXOR(6, 23) ➞ 00010001

Write three functions to calculate the bitwise AND, bitwise OR and bitwise XOR of two numbers.
Examples

bitwiseAND(7, 12) ➞ 4

bitwiseOR(7, 12) ➞ 15

bitwiseXOR(7, 12) ➞ 11

Notes

JavaScript has a useful function: toString(2), where you can see the binary representation of a decimal number.

*/

fn main() {
    assert_eq!(band(7, 12), 4);
    assert_eq!(bor(7, 12), 15);
    assert_eq!(bxor(7, 12), 11);

    assert_eq!(band(32, 17), 0);
    assert_eq!(bor(32, 17), 49);
    assert_eq!(bxor(32, 17), 49);

    assert_eq!(band(13, 19), 1);
    assert_eq!(bor(13, 19), 31);
    assert_eq!(bxor(13, 19), 30);
}

fn band(a: usize, b: usize) -> usize {
    a&b
}

fn bor(a: usize, b: usize) -> usize {
    a|b
}

fn bxor(a: usize, b: usize) -> usize {
    a^b
}
