/*

Description :

Given a string of space separated binary digits or space separated booleans or an array of binary digits or array of booleans.
Your job is to find the xor of each until you end up with one answer either 0 or 1. The inputs will always be valid and will only be either 0 or 1.

Example:

1 0 0 1 0 --> 0
1 0 1 1 1 0 0 1 0 0 0 0 --> 1

This is code golf so shortest code will win. Good luck.

*/

fn main() {
    assert_eq!(xors(&[1, 0, 0, 1, 0]), 0);
    assert_eq!(xors(&[1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0]), 1);
}

fn xors(a: &[isize]) -> isize {
    let mut r = 0;
    for v in a {
        r ^= v;
    }
    r
}
