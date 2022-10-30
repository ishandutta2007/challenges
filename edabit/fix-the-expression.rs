/*

Fix the code in the Code tab so the function returns true if and only if x is equal to 7.

Examples

isSeven(4) ➞ false

isSeven(9) ➞ false

isSeven(7) ➞ true

Notes

The bug can be hard to find, so look closely!

*/

fn is_seven(n: isize) -> bool {
    return n == 7;
}

fn main() {
    assert_eq!(is_seven(4), false);
    assert_eq!(is_seven(9), false);
    assert_eq!(is_seven(7), true);
    assert_eq!(is_seven(10), false);
    assert_eq!(is_seven(20), false);
}
