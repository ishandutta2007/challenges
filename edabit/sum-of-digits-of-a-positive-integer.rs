/*

An instructor has given her student an assignment to calculate the sum of the digits of a positive integer using recursion.
The student came up with the solution but the solution does not seem to be correct. Help her fix the error.

Examples

sumDigit(111) ➞ 3
// 1 + 1 + 1 = 3

sumDigit(222) ➞ 6
// 2 + 2 + 2 = 6

sumDigit(333) ➞ 9
// 3 + 3 + 3 = 9

Notes

Input is a positive integer.

*/

fn sum_digit(n: usize) -> usize {
    if n == 0 {
        return 0;
    }
    return n%10 + sum_digit(n/10);
}

fn main() {
    assert_eq!(sum_digit(111), 3);
    assert_eq!(sum_digit(222), 6);
    assert_eq!(sum_digit(333), 9);
    assert_eq!(sum_digit(444), 12);
    assert_eq!(sum_digit(555), 15);
    assert_eq!(sum_digit(666), 18);
    assert_eq!(sum_digit(777), 21);
    assert_eq!(sum_digit(888), 24);
    assert_eq!(sum_digit(999), 27);
    assert_eq!(sum_digit(1111), 4);
}
