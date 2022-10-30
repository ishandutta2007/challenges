/*

Write a function that finds the sum of an array. Make your function recursive.
Examples

sum([1, 2, 3, 4]) ➞ 10

sum([1, 2]) ➞ 3

sum([1]) ➞ 1

sum([]) ➞ 0

Notes

    Return 0 for an empty array.
    Check the Resources tab for info on recursion.

*/

fn main() {
    assert_eq!(sum(&vec![1, 2, 3, 4]), 10);
    assert_eq!(sum(&vec![-1, -1, -1]), -3);
    assert_eq!(sum(&vec![1]), 1);
    assert_eq!(sum(&vec![]), 0);
}

fn sum(v: &[isize]) -> isize {
    if v.len() == 0 {
        return 0;
    }
    return v[0] + sum(&v[1..v.len()]);
}
