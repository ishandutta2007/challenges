/*

Write a function that takes a string as an argument and returns the left most digit in the string.
Examples

leftDigit("TrAdE2W1n95!") ➞ 2

leftDigit("V3r1ta$") ➞ 3

leftDigit("U//DertHe1nflu3nC3") ➞ 1

leftDigit("J@v@5cR1PT") ➞ 5

Notes

Each string will have at least two numbers.

*/

fn main() {
    assert_eq!(leftdigit("TrAdE2W1n95!"), 2);
    assert_eq!(leftdigit("V3r1ta$"), 3);
    assert_eq!(leftdigit("U//DertHe1nflu3nC3"), 1);
    assert_eq!(leftdigit("J@v@5cR1PT"), 5);
    assert_eq!(leftdigit("0nSlaUgh7*d3atH"), 0);
    assert_eq!(leftdigit("F8andD3st1nY"), 8);
}

fn leftdigit(s: &str) -> isize {
    for ch in s.chars() {
        if '0' <= ch && ch <= '9' {
            return ch as isize - '0' as isize;
        }
    }
    return -1;
}
