/*

Write a full program to find whether the binary representation of a number is palindrome or not?

Sample Input
5

Sample Output
YES
Print YES if binary representation is palindrome and NO otherwise.

*/

fn main() {
    assert_eq!(palindrome(5), true);
    assert_eq!(palindrome(3), true);
    assert_eq!(palindrome(1), true);
    assert_eq!(palindrome(354), false);
}

fn palindrome(x: usize) -> bool {
    let s = format!("{:b}", x);
    let t = s.chars().rev().collect::<String>();
    s == t
}
