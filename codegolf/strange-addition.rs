/*

Challenge
Calculate the strange sum of two natural numbers (also known as lunar addition):

Given A=...a2a1a0 and B=...b2b1b0 two natural numbers written in the decimal base, the strange sum is defined, based on the maximum operation, as: A+B=...max(a2,b2)max(a1,b1)max(a0,b0)

   ...         a2         a1         a0
 + ...         b2         b1         b0
 ----------------------------------------
   ...  max(a2,b2) max(a1,b1) max(a0,b0)
Input
Two natural numbers

All the following is allowed:

Zero-padded strings (same length)
Left-space-padded strings
Right-space-padded strings
Array of two padded strings
2D space-padded char array
Output
A natural numbers

Example
1999 + 2018 -> 2999
17210 + 701 -> 17711
32 + 17     -> 37
308 + 250   -> 358
308 + 25    -> 328

Rules
The input and output can be given in any convenient format (choose the most appropriate format for your language/solution).
No need to handle negative values or invalid input
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
If possible, please include a link to an online testing environment so other people can try out your code!
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

use std::cmp::max;

fn main() {
    assert_eq!(lunarsum(1999, 2018), 2999);
    assert_eq!(lunarsum(17210, 701), 17711);
    assert_eq!(lunarsum(32, 17), 37);
    assert_eq!(lunarsum(308, 250), 358);
    assert_eq!(lunarsum(308, 25), 328);
}

fn lunarsum(mut a: usize, mut b: usize) -> usize {
    let (mut s, mut z) = (0, 0);
    loop {
        s = (s * 10) + max(a % 10, b % 10);
        a /= 10;
        b /= 10;
        if a == 0 && b == 0 {
            break;
        }
        if s == 0 {
            z += 1;
        }
    }

    let mut r = 0;
    loop {
        r = (r * 10) + (s % 10);
        s /= 10;
        if s == 0 {
            break;
        }
    }

    for _ in 0..z {
        r *= 10;
    }

    r
}
