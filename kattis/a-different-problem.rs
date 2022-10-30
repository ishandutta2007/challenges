/*

Write a program that computes the difference between non-negative integers.

Input

Each line of the input consists of a pair of integers.
Each integer is between 0 and 10^15 (inclusive).
The input is terminated by end of file.

Output

For each pair of integers in the input, output one line, containing the absolute value of their difference.

*/

fn main() {
    assert_eq!(absdiff(10, 12), 2);
    assert_eq!(absdiff(71293781758123, 72784), 71293781685339);
    assert_eq!(absdiff(1, 12345677654321), 12345677654320);
}

fn absdiff(x: i128, y: i128) -> i128 {
    (x - y).abs()
}
