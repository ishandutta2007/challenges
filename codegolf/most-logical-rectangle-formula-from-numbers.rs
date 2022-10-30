/*

Introduction
The task is simple. When given a number, output the most logical rectangle. To explain what a logical rectangle is, I provided some examples:

Input: 24.

All possible rectangles have the form A x B, (A and B are both positive integers). So, all possible rectangles for 24 are:

1 x 24
2 x 12
4 x 6
From this list, the most logical rectangle has the lowest A + B:

1 + 24 = 25
2 + 12 = 14
4 + 6 = 10
You can see that 4 x 6 is the most logical rectangle, so we will output 4 x 6 (or 6 x 4).

The rules
Given an integer from 1 to 99999, output the most logical rectangle.
You may write a function or a program.
The spaces in the output are not required.
This is code-golf, so the submission with the least amount of bytes wins!
Test cases
Input >   Output

1     >   1 x 1
4     >   2 x 2
8     >   4 x 2 (or 2 x 4)
15    >   5 x 3 (or 3 x 5)
47    >   1 x 47 (or 47 x 1)
5040  >   72 x 70 (or 70 x 72)
40320 >   210 x 192 (or 192 x 210)

*/

use std::cmp::*;

fn main() {
    assert_eq!(logical_rectangle(1), (1, 1));
    assert_eq!(logical_rectangle(4), (2, 2));
    assert_eq!(logical_rectangle(8), (2, 4));
    assert_eq!(logical_rectangle(15), (3, 5));
    assert_eq!(logical_rectangle(47), (1, 47));
    assert_eq!(logical_rectangle(5040), (70, 72));
    assert_eq!(logical_rectangle(40320), (192, 210));
}

fn logical_rectangle(n: usize) -> (usize, usize) {
    let (mut z, mut w, mut h) = (usize::MAX, 0, 0);
    for y in 0..n + 1 {
        for x in 0..n + 1 {
            if x * y == n && x + y < z {
                (z, w, h) = (x + y, x, y);
            }
        }
    }
    (min(w, h), max(w, h))
}
