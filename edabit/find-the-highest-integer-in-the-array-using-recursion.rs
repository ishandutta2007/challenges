/*

Create a function that finds the highest integer in the array using recursion.

Examples

findHighest([-1, 3, 5, 6, 99, 12, 2]) ➞ 99

findHighest([0, 12, 4, 87]) ➞ 87

findHighest([6,7,8]) ➞ 8

Notes

Please use the recursion to solve this (not the max() method).

*/

use std::cmp::max;

fn find_highest(a: &[isize]) -> isize {
    if a.len() == 0 {
        return isize::MIN;
    }
    return max(a[0], find_highest(&a[1..]));
}

fn main() {
    let a1 = [-1, 3, 5, 6, 99, 12, 2];
    let a2 = [0, 12, 4, 87];
    let a3 = [6, 7, 8];

    assert_eq!(find_highest(&a1), 99);
    assert_eq!(find_highest(&a2), 87);
    assert_eq!(find_highest(&a3), 8);
}
