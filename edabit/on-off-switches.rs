/*

Create a function that returns how many possible outcomes can come from a certain number of switches (on / off).
Examples

posCom(1) ➞ 2

posCom(3) ➞ 8

posCom(10) ➞ 1024

Notes

All numbers will be whole and positive.

*/

fn main() {
    assert_eq!(poscom(5), 32);
    assert_eq!(poscom(4), 16);
    assert_eq!(poscom(3), 8);
    assert_eq!(poscom(2), 4);
    assert_eq!(poscom(1), 2);
    assert_eq!(poscom(6), 64);
    assert_eq!(poscom(7), 128);
    assert_eq!(poscom(8), 256);
    assert_eq!(poscom(9), 512);
    assert_eq!(poscom(10), 1024);
    assert_eq!(poscom(25), 33554432);
}

fn poscom(n: usize) -> usize {
    1 << n
}
