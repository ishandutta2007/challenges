/*

Write a function that counts the number of times a specific digit occurs in a range (inclusive). The function will look like:

digit_occurrences(min, max, digit) ➞ number of times digit occurs
Examples
digit_occurrences(51, 55, 5) ➞ 6
# [51, 52, 53, 54, 55] : 5 occurs 6 times

digit_occurrences(1, 8, 9) ➞ 0

digit_occurrences(-8, -1, 8) ➞ 1

digit_occurrences(71, 77, 2) ➞ 1
Notes
Ranges can be negative.
min <= max

*/

fn main() {
    assert_eq!(digit_occurences(51, 55, 5), 6);
    assert_eq!(digit_occurences(1, 8, 9), 0);
    assert_eq!(digit_occurences(-8, -1, 8), 1);
    assert_eq!(digit_occurences(71, 77, 2), 1);
}

fn digit_occurences(min: isize, max: isize, digit: isize) -> isize {
    let mut c = 0;
    let mut i = min;
    while i <= max {
        let mut v = i.abs();
        while v != 0 {
            if v%10 == digit {
                c += 1;
            }
            v /= 10;
        }
        i += 1;
    }
    c
}
