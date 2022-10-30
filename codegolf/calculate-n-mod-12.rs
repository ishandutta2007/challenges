/*

Calculate n modulo 12 for an unsigned 32 bit integer.

The Rules:
Must work for all n between 0 and 23. Other numbers optional.
Must only use any of the operators +-*, ~&^| or <<, >> as commonly defined on 32 bit uints.
May use arbitrary number of constant uints.
May not use any form of pointers, including arrays, or any if statements, including things that compile to if statements such as ternary operators or "greater than" operators.
The scoring:
Operators + - and the bitwise operators ~ & ^ | << >> (NOT, AND, XOR, OR, bit shifts) give a score of 1, * gives a score of 2.
Lowest total score wins.

*/

fn main() {
    for n in 0..100000 {
        assert_eq!(mod12(n), n % 12);
    }
}

fn mod12(mut n: usize) -> usize {
    while n >= 12 {
        n -= 12;
    }
    n
}
