/*

Given integers N , P > 1 , find the largest integer M such that P ^ M ≤ N.

I/O:

Input is given as 2 integers N and P. The output will be the integer M.
Examples:

4, 5 -> 0
33, 5 -> 2
40, 20 -> 1
242, 3 -> 4 
243, 3 -> 5 
400, 2 -> 8
1000, 10 -> 3

Notes:

The input will always be valid, i.e. it will always be integers greater than 1.
Credits:

Credit for the name goes to @cairdcoinheringaahing. The last 3 examples are by @Nitrodon and credit for improving the description goes to @Giuseppe.

*/

fn main() {
    assert_eq!(ilog(4, 5), 0);
    assert_eq!(ilog(33, 5), 2);
    assert_eq!(ilog(40, 20), 1);
    assert_eq!(ilog(242, 3), 4);
    assert_eq!(ilog(243, 3), 5);
    assert_eq!(ilog(400, 2), 8);
    assert_eq!(ilog(1000, 10), 3);
}

fn ilog(n: usize, p: usize) -> usize {
    let mut m = 0;
    let mut v = p;
    while v <= n {
        v *= p;
        m += 1;
    }
    return m;
}
