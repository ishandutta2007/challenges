/*

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:

    The given integer is guaranteed to fit within the range of a 32-bit signed integer.
    You could assume no leading zero bit in the integer’s binary representation.

*/
fn main() {
    println!("{}", complement(5));
    println!("{}", complement(1));
    println!("{}", complement(0));
    println!("{}", complement(128));
    println!("{}", complement(513));
}

fn complement(x: u32) -> u32 {
    !x & ((1 << (32 - x.leading_zeros())) - 1)
}
