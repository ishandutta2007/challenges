/*

Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).

*/

fn main() {
    println!("{}", hamming_weight(0b00000000000000000000000000001011));
    println!("{}", hamming_weight(0b00000000000000000000000010000000));
    println!("{}", hamming_weight(0b11111111111111111111111111111101));
}

fn hamming_weight(n: u32) -> isize {
    let mut v = n;
    let mut c = 0;
    while v != 0 {
        v &= v - 1;
        c += 1;
    }
    c
}
