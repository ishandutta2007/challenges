/*

Fix the code in the code tab to pass this challenge (only syntax errors). Look at the examples below to get an idea of what the function should do.

Examples

cubes(3) ➞ 27

cubes(5) ➞ 125

cubes(10) ➞ 1000

Notes

    READ EVERY WORD CAREFULLY, CHARACTER BY CHARACTER!
    Don't overthink this challenge; it's not supposed to be hard.

*/

fn cubes(n: isize) -> isize {
    n*n*n
}

fn main() {
    assert_eq!(cubes(2), 8);
    assert_eq!(cubes(3), 27);
    assert_eq!(cubes(4), 64);
    assert_eq!(cubes(5), 125);
    assert_eq!(cubes(10), 1000);
}
