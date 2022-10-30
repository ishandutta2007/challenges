/*

Starting with either 3 or 5 and given these operations:

    add 5
    multiply by 3

You should say if it is possible to reach the target number n.
Examples

only_5_and_3(14) ➞ True
# 14 = 3*3 + 5

only_5_and_3(25) ➞ True
# 25 = 5+5+5+5+5

only_5_and_3(7) ➞ False
# There exists no path to the target number 7

Notes

You can solve this problem by recursion or algebra.

*/

fn main() {
    assert_eq!(only5and3(14), true);
    assert_eq!(only5and3(25), true);
    assert_eq!(only5and3(7), false);
    assert_eq!(only5and3(2), false);
    assert_eq!(only5and3(43), true);
    assert_eq!(only5and3(33), true);
    assert_eq!(only5and3(51), false);
    assert_eq!(only5and3(91), true);
    assert_eq!(only5and3(378), true);
    assert_eq!(only5and3(627), true);
}

fn only5and3(n: usize) -> bool {
    return only5and3rec(n, 3) || only5and3rec(n, 5);
}

fn only5and3rec(n: usize, v: usize) -> bool {
    if v > n {
        return false;
    }
    if n == v {
        return true;
    }
    return only5and3rec(n, v*3) || only5and3rec(n, v+5);
}
