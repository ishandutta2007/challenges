/*

Create a function that takes two arguments. Both arguments are integers, a and b.
Return true if one of them is 10 or if their sum is 10.

Examples

makes10(9, 10) ➞ true

makes10(9, 9) ➞ false

makes10(1, 9) ➞ true

Notes

Don't forget to return the result.

*/

fn makes10(a: isize, b: isize) -> bool {
    a == 10 || b == 10 || a+b == 10
}

fn main() {
    assert_eq!(makes10(9, 10), true);
    assert_eq!(makes10(9, 9), false);
    assert_eq!(makes10(1, 9), true);
    assert_eq!(makes10(10, 1), true);
    assert_eq!(makes10(10, 10), true);
    assert_eq!(makes10(8, 2), true);
    assert_eq!(makes10(8, 3), false);
    assert_eq!(makes10(10, 42), true);
    assert_eq!(makes10(12, -2), true);
}
