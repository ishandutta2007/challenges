/*

Given an index and an array, return the value of the array with the given index.
Examples

valueAt([1, 2, 3, 4, 5, 6], 10 / 2) ➞ 6

valueAt([1, 2, 3, 4, 5, 6], 8.0 / 2) ➞ 5

valueAt([1, 2, 3, 4], 6.535355314 / 2) ➞ 4

Notes

Math.floor() can be helpful.

*/

fn at(x: Vec<isize>, i: usize) -> isize {
    return x[i];
}

fn main() {
    assert_eq!(at(vec![1, 2, 3, 4, 5, 6], 10/2), 6);
    assert_eq!(at(vec![1, 2, 3, 4, 5, 6], (8.0/2.0) as usize), 5);
    assert_eq!(at(vec![1, 2, 3, 4], (6.535355314/2.0) as usize), 4);
    assert_eq!(at(vec![1, 2], (1.0/2.0) as usize), 1);
}
