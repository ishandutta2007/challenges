/*

Given an integer n > 0, output the length of the longest contiguous sequence of 0 or 1 in its binary representation.

Examples

    6 is written 110 in binary; the longest sequence is 11, so we should return 2
    16 → 10000 → 4
    893 → 1101111101 → 5
    1337371 → 101000110100000011011 → 6
    1 → 1 → 1
    9965546 → 100110000000111111101010 → 7

*/

use std::cmp::max;

fn main() {
    assert_eq!(rundown(6), 2);
    assert_eq!(rundown(16), 4);
    assert_eq!(rundown(893), 5);
    assert_eq!(rundown(1337371), 6);
    assert_eq!(rundown(1), 1);
    assert_eq!(rundown(9965546), 7);
}

fn rundown(mut x: usize) -> isize {
    let (mut b, mut c, mut r) = (0, 0, 1);
    while x != 0 {
        let v = x & 1;
        if v != b {
            b = v;
            c = 1;
        } else {
            c += 1;
        }
        x >>= 1;
        
        r = max(r, c);
    }
    r
}
