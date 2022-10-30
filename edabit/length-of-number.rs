/*

Create a function that takes a number num and returns its length.
Examples

number_length(10) ➞ 2

number_length(5000) ➞ 4

number_length(0) ➞ 1

Notes

The use of the len() function is prohibited.

*/

fn main() {
    assert_eq!(number_length(10), 2);
    assert_eq!(number_length(5000), 4);
    assert_eq!(number_length(0), 1);
    assert_eq!(number_length(4039182), 7);
    assert_eq!(number_length(9999999999999999), 16);
    assert_eq!(number_length(1), 1);
    assert_eq!(number_length(777777777777777777777777777777), 30);
}

fn number_length(n: u128) -> usize {
    if n == 0 {
        return 1;
    }

    let mut l = 0;
    let mut x = n;
    while x != 0 {
        x /= 10;
        l += 1;
    }
    return l;
}
