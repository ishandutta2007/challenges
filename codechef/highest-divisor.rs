/*

You are given an integer N. Find the largest integer between 1 and 10 (inclusive) which divides N.

Input

The first and only line of the input contains a single integer N.

Output

Print a single line containing one integer ― the largest divisor of N between 1 and 10.

Constraints
2≤N≤1,000

*/

fn main() {
    assert_eq!(divisor(24), 8);
    assert_eq!(divisor(91), 7);
    assert_eq!(divisor(1), 1);
}

fn divisor(n: isize) -> isize {
    let mut i = 10;
    while n%i != 0 {
        i -= 1;
    }
    i
}
