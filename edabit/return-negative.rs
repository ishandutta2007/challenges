/*

Create a function that takes a number as an argument and returns negative of that number. Return negative numbers without any change.

Examples

returnNegative(4) ➞ -4

returnNegative(15) ➞ -15

returnNegative(-4) ➞ -4

returnNegative(0) ➞ 0

Notes

N/A

*/

fn neg(x: isize) -> isize {
    if x > 0 {
        return -x;
    }
    return x;
}

fn main() {
    assert_eq!(neg(4), -4);
    assert_eq!(neg(15), -15);
    assert_eq!(neg(-4), -4);
    assert_eq!(neg(0), 0);
    assert_eq!(neg(212), -212);
    assert_eq!(neg(-125), -125);
    assert_eq!(neg(932123), -932123);
}
