/*

Create a function that validates whether three given integers form a Pythagorean triplet. The sum of the squares of the two smallest integers must equal the square of the largest number to be validated.
Examples

isTriplet(3, 4, 5) ➞ true
// 3² + 4² = 25
// 5² = 25

isTriplet(13, 5, 12) ➞ true
// 5² + 12² = 169
// 13² = 169

isTriplet(1, 2, 3) ➞ false
// 1² + 2² = 5
// 3² = 9

Notes

Numbers may not be given in a sorted order.

*/

fn main() {
    assert_eq!(pythagorean_triplet(3, 4, 5), true);
    assert_eq!(pythagorean_triplet(1, 2, 3), false);
    assert_eq!(pythagorean_triplet(3, 18, 8), false);
    assert_eq!(pythagorean_triplet(7, 12, 7), false);
    assert_eq!(pythagorean_triplet(13, 5, 12), true);
    assert_eq!(pythagorean_triplet(12, 20, 18), false);
    assert_eq!(pythagorean_triplet(17, 14, 2), false);
    assert_eq!(pythagorean_triplet(6, 15, 12), false);
    assert_eq!(pythagorean_triplet(60, 61, 11), true);
    assert_eq!(pythagorean_triplet(7, 13, 15), false);
    assert_eq!(pythagorean_triplet(12, 18, 7), false);
    assert_eq!(pythagorean_triplet(8, 17, 15), true);
    assert_eq!(pythagorean_triplet(3120, 79, 3121), true);
}

fn pythagorean_triplet(a: usize, b: usize, c: usize) -> bool {
    let mut v = [a, b, c];
    v.sort();
    v[0]*v[0] + v[1]*v[1] == v[2]*v[2]
}

