/*

The impossible has happened. Bear G. has fallen into his own trap. Lured by a delicious box of Domaćica, without even thinking, he rushed and fell into his trap.
In order to get out of the trap, he must solve the following task with your help. You are given three integers L, D and X.

    determine the minimal integer N such that L≤N≤D and the sum of its digits is X
    determine the maximal integer M such that L≤M≤D and the sum of its digits is X

Bear will be able to escape from the trap if he correctly determines numbers N and M. The numbers N and M will always exist.

Input

The first line of input contains the integer L (1≤L≤10000), the number from the task.
The second line of input contains the integer D (1≤D≤10000, L≤D), the number from the task.
The third line of input contains the integer X (1≤X≤36), the number from the task.

Output

The first line of output must contain the integer N from the task. The second line of output must contain the integer M from the task.

*/

use std::cmp::*;

fn main() {
    assert_eq!(find(1, 100, 4), (4, 40));
    assert_eq!(find(100, 500, 12), (129, 480));
    assert_eq!(find(1, 10000, 1), (1, 10000));
}

fn find(l: isize, d: isize, x: isize) -> (isize, isize) {
    let (mut n, mut m) = (isize::MAX, isize::MIN);
    for i in l..d+1 {
        if digit_sum(i) == x {
            n = min(n, i);
            m = max(m, i);
        }
    }
    (n, m)
}

fn digit_sum(mut x: isize) -> isize {
    let mut r = 0;
    while x != 0 {
        r += x % 10;
        x /= 10;
    }
    r
}
