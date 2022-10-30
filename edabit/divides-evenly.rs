/*

Given two integers, a and b, return true if a can be divided evenly by b. Return false otherwise.
Examples

dividesEvenly(98, 7) ➞ true
# 98/7 = 14

dividesEvenly(85, 4) ➞ false
# 85/4 = 21.25

Notes

a will always be greater than or equal to b.

*/

fn main() {
    assert_eq!(divisible(98, 7), true);
    assert_eq!(divisible(87, 49), false);
    assert_eq!(divisible(34, 14), false);
    assert_eq!(divisible(78, 6), true);
    assert_eq!(divisible(30, 4), false);
    assert_eq!(divisible(87, 73), false);
    assert_eq!(divisible(74, 7), false);
    assert_eq!(divisible(87, 29), true);
    assert_eq!(divisible(48, 24), true);
    assert_eq!(divisible(99, 20), false);
    assert_eq!(divisible(98, 49), true);
    assert_eq!(divisible(100, 6), false);
    assert_eq!(divisible(64, 4), true);
    assert_eq!(divisible(70, 35), true);
    assert_eq!(divisible(38, 38), true);
    assert_eq!(divisible(29, 3), false);
    assert_eq!(divisible(20, 8), false);
    assert_eq!(divisible(66, 50), false);
    assert_eq!(divisible(95, 1), true);
    assert_eq!(divisible(58, 2), true);
}

fn divisible(a: usize, b: usize) -> bool {
    if b == 0 {
        return false;
    }
    return a%b == 0;
}
