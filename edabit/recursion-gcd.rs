/*

Write a function that calculates the GCD (Greatest Common Divisor) of two numbers recursively.
Examples

gcd(10, 20) ➞ 10

gcd(1, 3) ➞ 1

gcd(5, 7) ➞ 1

gcd(2, 6) ➞ 2

*/

fn main() {
    assert_eq!(gcd(10, 20), 10);
    assert_eq!(gcd(1, 3), 1);
    assert_eq!(gcd(5, 7), 1);
    assert_eq!(gcd(2, 6), 2);
    assert_eq!(gcd(13, 39), 13);
    assert_eq!(gcd(50, 5), 5);
    assert_eq!(gcd(70, 35), 35);
    assert_eq!(gcd(100, 8), 4);
    assert_eq!(gcd(11, 45), 1);
}

fn gcd(a: usize, b: usize) -> usize {
    if a == b {
        return a;
    }
    if a > b {
        return gcd(a-b, b);
    }
    return gcd(a, b-a);
}
