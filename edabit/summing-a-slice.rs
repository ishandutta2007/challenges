/*

Given an array and an integer n, return the sum of the first n numbers in the array.
Examples

sliceSum([1, 3, 2], 2) ➞ 4

sliceSum([4, 2, 5, 7], 4) ➞ 18

sliceSum([3, 6, 2], 0) ➞ 0

Notes

If n is larger than the length of the array, return the sum of the whole array.

*/

use std::cmp;

fn main() {
    assert_eq!(sum(&vec![1, 3, 2], 2), 4);
    assert_eq!(sum(&vec![4, 2, 5, 7], 4), 18);
    assert_eq!(sum(&vec![3, 6, 2], 0), 0);
    assert_eq!(sum(&vec![2, 4], 9), 6);
    assert_eq!(sum(&vec![-5, 2], 2), -3);
    assert_eq!(sum(&vec![0, 0, 0, 3, 4], 2), 0);
}

fn sum(a: &Vec<isize>, n: usize) -> isize {
    return a[0..cmp::min(a.len(), n)].iter().sum();
}
