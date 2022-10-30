/*

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 2^31.

*/

use std::mem;

fn main() {
	println!("{}", hamming_distance(1, 4));
	println!("{}", hamming_distance(0x7, 0x10));
	println!("{}", hamming_distance(0, 0xffffffff));
	println!("{}", hamming_distance(3, 3));
}

fn hamming_distance(x: u32, y: u32) -> isize {
	let mut b = 0;
	for i in 0..mem::size_of_val(&x)*8 {
		if x&(1<<i) != y&(1<<i) {
			b += 1;
		}
	}
	b
}
