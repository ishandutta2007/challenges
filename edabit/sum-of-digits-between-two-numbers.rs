/*

Create a function that sums the total number of digits between two numbers, inclusive. For example, between the numbers 19 and 22 we have:

// 19, 20, 21, 22
(1 + 9) + (2 + 0) + (2 + 1) + (2 + 2) = 19

Examples

sumDigits(7, 8) ➞ 15

sumDigits(17, 20) ➞ 29

sumDigits(10, 12) ➞ 6

Notes

N/A

*/

fn main() {
    assert_eq!(sum(7, 8), 15);
    assert_eq!(sum(17, 20), 29);
    assert_eq!(sum(10, 12), 6);
    assert_eq!(sum(500, 506), 56);
    assert_eq!(sum(66, 789), 9324);
}

fn sum(n: usize, m: usize) -> usize {
    let mut r = 0;
    for i in n..m+1 {
        r += tally(i); 
    }
    return r;
}

fn tally(mut n: usize) -> usize {
    let mut r = 0;
    while n != 0 {
        r += n % 10;
        n /= 10;
    }
    return r;
}
