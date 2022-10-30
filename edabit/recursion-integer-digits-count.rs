/*

Create a function that recursively counts the integer's number of digits.

Examples

count(318) ➞ 3

count(-92563) ➞ 5

count(4666) ➞ 4

count(-314890) ➞ 6

count(654321) ➞ 6

count(638476) ➞ 6

Notes

    You are expected to solve this challenge via recursion.
    You can check on the Resources tab for more details about recursion.
    A non-recursive version of this challenge can be found in here.

*/

fn main() {
    assert_eq!(count(318), 3);
    assert_eq!(count(-92563), 5);
    assert_eq!(count(4666), 4);
    assert_eq!(count(-314890), 6);
    assert_eq!(count(654321), 6);
    assert_eq!(count(638476), 6);
    assert_eq!(count(12345), 5);
    assert_eq!(count(1289396), 7);
    assert_eq!(count(-1232323), 7);
    assert_eq!(count(12839393), 8);
    assert_eq!(count(-231273683), 9);
    assert_eq!(count(0), 1);
}

fn count(n: isize) -> isize {
    return 1 + recurse(n/10);
}

fn recurse(n: isize) -> isize {
    if n == 0 {
        return 0;
    }
    return 1 + recurse(n/10);
}
