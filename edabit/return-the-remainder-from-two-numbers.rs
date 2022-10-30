/*

There is a single operator in JavaScript, capable of providing the remainder of a division operation. Two numbers are passed as parameters. The first parameter divided by the second parameter will have a remainder, possibly zero. Return that value.
Examples

remainder(1, 3) ➞ 1

remainder(3, 4) ➞ 3

remainder(-9, 45) ➞ -9

remainder(5, 5) ➞ 0

Notes

    The tests only use positive and negative integers.
    Don't forget to return the result.
    If you get stuck on a challenge, find help in the Resources tab.
    If you're really stuck, unlock solutions in the Solutions tab.

*/

fn main() {
    assert_eq!(remainder(1, 3), 1);
    assert_eq!(remainder(3, 4), 3);
    assert_eq!(remainder(-9, 45), -9);
    assert_eq!(remainder(5, 5), 0);
}

fn remainder(x: isize, y: isize) -> isize {
    x % y
}
