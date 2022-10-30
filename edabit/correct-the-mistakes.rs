/*

Fix the code in the code tab to pass this challenge (only syntax errors). Look at the examples below to get an idea of what the function should do.

Examples

squared(5) ➞ 25

squared(9) ➞ 81

squared(100) ➞ 10000

Notes

    READ EVERY WORD CAREFULLY, CHARACTER BY CHARACTER!
    Don't overthink this challenge; it's not supposed to be hard.

*/

fn squared(n: isize) -> isize {
    n*n
}

fn main() {
    assert_eq!(squared(5), 25);
    assert_eq!(squared(9), 81);
    assert_eq!(squared(100), 10000);
    assert_eq!(squared(69), 4761);
    assert_eq!(squared(666), 443556);
    assert_eq!(squared(-21), 441);
    assert_eq!(squared(21), 441);
}
