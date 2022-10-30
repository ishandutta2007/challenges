/*

Create a function that takes two vectors as arrays and checks if the two vectors are orthogonal or not. The return value is boolean. Two vectors a and b are orthogonal if their dot product is equal to zero.
Examples

isOrthogonal([1, 2], [2, -1]) ➞ true

isOrthogonal([3, -1], [7, 5]) ➞ false

isOrthogonal([1, 2, 0], [2, -1, 10]) ➞ true

Notes

    The two arrays will be of same length.
    Check out the Resources tab.

*/

fn main() {
    assert_eq!(isorthogonal(&vec![1, 2], &vec![2, -1]), true);
    assert_eq!(isorthogonal(&vec![3, -1], &vec![7, 5]), false);
    assert_eq!(isorthogonal(&vec![1, 2, 0], &vec![2, -1, 10]), true);
    assert_eq!(isorthogonal(&vec![7, 8], &vec![7, -6]), false);
    assert_eq!(isorthogonal(&vec![-13, -26], &vec![-8, 4]), true);
    assert_eq!(isorthogonal(&vec![2, 4, 1], &vec![2, 1, -8]), true);
    assert_eq!(isorthogonal(&vec![1, 2, 0], &vec![2, -1, 10]), true);
    assert_eq!(isorthogonal(&vec![3, 8, 9], &vec![16, 17, -18]), false);
}

fn isorthogonal(a: &Vec<isize>, b: &Vec<isize>) -> bool {
    assert_eq!(a.len(), b.len());
    let mut v = 0;
    for i in 0..a.len() {
        v += a[i]*b[i];
    }
    return v == 0;
}
